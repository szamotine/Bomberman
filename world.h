#pragma once
#include "terrain.h"
#include "2D_graphics.h"
#include<vector>
#include "iMatrix.h"
#include "game_logic.h"




class world
{
private:
	
	// pointer to player objects
	player* pointer_player{};
	// Pointer to bomb objects
	bomb* pointer_bomb{};
	// Pointer to game logic class
	game_logic* pointer_game_logic{};

	//collision matrix grid size, based on play area: currently 15x15 area
	int area = 17;

	//number of players: currently hardcoded
	int number_of_players = 2;

public:

	iMatrix* collision_matrix;

	//pointer to terrain object
	terrain* pointer_terrain{};

	world();
	~world();
	// Initializes terrain and collision matrix
	void initialize_world();
	// Gameplay loop 
	void run();

};

