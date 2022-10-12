#pragma once
#include "terrain.h"
#include "2D_graphics.h"
#include<vector>

class world
{
private:
	
	// pointers to objects
	player* pointer_player;
	bomb* pointer_bomb;
	

public:

	//pointer to terrain object
	terrain* pointer_terrain;

	world();
	~world();
	void initialize_world();
	void draw_world();

	void player1_input();

	void check_bomb_time(player* p);
	void check_bomb_timer();
	void new_bomb_coordinates(player* p);
};

