#include "player.h"
#include "2D_graphics.h"

player::player(int player_number)
{
	x_coordinate = start_x_co[player_number];
	y_coordinate = start_y_co[player_number];
	orientation = 360.0;
	sprite_id = new int[4];
	initialize_sprites(player_number);
	
	
}

player::~player()
{
}

double player::get_x_coordinate()
{
	return x_coordinate;
}

double player::get_y_coordinate()
{
	return y_coordinate;
}

double player::get_orientation()
{
	return orientation;
}

double player::get_angle()
{
	return player_angle;
}

double player::get_scale()
{
	return player_sprite_scale;
}

int player::get_sprite_id() {
	
	//sprite ids array -> {top, bottom, left, right}
	if (orientation == 0.0) {
		return sprite_id[0];
	}
	else if (orientation == 90.0) {
		return sprite_id[1];
	}
	else if (orientation == 270.0) {
		return sprite_id[2];
	}
	else {
		return sprite_id[3];
	}
	
}

void player::set_x_coordinate(double value)
{
	x_coordinate = value;
}

void player::set_y_coordinate(double value)
{
	y_coordinate = value;
}

void player::set_orientation(double value)
{
	orientation = value;
}

void player::set_scale(double value)
{
	player_sprite_scale = value;
}

void player::initialize_sprites(int player_number) {

	char** player;

	if (player_number == 0) {
		player = PLAYER_1_SPRITE_NAMES;
		
	}else if (player_number == 1) {
		player = PLAYER_2_SPRITE_NAMES;
	}else if (player_number == 2) {
		player = PLAYER_3_SPRITE_NAMES;
	}else {
		player = PLAYER_4_SPRITE_NAMES;
	}

	for (int i = 0; i < 4; i++) {
		create_sprite(player[i], sprite_id[i]);
	}

}

