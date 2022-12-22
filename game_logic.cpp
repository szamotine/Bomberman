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
	//xmin represents offset from left side of the frame
	//dx is the length of the side of each square area used for the 
	double xmin = 21, dx = 42;
	int coordinate = (int)(index * dx + xmin);
	return coordinate;
}

void game_logic::collision_matrix_init() {
	//To be run once at initialization

	// holders for index values of object locations
	int i_index, j_index;

	// number of bricks
	int n;
	
	// number of red bricks
	n = terrain_pointer->red_brick_list.size();

	//sets values in collision matrix for each red brick
	for (int i = 0; i < n; i++)
	{
		rb_pointer =& terrain_pointer->red_brick_list[i];
		i_index = calculate_index(rb_pointer->get_x_coordinate());
		j_index = calculate_index(rb_pointer->get_y_coordinate());
		rb_pointer->set_i_index(i_index);
		rb_pointer->set_j_index(j_index);

		collision_pointer->e(i_index, j_index) = Collision_Type::Destructible;
	}

	// number of grey bricks
	n = terrain_pointer->grey_brick_list.size();

	//sets values in collision matrix for each grey brick
	for (int i = 0; i < n; i++)
	{
		gb_pointer = &terrain_pointer->grey_brick_list[i];
		i_index = calculate_index(gb_pointer->get_x_coordinate());
		j_index = calculate_index(gb_pointer->get_y_coordinate());

		collision_pointer->e(i_index, j_index) = Collision_Type::Indestructible;
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
	
		
	//check for collision with indestructible object
	if (collision_pointer->e(i_index, j_index) == Collision_Type::Indestructible) {
		//cout << "\nPlayer / Grey Brick collision detected at index: " << i_index << "," << j_index;
		return true;
	}
	//check for collision with destructible object
	if (collision_pointer->e(i_index, j_index) == Collision_Type::Destructible) {
		//cout << "\nPlayer / Red Brick collision detected at index: " << i_index << "," << j_index;
		return true;
	}
	//check for collision with bomb
	if (collision_pointer->e(i_index, j_index) == Collision_Type::Bomb) {
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
	check_bomb_flag_time(player_pointer);

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
		
		if (player_pointer->get_bomb_flag() && check_bomb_collison(player_pointer)) 
		{
			new_bomb(player_pointer);
		}
	}

	// player 2
	if (terrain_pointer->player_list.size() > 1) 
	{
		player_pointer = &terrain_pointer->player_list[1];

		check_bomb_flag_time(player_pointer);

		if (KEY('L')) 
		{
			player_pointer->set_orientation(RIGHT);
			if (!check_player_collision(player_pointer)) {
				player_pointer->move_player_x(m);
			}
		}
		if (KEY('J')) 
		{
			player_pointer->set_orientation(LEFT);
			if (!check_player_collision(player_pointer)) {
				player_pointer->move_player_x(-m);
			}
		}
		if (KEY('I')) 
		{
			player_pointer->set_orientation(UP);
			if (!check_player_collision(player_pointer)) {
				player_pointer->move_player_y(m);
			}
		}
		if (KEY('K')) 
		{
			player_pointer->set_orientation(DOWN);
			if (!check_player_collision(player_pointer)) {
				player_pointer->move_player_y(-m);
			}
		}

		if (KEY('M')) {
			
			if (player_pointer->get_bomb_flag() && check_bomb_collison(player_pointer)) {
				new_bomb(player_pointer);
			}
		}
	}
	
}

void game_logic::check_bomb_flag_time(player* p) {

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
				bomb_pointer->set_bomb_removal_flag();
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

	collision_pointer->e(i_index, j_index) = Collision_Type::Bomb;

}

bool game_logic::check_bomb_collison(player* p) {

	int i_index = calculate_index(p->get_x_coordinate());
	int j_index = calculate_index(p->get_y_coordinate());

	double orientation = p->get_orientation();

	if (orientation == RIGHT) {
		i_index ++;
	}
	else if (orientation == UP) {
		j_index ++;
	}
	else if (orientation == LEFT) {
		i_index--;
	}
	else if (orientation == DOWN) {
		j_index--;
	}

	int value = collision_pointer->e(i_index, j_index);

	if (collision_pointer->e(i_index, j_index) == 0) {
		return true;
	}
	else
	{
		//cout << "\nCannot place bomb at index: " << i_index << "," << j_index;
		return false;
	}


}

void game_logic::explode_bomb(bomb* b) {

	//i_index, j_index of bomb explosion area
	int x;
	int y;

	// bomb coordinate index
	int bomb_i_index =calculate_index(b->get_x_coordinate()); 
	int bomb_j_index = calculate_index(b->get_y_coordinate());

	//remove bomb index from collision matrix
	collision_pointer->e(bomb_i_index, bomb_j_index) = 0;

	for (vector<red_brick>::iterator i = terrain_pointer->red_brick_list.begin(); i != terrain_pointer->red_brick_list.end(); ++i) {

		x = i->get_i_index();
		y = i->get_j_index();

		// mark red brick for removal: 1 square left and right of the bomb
		if ((x == bomb_i_index + 1 || x == bomb_i_index - 1) && bomb_j_index == y) {
			i->set_flag_false();
		}

		// mark red brick for removal: 1 square above and below of the bomb
		if ((y == bomb_j_index + 1 || y == bomb_j_index - 1) && bomb_i_index == x) {
			i->set_flag_false();
		}

		// mark red brick for removal: 2 squares above the bomb if there are no indestructibles in the way
		if (x == bomb_i_index && (y == bomb_j_index + 2) && collision_pointer->e(bomb_i_index, bomb_j_index + 1) != Collision_Type::Indestructible) {
			i->set_flag_false();
		}

		// mark red brick for removal: 2 squares below the bomb if there are no indestructibles in the way
		if (x == bomb_i_index && (y == bomb_j_index - 2) && collision_pointer->e(bomb_i_index, bomb_j_index - 1) != Collision_Type::Indestructible) {
			i->set_flag_false();
		}

		// mark red brick for removal: 2 squares to the right of the bomb if there are no indestructibles in the way
		if (x == bomb_i_index + 2 && y == bomb_j_index && collision_pointer->e(bomb_i_index + 1, bomb_j_index) != Collision_Type::Indestructible) {
			i->set_flag_false();
		}

		// mark red brick for removal: 2 squares to the left of the bomb if there are no indestructibles in the way
		if (x == bomb_i_index - 2 && y == bomb_j_index && collision_pointer->e(bomb_i_index - 1, bomb_j_index) != Collision_Type::Indestructible) {
			i->set_flag_false();
		}
	}

	if (terrain_pointer->bomb_list.size() > 1)
	{
		chain_bomb_explosion(b);
	}
	
}

void game_logic::chain_bomb_explosion(bomb* b)
{
	//existing bomb location
	int bomb_i = b->get_bomb_i_index();
	int bomb_j = b->get_bomb_j_index();

	// placeholder to check collision matrix for bombs
	int i, j;

	//check for bomb to the right
	i = bomb_i + 1;
	j = bomb_j;

	check_bomb_bomb_interaction(i, j);

	//check for bomb to the left
	i = bomb_i - 1;
	j = bomb_j;

	check_bomb_bomb_interaction(i, j);

	//check for bomb above
	i = bomb_i;
	j = bomb_j +1;

	check_bomb_bomb_interaction(i, j);

	//check for bomb below
	i = bomb_i;
	j = bomb_j -1;

	check_bomb_bomb_interaction(i, j);

}

void game_logic::check_bomb_bomb_interaction(int i, int j)
{
	if (collision_pointer->e(i, j) == Collision_Type::Bomb)
	{
		flag_chain_bomb(i, j);
	}
	
}

void game_logic::flag_chain_bomb(int i_index, int j_index)
{
	if (terrain_pointer->bomb_list.size() > 0)
	{

		for (int i = 0; (unsigned)i < terrain_pointer->bomb_list.size(); i++)
		{
			bomb_pointer = &terrain_pointer->bomb_list[i];
			if (bomb_pointer->get_bomb_i_index() == i_index && bomb_pointer->get_bomb_j_index() == j_index)
			{
				bomb_pointer->set_bomb_removal_flag();
			}

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

void game_logic::remove_flagged_bombs()
{
	if (terrain_pointer->bomb_list.size() > 0)
	{
		for (int i = 0; (unsigned)i < terrain_pointer->bomb_list.size(); i++)
		{
			bomb_pointer = &terrain_pointer->bomb_list[i];

			if (bomb_pointer->get_bomb_removal_flag())
			{
				explode_bomb(bomb_pointer);
				terrain_pointer->remove_bomb(i);
			}
		}
	}
}
