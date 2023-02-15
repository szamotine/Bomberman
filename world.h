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

	// pointer to collision matrix -> must be initialized before terrain
	std::shared_ptr<iMatrix> collision_matrix = std::make_shared<iMatrix>(area, area);

	// pointer to terrain
	std::shared_ptr<terrain> pointer_terrain = std::make_shared<terrain>(collision_matrix);

	// Pointer to game logic class
	std::shared_ptr<game_logic> pointer_game_logic = std::make_shared<game_logic>(pointer_terrain, collision_matrix);

public:
	world();
	~world();
	// Initializes terrain and collision matrix
	void initialize_world();
	// Gameplay loop 
	void run() const;
};

