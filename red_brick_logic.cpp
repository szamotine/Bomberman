#pragma once
#include <iostream>
#include "red_brick_logic.h"
#include "iMatrix.h"

red_brick_logic::~red_brick_logic() {

}
red_brick_logic::red_brick_logic(world w) {
	world_pointer = &w;
	terrain_pointer = world_pointer->pointer_terrain;
	collision_pointer = world_pointer->collision_matrix;

}

int red_brick_logic::calculate_index(double coordinate) {
	double xmin = 21, dx = 42;

	double d_index = (coordinate - xmin) / dx;
	int index = (int)(d_index + 0.5);
	return index;
}

void red_brick_logic::red_brick_collision_matrix_init() {

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

bool red_brick_logic::check_player_collision() {
	//TODO: add offset in coordiantes for player sprite size + orientation
	int i_index;
	int j_index;

	for (int i = 0; i < terrain_pointer->player_list.size(); i++) {
		player_pointer = &terrain_pointer->player_list[i];
		i_index = calculate_index(player_pointer->get_x_coordinate());
		j_index = calculate_index(player_pointer->get_y_coordinate());
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
}

