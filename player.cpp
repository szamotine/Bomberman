#include "player.h"
#include "2D_graphics.h"
#include <vector>
#include <iostream>

player::player(int player_number) : player_number(player_number) {

	x_coordinate = player_constant_pointer->get_start_x_co()[player_number];
	y_coordinate = player_constant_pointer->get_start_y_co()[player_number];

	initialize_sprites();
}

player::~player() = default;

#pragma region Getters

double player::get_x_coordinate() const {
	return x_coordinate;
}

double player::get_y_coordinate() const {
	return y_coordinate;
}

double player::get_angle() const {
	return player_angle;
}

double player::get_scale() const {
	return player_sprite_scale;
}

int player::get_sprite_id() const {

	//sprite ids array -> {right, top, left, bottom}
	if (orientation == RIGHT)
	{
		return sprite_id[0];
	}
	else if (orientation == UP)
	{
		return sprite_id[1];
	}
	else if (orientation == LEFT)
	{
		return sprite_id[2];
	}
	else
	{
		return sprite_id[3];
	}

}

double player::get_bomb_time() const {
	return bomb_flag_time;
}

bool player::get_bomb_flag() const {
	return bomb_flag;
}

bool player::get_player_removal_flag() const {
	return removal_flag;
}

int player::get_player_number() const {
	return player_number;
}

player::player_orientation player::get_player_orientation() const {
	return orientation;
}
#pragma endregion
#pragma region Setters

void player::set_scale(double value) {
	player_sprite_scale = value;
}

void player::set_bomb_flag_time(double value) {
	bomb_flag_time = value;
}

void player::set_bomb_flag(bool flag) {
	bomb_flag = flag;
}

void player::set_removal_flag() {
	removal_flag = true;
}
void player::set_player_orientation(int p_o) {
	orientation = (player_orientation)p_o;
}
#pragma endregion

void player::initialize_sprites() {
	std::vector< char*> player;

	if (player_number == 0)
	{
		player = player_constant_pointer->get_player_1_sprite_name();

	}
	else if (player_number == 1)
	{
		player = player_constant_pointer->get_player_2_sprite_name();
	}
	else if (player_number == 2)
	{
		player = player_constant_pointer->get_player_3_sprite_name();
	}
	else
	{
		player = player_constant_pointer->get_player_4_sprite_name();
	}

	for (int i = 0; i < 4; i++)
	{
		create_sprite((player[i]), sprite_id[i]);
	}



}

void player::move_player_x(double value) {
	x_coordinate += value;
}
void player::move_player_y(double value) {
	y_coordinate += value;
}