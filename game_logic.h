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
	bomb* bomb_pointer{};

	// collision matrix value that indicates destructable red square
	int collision_destructible = 2;
	int collision_indestructible = 1;
	
	// freq used to store current time
	double current_time{};


public:

	~game_logic();
	game_logic(terrain* pointer_terrain, iMatrix* collision_matrix);

	int calculate_index(double value);
	double calculate_coordinate(int index);

	void collision_matrix_init();

	bool check_player_collision(player* player);

	void player_input();

	void check_bomb_flag(player* p);
	void check_bomb_timer();
	void new_bomb(player* p);
	bool check_bomb_collison(player* p);
	void explode_bomb(bomb* bomb);

	void remove_red_brick(int i, int i_index, int j_index);
	void remove_flagged_bricks();

};