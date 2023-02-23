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
		p->set_player_orientation(0);
		if (validate_player_movement(p))
		{
			p->move_player_x(movement_size);
		}
	}
	if (KEY('A'))
	{
		p->set_player_orientation(2);
		if (validate_player_movement(p))
		{
			p->move_player_x(-movement_size);
		}
	}
	if (KEY('W'))
	{
		p->set_player_orientation(1);
		if (validate_player_movement(p))
		{
			p->move_player_y(movement_size);
		}
	}
	if (KEY('S'))
	{
		p->set_player_orientation(3);
		if (validate_player_movement(p))
		{
			p->move_player_y(-movement_size);
		}
	}

	if (KEY('X') && p->get_bomb_flag() && validate_bomb_collison(p))
	{
		new_bomb(p);
	}

}

void game_logic::player_2_input(player* p) {
	//input keys for movement of player 2
	if (KEY('L'))
	{
		p->set_player_orientation(0);
		if (validate_player_movement(p))
		{
			p->move_player_x(movement_size);
		}
	}
	if (KEY('J'))
	{
		p->set_player_orientation(2);
		if (validate_player_movement(p))
		{
			p->move_player_x(-movement_size);
		}
	}
	if (KEY('I'))
	{
		p->set_player_orientation(1);
		if (validate_player_movement(p))
		{
			p->move_player_y(movement_size);
		}
	}
	if (KEY('K'))
	{
		p->set_player_orientation(3);
		if (validate_player_movement(p))
		{
			p->move_player_y(-movement_size);
		}
	}

	if (KEY('M') && p->get_bomb_flag() && validate_bomb_collison(p))
	{
		new_bomb(p);
	}

}


bool game_logic::validate_player_movement(const player* p) {
	// offset used based on player sprite size
	int x_shift = 15;
	int y_shift = 25;
	int x_shift_2 = 10;
	int y_shift_2 = 13;

	// temporary placeholders for player coordinates
	double x = p->get_x_coordinate();
	double y = p->get_y_coordinate();

	int p_o = p->get_player_orientation();

	bool result = false;

	switch (p_o)
	{
		case 0:
			x += x_shift;
			y += y_shift_2;
			result = check_player_offset(x, y);
			if (result)
			{
				y -= y_shift_2 * 2;
				result = check_player_offset(x, y);
			}
			if (result)
			{
				x -= x_shift;
				result = check_player_offset(x, y);
			}
			break;
		case 1:
			y += y_shift;
			x += x_shift_2;
			result = check_player_offset(x, y);
			if (result)
			{
				x -= x_shift_2 * 2;
				result = check_player_offset(x, y);
			}
			if (result)
			{
				y -= y_shift;
				result = check_player_offset(x, y);
			}
			break;
		case 2:
			x -= x_shift;
			y += y_shift_2;
			result = check_player_offset(x, y);
			if (result)
			{
				y -= y_shift_2 * 2;
				result = check_player_offset(x, y);
			}
			if (result)
			{
				x += x_shift;
				result = check_player_offset(x, y);
			}
			break;
		case 3:
			y -= y_shift;
			x += x_shift_2;
			result = check_player_offset(x, y);
			if (result)
			{
				x -= x_shift_2 * 2;
				result = check_player_offset(x, y);
			}
			if (result)
			{
				y += y_shift;
				result = check_player_offset(x, y);
			}
			break;
		default:
			break;
	}

	return result;
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
	int matrix_value;
	// adjust bomb drop location for direction that player is facing

	int orientation = p->get_player_orientation();

	if (orientation == 0)
	{
		i_index++;
	}
	if (orientation == 1)
	{
		j_index++;
	}
	if (orientation == 2)
	{
		i_index--;
	}
	if (orientation == 3)
	{
		j_index--;
	}


	//create bomb object
	matrix_value = calculator::matrix_value(i_index, j_index);
	terrain_pointer->construct_bomb(matrix_value, i_index, j_index);

	//configure player to ensure 1 bomb placement per time delay
	p->set_bomb_flag(false);
	p->set_bomb_flag_time(high_resolution_time());

	// Update collision matrix
	set_matrix_to_bomb(i_index, j_index);

}

bool game_logic::validate_bomb_collison(const player* p) {
	int i_index = calculator::calculate_index(p->get_x_coordinate());
	int j_index = calculator::calculate_index(p->get_y_coordinate());

	int orientation = p->get_player_orientation();

	if (orientation == 0)
	{
		i_index++;
	}
	else if (orientation == 1)
	{
		j_index++;
	}
	else if (orientation == 2)
	{
		i_index--;
	}
	else if (orientation == 3)
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
	if (terrain_pointer->get_bomb_map().size() > 1)
	{
		validate_bomb_map_for_chain_explosions(b);
	}

	// bomb - player interactions
	validate_player_bomb_interaction(b);

	// remove bomb index from collision matrix
	set_matrix_to_empty_space(bomb_i_index, bomb_j_index);
}

void game_logic::validate_bomb_map_for_chain_explosions(const bomb* b) {

	auto temp = terrain_pointer->get_bomb_map();
	auto it = temp.begin();
	auto it2 = temp.end();
	while (it != it2)
	{
		if (validate_chain_bomb_sequence(b, &it->second))
		{
			flag_chain_bomb(it->second.get_i_index(), it->second.get_j_index());
		}
		it++;
	}
}

bool game_logic::validate_chain_bomb_sequence(const bomb* b, const bomb* b2) const {

	if (b2->get_bomb_removal_flag()) return false;

	int b_i_index = b->get_i_index();
	int b_j_index = b->get_j_index();

	int b2_i_index = b2->get_i_index();
	int b2_j_index = b2->get_j_index();

	int abs_difference_i = abs(b_i_index - b2_i_index);
	int abs_difference_j = abs(b_j_index - b2_j_index);

	int range = 3;

	if (b_i_index == b2_i_index && abs_difference_j < range) return true;

	if (b_j_index == b2_j_index && abs_difference_i < range) return true;

	return false;
}

void game_logic::flag_chain_bomb(int i_index, int j_index) {
	int matrix_value = calculator::matrix_value(i_index, j_index);
	terrain_pointer->get_bomb_pointer(matrix_value)->set_bomb_exploding_flag();
	terrain_pointer->get_bomb_pointer(matrix_value)->set_bomb_removal_flag();
}

void game_logic::validate_player_bomb_interaction(const bomb* b) {

	if (!terrain_pointer->get_player_list().empty())
	{
		// Iterate through player list
		for (int i = 0; (unsigned)i < terrain_pointer->get_player_list().size(); i++)
		{
			player_pointer = terrain_pointer->get_player(i);

			if (validate_player_bomb_proximity(player_pointer, b))
				player_pointer->set_removal_flag();
		}
	}
}

bool game_logic::validate_player_bomb_proximity(const player* p, const bomb* b) {

	int player_i = calculator::calculate_index(p->get_x_coordinate());
	int player_j = calculator::calculate_index(p->get_y_coordinate());

	int bomb_i = b->get_i_index();
	int bomb_j = b->get_j_index();

	// Number of squares affected by Bomb explosion
	int offset = 1;
	int offset2 = 2;

	// check if bomb is on same j_index as player
	if (player_j == bomb_j)
	{
		// check left/right of bomb for player
		if (player_i == bomb_i - offset || player_i == bomb_i + offset) return true;

		// check 2 left of bomb if grey brick is not obstructing
		if (!validate_matrix_for_grey_brick(bomb_i - offset, bomb_j) && bomb_i - offset2 == player_i) return true;

		// check 2 right of bomb if grey brick is not obstructing
		if (!validate_matrix_for_grey_brick(bomb_i + offset, bomb_j) && bomb_i + offset2 == player_i) return true;
	}

	// Check if bomb is one same i_index as player
	if (player_i == bomb_i)
	{
		// check above/below of bomb for player
		if (player_j == bomb_j - offset || player_j == bomb_j + offset) return true;

		// check 2 above bomb if grey brick is not obstructing
		if (!validate_matrix_for_grey_brick(bomb_i, bomb_j + offset) && bomb_j + offset2 == player_j) return true;

		// check 2 below bomb if grey brick is not obstructing
		if (!validate_matrix_for_grey_brick(bomb_i, bomb_j - offset) && bomb_j - offset2 == player_j) return true;
	}

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

	if (!terrain_pointer->get_bomb_map().empty())
	{
		// Length of time before a bomb explodes (seconds)
		double bomb_duration = 3;

		// Length of time to show explosion
		double explosion_duration = 0.3;

		double duration;

		auto temp = terrain_pointer->get_bomb_map();
		auto it = temp.begin();
		auto it2 = temp.end();

		while (it != it2)
		{
			current_time = high_resolution_time();
			duration = current_time - it->second.get_time();

			if (duration > bomb_duration - explosion_duration)
			{
				int matrix_value = calculator::matrix_value(it->second.get_i_index(), it->second.get_j_index());
				bomb_pointer = terrain_pointer->get_bomb_pointer(matrix_value);
				bomb_pointer->set_bomb_exploding_flag();
				duration > bomb_duration ? bomb_pointer->set_bomb_removal_flag() : NULL;
			}
			it++;
		}
	}
}

void game_logic::remove_flagged_bombs() {

	if (!terrain_pointer->get_bomb_map().empty())
	{
		auto temp = terrain_pointer->get_bomb_map();
		auto it = temp.begin();
		auto it2 = temp.end();

		while (it != it2)
		{

			if (it->second.get_bomb_removal_flag())
			{
				int matrix_value = calculator::matrix_value(it->second.get_i_index(), it->second.get_j_index());
				bomb_pointer = terrain_pointer->get_bomb_pointer(matrix_value);
				explode_bomb(bomb_pointer);
				terrain_pointer->destroy_bomb(matrix_value);
			}
			it++;
		}
	}
}

void game_logic::remove_flagged_players() {
	if (terrain_pointer->get_player_list().size() > 1)
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