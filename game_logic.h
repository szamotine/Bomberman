#pragma once
//#include "world.h"
#include "iMatrix.h"
#include "terrain.h"

class game_logic 
{
private:

	red_brick* rb_pointer{};
	grey_brick* gb_pointer{};
	terrain* terrain_pointer{};
//	world* world_pointer;
	player* player_pointer{};
	iMatrix* collision_pointer{};

	// collision matrix value that indicates destructable red square
	int collision_destructible = 2;
	int collision_indestructible = 1;


public:

	~game_logic();
	game_logic(terrain* pointer_terrain, iMatrix* collision_matrix);

	int calculate_index(double value);

	void collision_matrix_init();

	bool check_player_collision(player* player);

	void player_input();


};