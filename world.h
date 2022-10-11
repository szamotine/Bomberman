#pragma once
#include "terrain.h"
#include "2D_graphics.h"
#include<vector>

class world
{
private:
	//pointer to terrain object
	terrain* pointer_terrain;
	vector<player>* pointer_terrain_list;
	player* pointer_player;
	

public:

	world();
	~world();
	void initialize_world();
	void draw_world();

	void player_input();

};

