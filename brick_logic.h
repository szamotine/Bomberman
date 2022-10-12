#pragma once
#include "world.h"
#include "iMatrix.h"

class brick_logic 
{
private:

	red_brick* rb_pointer{};
	grey_brick* gb_pointer{};
	terrain* terrain_pointer{};
	world* world_pointer;
	player* player_pointer{};
	iMatrix* collision_pointer{};

	// collision matrix value that indicates destructable red square
	int collision_destructible = 2;
	int collision_indestructible = 1;


public:

	~brick_logic();
	brick_logic(world w);

	int calculate_index(double value);

	void red_brick_remove();
	void red_brick_collision_matrix_init();

	int check_player_collision();


};