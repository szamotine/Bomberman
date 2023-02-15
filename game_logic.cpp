#pragma once
#include <iostream>
#include "game_logic.h"
#include "2D_graphics.h"
#include <Windows.h>
#include "timer.h"
#include "calculator.h"
#include "player.h"

#pragma region Constructors

game_logic::~game_logic() = default;

game_logic::game_logic(std::shared_ptr<terrain> pointer_terrain, std::shared_ptr<iMatrix> collision_matrix) : terrain_pointer(pointer_terrain), collision_pointer(collision_matrix) {}

#pragma endregion

#pragma region Player Movement and Actions

void game_logic::player_input() {

	if (terrain_pointer->get_player_list().empty()) return;

	// Loop through each player, assign appropriate controls
	for (int i = 0; (unsigned)i < terrain_pointer->get_player_list().size(); i++)
	{
		player_pointer = terrain_pointer->get_player(i);
		if (player_pointer->get_player_number() == 0)
		{
			validate_bomb_flag_time(player_pointer);
			player_1_input(player_pointer);
		}
		if (player_pointer->get_player_number() == 1)
		{
			validate_bomb_flag_time(player_pointer);
			player_2_input(player_pointer);
		}
	}
}

void game_logic::player_1_input(player* p) {
	//input keys for movement of player 1
	if (KEY('D'))
	{
		p->set_orientation(RIGHT);
		if (validate_player_movement(p))
		{
			p->move_player_x(movement_size);
		}
	}
	if (KEY('A'))
	{
		p->set_orientation(LEFT);
		if (validate_player_movement(p))
		{
			p->move_player_x(-movement_size);
		}
	}
	if (KEY('W'))
	{
		p->set_orientation(UP);
		if (validate_player_movement(p))
		{
			p->move_player_y(movement_size);
		}
	}
	if (KEY('S'))
	{
		p->set_orientation(DOWN);
		if (validate_player_movement(p))
		{
			p->move_player_y(-movement_size);
		}
	}

	if (KEY('X') && p->get_bomb_flag() && validate_bomb_collison(p))
	{
		new_bomb(p);
	}

	if (KEY('Z'))
	{
		//print_player_coordinates(p);
	}

}

void game_logic::player_2_input(player* p) {
	//input keys for movement of player 2
	if (KEY('L'))
	{
		p->set_orientation(RIGHT);
		if (validate_player_movement(p))
		{
			p->move_player_x(movement_size);
		}
	}
	if (KEY('J'))
	{
		p->set_orientation(LEFT);
		if (validate_player_movement(p))
		{
			p->move_player_x(-movement_size);
		}
	}
	if (KEY('I'))
	{
		p->set_orientation(UP);
		if (validate_player_movement(p))
		{
			p->move_player_y(movement_size);
		}
	}
	if (KEY('K'))
	{
		p->set_orientation(DOWN);
		if (validate_player_movement(p))
		{
			p->move_player_y(-movement_size);
		}
	}

	if (KEY('M') && p->get_bomb_flag() && validate_bomb_collison(p))
	{
		new_bomb(p);
	}

	if (KEY('N'))
	{

		//print_player_coordinates(p);

	}

}

bool game_logic::validate_player_movement(const player* p) {
	// offset used based on player sprite size
	int x_shift = 15;

	int y_shift = 25;

	int y_shift2 = 13;

	// temporary placeholders for player coordinates
	double x;
	double y;
	double orientation;

	x = p->get_x_coordinate();
	y = p->get_y_coordinate();
	orientation = p->get_orientation();


	if (orientation == RIGHT)
	{
		x += x_shift;
		if (!check_player_offset(x, y)) return false;
		y += y_shift2;
		if (!check_player_offset(x, y)) return false;
		y -= y_shift2 * 2;
		if (!check_player_offset(x, y)) return false;
	}
	if (orientation == UP)
	{
		y += y_shift;
		if (!check_player_offset(x, y)) return false;
	}
	if (orientation == LEFT)
	{
		x -= x_shift;
		if (!check_player_offset(x, y)) return false;
		y += y_shift2;
		if (!check_player_offset(x, y)) return false;
		y -= y_shift2 * 2;
		if (!check_player_offset(x, y)) return false;
	}
	if (orientation == DOWN)
	{
		y -= y_shift;
		if (!check_player_offset(x, y)) return false;
	}

	return true;
}

bool game_logic::check_player_offset(double x, double y) {
	// index used to check collision matrix
	int i_index = calculator::calculate_index(x);
	int j_index = calculator::calculate_index(y);

	if (!validate_matrix_for_empty_space(i_index, j_index))
	{
		return false;
	}
	return true;
}


void game_logic::new_bomb(player* p) {

	//get player index
	int i_index = calculator::calculate_index(p->get_x_coordinate());
	int j_index = calculator::calculate_index(p->get_y_coordinate());

	// adjust bomb drop location for direction that player is facing

	double orientation = p->get_orientation();

	if (orientation == RIGHT)
	{
		i_index++;
	}
	if (orientation == UP)
	{
		j_index++;
	}
	if (orientation == LEFT)
	{
		i_index--;
	}
	if (orientation == DOWN)
	{
		j_index--;
	}


	//create bomb object
	terrain_pointer->construct_bomb(i_index, j_index);

	//configure player to ensure 1 bomb placement per time delay
	p->set_bomb_flag(false);
	p->set_bomb_time(high_resolution_time());

	// Update collision matrix
	set_matrix_to_bomb(i_index, j_index);

}

bool game_logic::validate_bomb_collison(const player* p) {
	int i_index = calculator::calculate_index(p->get_x_coordinate());
	int j_index = calculator::calculate_index(p->get_y_coordinate());

	double orientation = p->get_orientation();

	if (orientation == RIGHT)
	{
		i_index++;
	}
	else if (orientation == UP)
	{
		j_index++;
	}
	else if (orientation == LEFT)
	{
		i_index--;
	}
	else if (orientation == DOWN)
	{
		j_index--;
	}

	return validate_matrix_for_empty_space(i_index, j_index);

}

void game_logic::validate_bomb_flag_time(player* p) {

	current_time = high_resolution_time();

	if (current_time - p->get_bomb_time() > 0.5)
	{
		p->set_bomb_flag(true);
	}
}

void game_logic::print_player_coordinates(const player* p) const {
	double x = p->get_x_coordinate();
	double y = p->get_y_coordinate();
	int i_index = calculator::calculate_index(x);
	int j_index = calculator::calculate_index(y);
	std::cout << "\nPlayer coordinates: x= " << x << ", y= " << y;
	std::cout << "\nPlayer index: i= " << i_index << ", j= " << j_index;
}


#pragma endregion

#pragma region Bomb Explosion

void game_logic::explode_bomb(const bomb* b) {
	/*
	* High level function that coordinates all bomb explosion interactions:
	*	bomb - red brick
	*	bomb - bomb
	*	bomb - player
	*/

	// bomb coordinate index
	int bomb_i_index = b->get_i_index();
	int bomb_j_index = b->get_j_index();

	// bomb - red brick interactions

	validate_red_brick_bomb_interactions(bomb_i_index, bomb_j_index);

	// bomb chain interactions
	//if (terrain_pointer->get_bomb_list().size() > 1)
	//{
	//	validate_exploding_bomb_proximity(b);
	//}

	// bomb - player interactions
	validate_player_bomb_interaction();

	// remove bomb index from collision matrix
	set_matrix_to_empty_space(bomb_i_index, bomb_j_index);
}

void game_logic::validate_exploding_bomb_proximity(const bomb* b) {
	//existing bomb location
	int bomb_i = b->get_i_index();
	int bomb_j = b->get_j_index();

	// placeholder to check collision matrix for bombs
	int i;
	int j;

	//check for bomb to the right
	i = bomb_i + 1;
	j = bomb_j;

	if (validate_matrix_for_bomb(i, j)) flag_chain_bomb(i, j);

	//check for bomb to the left
	i = bomb_i - 1;
	j = bomb_j;

	if (validate_matrix_for_bomb(i, j)) flag_chain_bomb(i, j);

	//check for bomb above
	i = bomb_i;
	j = bomb_j + 1;
	if (validate_matrix_for_bomb(i, j)) flag_chain_bomb(i, j);

	//check for bomb below
	i = bomb_i;
	j = bomb_j - 1;
	if (validate_matrix_for_bomb(i, j)) flag_chain_bomb(i, j);

}

void game_logic::flag_chain_bomb(int i_index, int j_index) {

	if (!terrain_pointer->get_bomb_list().empty())
	{
		for (int i = 0; (unsigned)i < terrain_pointer->get_bomb_list().size(); i++)
		{
			bomb_pointer = terrain_pointer->get_bomb(i);

			if (bomb_pointer->get_i_index() == i_index && bomb_pointer->get_j_index() == j_index)
			{
				bomb_pointer->set_bomb_removal_flag();
			}
		}
	}
}

void game_logic::validate_player_bomb_interaction() {
	int i_index;
	int j_index;


	if (!terrain_pointer->get_player_list().empty())
	{
		// Iterate through player list
		for (int i = 0; (unsigned)i < terrain_pointer->get_player_list().size(); i++)
		{
			// Determine player coordinates

			player_pointer = terrain_pointer->get_player(i);
			i_index = calculator::calculate_index(player_pointer->get_x_coordinate());
			j_index = calculator::calculate_index(player_pointer->get_y_coordinate());

			// Check if player is in the bomb explosion area
			if (validate_player_bomb_proximity(i_index, j_index))
			{
				std::cout << "\nPlayer " << i << " at i: " << i_index << ", j: " << j_index << " hit by a bomb";
				player_pointer->set_removal_flag();
			}
		}
	}
}

bool game_logic::validate_player_bomb_proximity(int player_i, int player_j) {

	// Number of squares affected by Bomb explosion
	int offset = 1;
	int offset2 = 2;

	// Check left/right of player
	if (validate_matrix_for_bomb(player_i - offset, player_j) || validate_matrix_for_bomb(player_i + offset, player_j)) return true;

	// Check above/below player
	if (validate_matrix_for_bomb(player_i, player_j + offset) || validate_matrix_for_bomb(player_i, player_j - offset)) return true;

	// Check 2 left of player if not obstructed
	if (!validate_matrix_for_grey_brick(player_i - offset, player_j) && validate_matrix_for_bomb(player_i - offset2, player_j)) return true;
	// Check 2 right of player if not obstructed
	if (!validate_matrix_for_grey_brick(player_i + offset, player_j) && validate_matrix_for_bomb(player_i + offset2, player_j)) return true;
	// Check 2 above of player if not obstructed
	if (!validate_matrix_for_grey_brick(player_i, player_j + offset) && validate_matrix_for_bomb(player_i, player_j + offset2)) return true;
	// Check 2 below of player if not obstructed
	if (!validate_matrix_for_grey_brick(player_i, player_j - offset) && validate_matrix_for_bomb(player_i, player_j - offset2)) return true;

	return false;
}

void game_logic::validate_red_brick_bomb_interactions(int bomb_i_index, int bomb_j_index) {

	int matrix_value;
	int offset = 1;
	int offset2 = 2;

	// Removes red brick to the right of the bomb
	matrix_value = calculator::matrix_value(bomb_i_index + offset, bomb_j_index);
	terrain_pointer->destroy_red_brick(matrix_value);
	// Removes red brick to the left of the bomb
	matrix_value = calculator::matrix_value(bomb_i_index - offset, bomb_j_index);
	terrain_pointer->destroy_red_brick(matrix_value);
	// Removes red brick above the bomb
	matrix_value = calculator::matrix_value(bomb_i_index, bomb_j_index + offset);
	terrain_pointer->destroy_red_brick(matrix_value);
	// Removes red brick below the bomb
	matrix_value = calculator::matrix_value(bomb_i_index, bomb_j_index - offset);
	terrain_pointer->destroy_red_brick(matrix_value);

	//Removes red brick 2 to the right of the bomb if not obstructed
	if (!validate_matrix_for_grey_brick(bomb_i_index + offset, bomb_j_index))
	{
		matrix_value = calculator::matrix_value(bomb_i_index + offset2, bomb_j_index);
		terrain_pointer->destroy_red_brick(matrix_value);
	}
	//Removes red brick 2 to the left of the bomb if not obstructed
	if (!validate_matrix_for_grey_brick(bomb_i_index - offset, bomb_j_index))
	{
		matrix_value = calculator::matrix_value(bomb_i_index - offset2, bomb_j_index);
		terrain_pointer->destroy_red_brick(matrix_value);
	}
	// Removes red brick 2 above the bomb if not obstructed
	if (!validate_matrix_for_grey_brick(bomb_i_index, bomb_j_index + offset))
	{
		matrix_value = calculator::matrix_value(bomb_i_index, bomb_j_index + offset2);
		terrain_pointer->destroy_red_brick(matrix_value);
	}
	// Removes red brick 2 below the bomb if not obstructed
	if (!validate_matrix_for_grey_brick(bomb_i_index, bomb_j_index - offset))
	{
		matrix_value = calculator::matrix_value(bomb_i_index, bomb_j_index - offset2);
		terrain_pointer->destroy_red_brick(matrix_value);
	}

}


#pragma endregion

#pragma region Matrix Operations

void game_logic::collision_matrix_init() {
	//To be run once at initialization


	collision_matrix_init_grey_bricks();
	//collision_pointer->print0();
}

void game_logic::collision_matrix_init_grey_bricks() {
	// holders for index values of object locations
	int i_index;
	int j_index;


	// sets values in collision matrix for each grey brick
	for (int i = 0; (unsigned)i < terrain_pointer->get_grey_brick_list().size(); i++)
	{
		gb_pointer = terrain_pointer->get_grey_brick(i);

		// calculate matrix indices from coordinates
		i_index = gb_pointer->get_i_index();
		j_index = gb_pointer->get_j_index();

		// set collision matrix to contain grey brick location
		collision_pointer->e(i_index, j_index) = Collision_Type::Indestructible;
	}
}

bool game_logic::validate_matrix_for_bomb(int i, int j) {
	// Edge case: index out of bounds
	if (i < 0 || j < 0 || i > 16 || j > 16) return false;

	// Check Collision Matrix for bomb value
	if (collision_pointer->e(i, j) == Collision_Type::Bomb) return true;

	return false;
}

bool game_logic::validate_matrix_for_empty_space(int i, int j) {
	// Edge case: index out of bounds
	if (i < 0 || j < 0 || i > 16 || j > 16) return false;

	// Check Collision Matrix for Empty Space value
	return collision_pointer->e(i, j) == Collision_Type::None;
}

bool game_logic::validate_matrix_for_grey_brick(int i, int j) {
	// Edge case: index out of bounds
	if (i < 0 || j < 0 || i > 16 || j > 16) return false;

	// Check Collision Matrix for Empty Space value
	return collision_pointer->e(i, j) == Collision_Type::Indestructible;
}

void game_logic::set_matrix_to_empty_space(int i, int j) {
	collision_pointer->e(i, j) = Collision_Type::None;
}

void game_logic::set_matrix_to_bomb(int i, int j) {
	collision_pointer->e(i, j) = Collision_Type::Bomb;
}

#pragma endregion

#pragma region Flag operations

void game_logic::validate_bomb_timer() {
	if (!terrain_pointer->get_bomb_list().empty())
	{

		double duration;
		for (int i = 0; unsigned(i) < terrain_pointer->get_bomb_list().size(); i++)
		{
			bomb_pointer = terrain_pointer->get_bomb(i);
			current_time = high_resolution_time();
			duration = current_time - bomb_pointer->get_time();

			if (duration > 3)
			{
				bomb_pointer->set_bomb_removal_flag();
			}
		}
	}
}

void game_logic::remove_flagged_bombs() {
	if (!terrain_pointer->get_bomb_list().empty())
	{
		for (int i = 0; (unsigned)i < terrain_pointer->get_bomb_list().size(); i++)
		{
			bomb_pointer = terrain_pointer->get_bomb(i);
			if (bomb_pointer->get_bomb_removal_flag())
			{
				explode_bomb(bomb_pointer);
				terrain_pointer->erase_bomb(i);
			}
		}
	}
}

void game_logic::remove_flagged_players() {
	if (!terrain_pointer->get_player_list().empty())
	{
		for (int i = 0; (unsigned)i < terrain_pointer->get_player_list().size(); i++)
		{
			player_pointer = terrain_pointer->get_player(i);
			if (player_pointer->get_player_removal_flag())
			{
				terrain_pointer->erase_player(i);
			}
		}
	}
}
#pragma endregion