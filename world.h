#pragma once
#include "terrain.h"
#include "2D_graphics.h"
#include<vector>
#include "iMatrix.h"
#include "game_logic.h"




class world
{
private:
	
	// pointers to objects
	player* pointer_player{};
	bomb* pointer_bomb{};
	game_logic* pointer_brick_logic{};

	

	//collision matrix grid size, based on play area: currently 15x15 area
	int area = 17;

	//number of players: currently hardcoded
	int number_of_players = 1;
	

public:

	iMatrix* collision_matrix;

	//pointer to terrain object
	terrain* pointer_terrain;

	world();
	~world();
	void initialize_world();
	void draw_world();

	void run();

	//void player1_input();

	void check_bomb_time(player* p);
	void check_bomb_timer();
	void new_bomb_coordinates(player* p);
};

