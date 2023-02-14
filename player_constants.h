#pragma once
#include <vector>
#include "player_constants_filenames.h"
#include <memory>

class player_constants
{
private:
	std::shared_ptr< player_constants_filenames> pcf = std::make_shared< player_constants_filenames>();
	const std::vector<char*> PLAYER_1_SPRITE_NAMES = { pcf->PLAYER_RIGHT, pcf->PLAYER_TOP,pcf->PLAYER_LEFT,pcf->PLAYER_BOTTOM };
	const std::vector<char*> PLAYER_2_SPRITE_NAMES = { pcf->PLAYER2_RIGHT, pcf->PLAYER2_TOP,pcf->PLAYER2_LEFT,pcf->PLAYER2_BOTTOM };
	const std::vector<char*> PLAYER_3_SPRITE_NAMES = { pcf->PLAYER3_RIGHT, pcf->PLAYER3_TOP,pcf->PLAYER3_LEFT,pcf->PLAYER3_BOTTOM };
	const std::vector<char*> PLAYER_4_SPRITE_NAMES = { pcf->PLAYER4_RIGHT, pcf->PLAYER4_TOP,pcf->PLAYER4_LEFT,pcf->PLAYER4_BOTTOM };

	const std::vector<double> start_x_co = { 63.0,651.0,63.0,651.0 };
	const std::vector<double> start_y_co = { 63.0,651.0,651.0,63.0 };
public:


	std::vector<char*> get_player_1_sprite_name() const;
	std::vector<char*> get_player_2_sprite_name() const;
	std::vector<char*> get_player_3_sprite_name() const;
	std::vector<char*> get_player_4_sprite_name() const;

	std::vector<double> get_start_x_co() const;
	std::vector<double> get_start_y_co() const;
};