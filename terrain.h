#pragma once
#include <vector>
#include "grey_brick.h"
#include "red_brick.h"
#include "player.h"
#include "bomb.h"
#include "terrain_constants.h"
#include <vector>

class terrain
{
private:

	// stores the images sprite ids
	int background_sprite_id = {};
	int grey_brick_sprite_id = {};
	int red_brick_sprite_id = {};
	int bomb_sprite_id = {};


	int number_of_players = {};
	terrain_constants terrain_constants_pointer;

public:
	// List of grey bricks
	std::vector<grey_brick> grey_brick_list;
	// List of red bricks
	std::vector<red_brick> red_brick_list;
	// List of players
	std::vector<player> player_list;
	// List of bombs
	std::vector<bomb> bomb_list;


	terrain();

	~terrain();
#pragma region Initialization/Creation Functions
	// Creates sprites, sets number of players, initializes lists and game objects
	void initialize_terrain(int number);
	// Red brick initialization run once at start of game
	void initialize_red_bricks();
	// Creates outer perimeter of red brick objects
	void initialize_red_bricks_outer_perimeter();
	// Creates horizontal lines of red bricks in empty rows
	void initialize_red_bricks_horizontal_lines();
	// Creates horizontal lines of red bricks in rows occupied by grey bricks
	void initialize_red_bricks_horizontal_lines_between_grey_bricks();
	// Creates grid of grey bricks
	void initialize_grey_bricks();
	// Creates player objects
	void initialize_players(int number_of_players);
	// Constructs bomb at given location and adds to bomb list
	void construct_bomb(int i, int j);


#pragma region

#pragma region Draw functions
	void draw_grey_bricks();
	void draw_red_bricks();
	void draw_terrain();
	void draw_players();
	void draw_bombs();
	void draw_map();
#pragma endregion


#pragma region Remove functions
	// Erases bomb from bomb list
	void erase_bomb(int index);
	// Erases red brick from red brick list
	void erase_red_brick(int index);
	// Erases player from player list
	void erase_player(int index);
#pragma endregion
};

