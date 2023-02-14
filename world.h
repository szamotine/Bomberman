#pragma once
#include "terrain.h"
#include "2D_graphics.h"
#include<vector>
#include "iMatrix.h"
#include "game_logic.h"
#include <memory>

class world
{
private:

	//collision matrix grid size, based on play area: currently 17x17 area
	int area = 17;
	//number of players: currently hardcoded
	int number_of_players = 2;
	// pointer to player objects
	player* pointer_player{};
	// Pointer to bomb objects
	bomb* pointer_bomb{};
	// pointer to collision matrix -> must be initialized before terrain
	iMatrix* collision_matrix = new iMatrix(area, area);
	// pointer to terrain
	terrain* pointer_terrain = new terrain();

	// Pointer to game logic class
	game_logic* pointer_game_logic = new game_logic(pointer_terrain, collision_matrix);

public:
	world();
	~world();
	// Initializes terrain and collision matrix
	void initialize_world();
	// Gameplay loop 
	void run() const;
};

