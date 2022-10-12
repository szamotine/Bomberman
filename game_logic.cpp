#pragma once
#include <iostream>
#include "game_logic.h"
#include "2D_graphics.h"
#include <Windows.h>



game_logic::~game_logic() {

}
game_logic::game_logic(terrain* pointer_terrain, iMatrix* collision_matrix) {
	//world_pointer = &w;
	terrain_pointer = pointer_terrain;
	collision_pointer = collision_matrix;

}

int game_logic::calculate_index(double coordinate) {
	double xmin = 21, dx = 42;

	double d_index = (coordinate - xmin) / dx;
	int index = (int)(d_index + 0.5);
	return index;
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
		//cout << "\nRB(world) i_index= " << i_index;
		//cout << "\nRB(world) j_index= " << j_index;	
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
		//collision_pointer->print();
}

bool game_logic::check_player_collision(player* p) {
	
	int i_index;
	int j_index;

	// offset used based on player sprite size
	int x_shift = 15;
	int y_shift_down = 22;
	int y_shift_up = 20;
		
		
		double x = p->get_x_coordinate();
		double y = p->get_y_coordinate();
		double orientation = p->get_orientation();

		if (orientation == 0.0) {
			x += x_shift;
		}
		if (orientation == 90.0) {
			y += y_shift_up;
		}
		if (orientation == 180.0) {
			x -= x_shift;
		}
		if (orientation == 270.0) {
			y -= y_shift_down;
		}


		i_index = calculate_index(x);
		j_index = calculate_index(y);
		//cout << "\nchecking index: " << i_index << "," << j_index;
		//cout << "\ncollision matrix value at index: " << collision_pointer->e(i_index, j_index);

		//checking for grey brick collision
		if (collision_pointer->e(i_index, j_index) == collision_indestructible) {
			cout << "\nPlayer / Grey Brick collision detected at index: " << i_index << "," << j_index;
			return true;
		}
		// checking for red brick collision
		if (collision_pointer->e(i_index, j_index) == collision_destructible) {
			cout << "\nPlayer / Red Brick collision detected at index: " << i_index << "," << j_index;
			return true;
		}

	return false;
}

void game_logic::player_input()
{
	int m = 3;

	// pointer to player 1 of terrain player_list
	player_pointer = &terrain_pointer->player_list[0];
	//check_bomb_time(pointer_player);

	if (KEY('D')) {
		player_pointer->set_orientation(0.0);
		if (!check_player_collision(player_pointer)) {
			player_pointer->move_player_x(m);
		}
	}
	if (KEY('A')) {
		player_pointer->set_orientation(180.0);
		if (!check_player_collision(player_pointer)) {
			player_pointer->move_player_x(-m);
		}
		
		
	}
	if (KEY('W')) {
		player_pointer->set_orientation(90.0);
		if (!check_player_collision(player_pointer)) {
			player_pointer->move_player_y(m);
		}
	}
	if (KEY('S')) {
		player_pointer->set_orientation(270.0);
		if (!check_player_collision(player_pointer)) {
			player_pointer->move_player_y(-m);
		}
	}

	if (KEY('X')) {

		if (player_pointer->get_bomb_flag()) {
			//pointer_player->set_bomb_time(high_resolution_time());
			//new_bomb_coordinates(player_pointer);
			//cout << "\nBomb dropped for player 1";
		}

	}

	// player 2
	if (terrain_pointer->player_list.size() > 1) {
		player_pointer = &terrain_pointer->player_list[1];
	}
	//check_bomb_time(player_pointer);

	if (KEY('L')) {
		player_pointer->move_player_x(m);
		player_pointer->set_orientation(0.0);
	}
	if (KEY('J')) {
		player_pointer->move_player_x(-m);
		player_pointer->set_orientation(180.0);
	}
	if (KEY('I')) {
		player_pointer->move_player_y(m);
		player_pointer->set_orientation(90.0);
	}
	if (KEY('K')) {
		player_pointer->move_player_y(-m);
		player_pointer->set_orientation(270.0);
	}

	if (KEY('M')) {

		if (player_pointer->get_bomb_flag()) {
			//player_pointer->set_bomb_time(high_resolution_time());
			//new_bomb_coordinates(player_pointer);
			//cout << "\nBomb dropped for player 2";
		}
	}

}

