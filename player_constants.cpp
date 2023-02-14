#include "player_constants.h"

std::vector<char*> player_constants::get_player_1_sprite_name() const {
	return PLAYER_1_SPRITE_NAMES;
}

std::vector<char*> player_constants::get_player_2_sprite_name() const {
	return PLAYER_2_SPRITE_NAMES;
}

std::vector<char*> player_constants::get_player_3_sprite_name() const {
	return PLAYER_3_SPRITE_NAMES;
}

std::vector<char*> player_constants::get_player_4_sprite_name() const {
	return PLAYER_4_SPRITE_NAMES;
}

std::vector<double> player_constants::get_start_x_co() const {
	return start_x_co;
}

std::vector<double> player_constants::get_start_y_co() const {
	return start_y_co;
}
