#pragma once
#include <iostream>
#include "brick_logic.h"
#include "iMatrix.h"

brick_logic::~brick_logic() {

}
brick_logic::brick_logic(world w) {
	world_pointer = &w;
	terrain_pointer = world_pointer->pointer_terrain;
	collision_pointer = world_pointer->collision_matrix;

}

int brick_logic::calculate_index(double coordinate) {
	double xmin = 21, dx = 42;

	double d_index = (coordinate - xmin) / dx;
	int index = (int)(d_index + 0.5);
	return index;
}

void brick_logic::red_brick_collision_matrix_init() {

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

int brick_logic::check_player_collision() {
	
	int i_index;
	int j_index;

	// offset used based on player sprite size
	int x_shift = 5;
	int y_shift_down = 22;
	int y_shift_up = 20;

	
	for (int i = 0; i < terrain_pointer->player_list.size(); i++) {
		
		player_pointer = &terrain_pointer->player_list[i];
		double x = player_pointer->get_x_coordinate();
		double y = player_pointer->get_y_coordinate();
		double orientation = player_pointer->get_orientation();

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

	}

	return false;
}

