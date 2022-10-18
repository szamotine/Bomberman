#pragma once
#include <iostream>
#include "game_logic.h"
#include "2D_graphics.h"
#include <Windows.h>
#include "timer.h"

game_logic::~game_logic() {

}
game_logic::game_logic(terrain* pointer_terrain, iMatrix* collision_matrix) {
	
	terrain_pointer = pointer_terrain;
	collision_pointer = collision_matrix;

}

int game_logic::calculate_index(double coordinate) {
	double xmin = 21, dx = 42;

	double d_index = (coordinate - xmin) / dx;
	int index = (int)(d_index + 0.5);
	return index;
}

double game_logic::calculate_coordinate(int index) {
	double xmin = 21, dx = 42;
	int coordinate = (int)(index * dx + xmin);
	return coordinate;
}

void game_logic::collision_matrix_init() {

	//To be run once at initialization
	int i_index, j_index;

	// number of red bricks
	int n = terrain_pointer->red_brick_list.size();

	//sets values in collision matrix for each red brick
	for (int i = 0; i < n; i++)
	{
		rb_pointer =& terrain_pointer->red_brick_list[i];
		i_index = calculate_index(rb_pointer->get_x_coordinate());
		j_index = calculate_index(rb_pointer->get_y_coordinate());
		rb_pointer->set_i_index(i_index);
		rb_pointer->set_j_index(j_index);

		collision_pointer->e(i_index, j_index) = collision_destructible;
	}

	n = terrain_pointer->grey_brick_list.size();

	//sets values in collision matrix for each red brick
	for (int i = 0; i < n; i++)
	{
		gb_pointer = &terrain_pointer->grey_brick_list[i];
		i_index = calculate_index(gb_pointer->get_x_coordinate());
		j_index = calculate_index(gb_pointer->get_y_coordinate());
		//cout << "\nRB(world) i_index= " << i_index;
		//cout << "\nRB(world) j_index= " << j_index;	
		collision_pointer->e(i_index, j_index) = collision_indestructible;
	}
		//collision_pointer->print0();
}

bool game_logic::check_player_collision(player* p) {
	
	// index used to check collision matrix
	int i_index;
	int j_index;

	// offset used based on player sprite size
	int x_shift = 15;
	int y_shift_down = 22;
	int y_shift_up = 20;
	
	// temporary placeholders for player coordinates
	double x, y, orientation;

		
	x = p->get_x_coordinate();
	y = p->get_y_coordinate();
	orientation = p->get_orientation();

	if (orientation == RIGHT) {
		x += x_shift;
	}
	if (orientation == UP) {
		y += y_shift_up;
	}
	if (orientation == LEFT) {
		x -= x_shift;
	}
	if (orientation == DOWN) {
		y -= y_shift_down;
	}

	i_index = calculate_index(x);
	j_index = calculate_index(y);
	
		
	//checking for grey brick collision
	if (collision_pointer->e(i_index, j_index) == collision_indestructible) {
		//cout << "\nPlayer / Grey Brick collision detected at index: " << i_index << "," << j_index;
		return true;
	}
	// checking for red brick collision
	if (collision_pointer->e(i_index, j_index) == collision_destructible) {
		//cout << "\nPlayer / Red Brick collision detected at index: " << i_index << "," << j_index;
		return true;
	}
	if (collision_pointer->e(i_index, j_index) == collision_bomb) {
		//cout << "\nPlayer / Bomb collision detected at index: " << i_index << "," << j_index;
		return true;
	}

	return false;
}

void game_logic::player_input()
{
	// movement step size for fluid looking motion
	int m = 3;

	// pointer to player 1 of terrain player_list
	player_pointer = &terrain_pointer->player_list[0];

	//checks if player bomb flag can be reset to allow bomb placement
	check_bomb_flag(player_pointer);

	//input keys for movement
	if (KEY('D')) {
		player_pointer->set_orientation(RIGHT);
		if (!check_player_collision(player_pointer)) {
			player_pointer->move_player_x(m);
		}
	}
	if (KEY('A')) {
		player_pointer->set_orientation(LEFT);
		if (!check_player_collision(player_pointer)) {
			player_pointer->move_player_x(-m);
		}		
	}
	if (KEY('W')) {
		player_pointer->set_orientation(UP);
		if (!check_player_collision(player_pointer)) {
			player_pointer->move_player_y(m);
		}
	}
	if (KEY('S')) {
		player_pointer->set_orientation(DOWN);
		if (!check_player_collision(player_pointer)) {
			player_pointer->move_player_y(-m);
		}
	}

	if (KEY('X')) {
		cout << "\nBomb called for player 1";
		if (player_pointer->get_bomb_flag() && check_bomb_collison(player_pointer)) {
			
			new_bomb(player_pointer);
			
			cout << "\nBomb dropped for player 1";
		}
	}

	// player 2
	if (terrain_pointer->player_list.size() > 1) {
		player_pointer = &terrain_pointer->player_list[1];

		check_bomb_flag(player_pointer);

		if (KEY('L')) {
			player_pointer->set_orientation(RIGHT);
			if (!check_player_collision(player_pointer)) {
				player_pointer->move_player_x(m);
			}
		}
		if (KEY('J')) {
			player_pointer->set_orientation(LEFT);
			if (!check_player_collision(player_pointer)) {
				player_pointer->move_player_x(-m);
			}
		}
		if (KEY('I')) {
			player_pointer->set_orientation(UP);
			if (!check_player_collision(player_pointer)) {
				player_pointer->move_player_y(m);
			}
		}
		if (KEY('K')) {
			player_pointer->set_orientation(DOWN);
			if (!check_player_collision(player_pointer)) {
				player_pointer->move_player_y(-m);
			}
		}

		if (KEY('M')) {
			cout << "\nBomb called for player 2";
			if (player_pointer->get_bomb_flag() && check_bomb_collison(player_pointer)) {

				new_bomb(player_pointer);
				cout << "\nBomb dropped for player 2";
				//player_pointer->set_bomb_time(high_resolution_time());
			}
		}
	}
	
}

void game_logic::check_bomb_flag(player* p) {

	current_time = high_resolution_time();

	if (current_time - p->get_bomb_time() > 0.5) {
		p->set_bomb_flag(true);
	}
}

void game_logic::check_bomb_timer()
{
	if (terrain_pointer->bomb_list.size() > 0) {
		double duration;
		for (int i = 0; unsigned(i) < terrain_pointer->bomb_list.size(); i++) {
			bomb_pointer = &terrain_pointer->bomb_list[i];
			current_time = high_resolution_time();
			duration = current_time - bomb_pointer->get_time();

			if (duration > 3) {
				cout << "\nBomb explode!";
				explode_bomb(bomb_pointer);
				terrain_pointer->remove_bomb(i);
			}
		}
	}
}

void game_logic::new_bomb(player* p) {

	//get player index
	int i_index = calculate_index(p->get_x_coordinate());
	int j_index = calculate_index(p->get_y_coordinate());

	// adjust bomb drop location for direction that player is facing

	double orientation = p->get_orientation();

	if (orientation == RIGHT) {
		i_index++;
	}
	if (orientation == UP) {
		j_index++;
	}
	if (orientation == LEFT) {
		i_index--;
	}
	if (orientation == DOWN) {
		j_index--;
	}

	//calculate coordinates of bomb location
	double x = calculate_coordinate(i_index);
	double y = calculate_coordinate(j_index);

	//create bomb object
	terrain_pointer->create_bomb(x, y);
	
	//configure player to ensure 1 bomb placement per time delay
	p->set_bomb_flag(false);
	p->set_bomb_time(high_resolution_time());

	collision_pointer->e(i_index, j_index) = collision_bomb;

}

bool game_logic::check_bomb_collison(player* p) {

	int i_index = calculate_index(p->get_x_coordinate());
	int j_index = calculate_index(p->get_y_coordinate());

	/*
	// offset used based on bomb sprite size
	int x_shift = 50;
	int y_shift_down = 52;
	int y_shift_up = 40;


	double x = p->get_x_coordinate();
	double y = p->get_y_coordinate();
	*/
	double orientation = p->get_orientation();

	if (orientation == RIGHT) {
		i_index ++;
	}
	if (orientation == UP) {
		j_index ++;
	}
	if (orientation == LEFT) {
		i_index--;
	}
	if (orientation == RIGHT) {
		j_index--;
	}


	if (collision_pointer->e(i_index, j_index) == 0) {
		return true;
	}

	cout << "\nCannot place bomb at index: " << i_index << "," << j_index;

	return false;
}

void game_logic::explode_bomb(bomb* b) {

	int x;
	int y;

	int bomb_i_index =calculate_index(b->get_x_coordinate()); // b->get_bomb_i_index();

	int bomb_j_index = calculate_index(b->get_y_coordinate()); //b->get_bomb_j_index();

	cout << "\nExploding bomb at index: " << bomb_i_index << "," << bomb_j_index;
	collision_pointer->e(bomb_i_index, bomb_j_index) = 0;

	
	for (vector<red_brick>::iterator i = terrain_pointer->red_brick_list.begin(); i != terrain_pointer->red_brick_list.end(); ++i) {

		x = i->get_i_index();
		y = i->get_j_index();


		if ((x == bomb_i_index + 1 || x == bomb_i_index - 1) && bomb_j_index == y) {
			i->set_flag_false();
		}

		// remove bomb 1 to above and below
		if ((y == bomb_j_index + 1 || y == bomb_j_index - 1) && bomb_i_index == x) {
			i->set_flag_false();
		}


		if (x == bomb_i_index && (y == bomb_j_index + 2) && collision_pointer->e(bomb_i_index, bomb_j_index + 1) != collision_indestructible) {
			i->set_flag_false();
		}

		if (x == bomb_i_index && (y == bomb_j_index - 2) && collision_pointer->e(bomb_i_index, bomb_j_index - 1) != collision_indestructible) {
			i->set_flag_false();
		}


		if (x == bomb_i_index + 2 && y == bomb_j_index && collision_pointer->e(bomb_i_index + 1, bomb_j_index) != collision_indestructible) {
			i->set_flag_false();
		}

		if (x == bomb_i_index - 2 && y == bomb_j_index && collision_pointer->e(bomb_i_index - 1, bomb_j_index) != collision_indestructible) {
			i->set_flag_false();
		}
	}
}

void game_logic::remove_flagged_bricks() {

	for (int i = 0; unsigned(i) < terrain_pointer->red_brick_list.size(); i++) 
	{
		rb_pointer = &terrain_pointer->red_brick_list[i];
		
		if (rb_pointer->get_flag()) 
		{
			int i_index = rb_pointer->get_i_index();
			int j_index = rb_pointer->get_j_index();
			collision_pointer->e(i_index, j_index) = 0;
			terrain_pointer->red_brick_list.erase(terrain_pointer->red_brick_list.begin() + i);
		}	
	}
}
