#pragma once
#include "player_constants.h"
#include <memory>



class player
{
private:

	enum player_orientation
	{
		RIGHT,
		UP,
		LEFT,
		DOWN
	};


	std::shared_ptr<player_constants> player_constant_pointer = std::make_shared<player_constants>();

	double x_coordinate;
	double y_coordinate;

	player_orientation orientation = DOWN;

	double player_angle = 0;
	double player_sprite_scale = 0.67;

	std::vector<int> sprite_id{ 0,0,0,0 };

	// delay bomb drop
	double bomb_flag_time = 0.0;
	bool bomb_flag = true;
	bool removal_flag = false;
	int player_number;

public:

	explicit player(int player_number);
	~player();
#pragma region Getters
	double get_x_coordinate() const;
	double get_y_coordinate() const;
	double get_angle() const;
	double get_scale() const;
	int get_sprite_id() const;
	bool get_bomb_flag() const;
	bool get_player_removal_flag() const;
	double get_bomb_time() const;
	int get_player_number() const;
	player_orientation get_player_orientation() const;

#pragma endregion
#pragma region Setters
	void set_scale(double value);
	void set_bomb_time(double value);
	void set_bomb_flag(bool flag);
	void set_removal_flag();
	void set_player_orientation(int orientation);
#pragma endregion

	void initialize_sprites();
	// moves player in x direction
	void move_player_x(double value);
	// moves player in y direction
	void move_player_y(double value);

};