#pragma once
#include <vector>


class player_constants
{
private:

	const std::vector<char*> PLAYER_1_SPRITE_NAMES = { "player_right.png","player_top.png","player_left.png","player_bottom.png" };
	const std::vector<char*> PLAYER_2_SPRITE_NAMES = { "player_right_2.png","player_top_2.png","player_left_2.png","player_bottom_2.png" };
	const std::vector<char*> PLAYER_3_SPRITE_NAMES = { "player_right_3.png","player_top_3.png","player_left_3.png","player_bottom_3.png" };
	const std::vector<char*> PLAYER_4_SPRITE_NAMES = { "player_right_4.png","player_top_4.png","player_left_4.png","player_bottom_4.png" };

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