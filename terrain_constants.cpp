#include "terrain_constants.h"

terrain_constants::terrain_constants() = default;

char* terrain_constants::get_background_filename() const {
	return background_filename;
}

char* terrain_constants::get_grey_bricks_filename() const {
	return grey_bricks_filename;
}

char* terrain_constants::get_red_bricks_filename() const {
	return red_bricks_filename;
}

char* terrain_constants::get_bomb_filename() const {
	return bomb_filename;
}

char* terrain_constants::get_bomb_explosion_filename() const {
	return bomb_explosion;
}

double terrain_constants::get_angle() const {
	return angle;
}

double terrain_constants::get_scale() const {
	return scale;
}

double terrain_constants::get_background_coordinates() const {
	return background_coordinates;
}

double terrain_constants::get_background_scale() const {
	return background_scale;
}

double terrain_constants::get_bomb_explosion_scale() const {
	return bomb_explosion_scale;
}
