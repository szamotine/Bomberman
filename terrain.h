#pragma once
#include <vector>
#include "grey_brick.h"
#include "red_brick.h"
#include "player.h"
#include "bomb.h"
#include "terrain_constants.h"
#include <vector>
#include <map>
#include "calculator.h"
#include "iMatrix.h"

class terrain
{
private:

	// stores the images sprite ids
	int background_sprite_id = {};
	int grey_brick_sprite_id = {};
	int red_brick_sprite_id = {};
	int bomb_sprite_id = {};
	int bomb_explosion_sprite_id = {};

	int number_of_players = {};

	// Pointer to terrain constants
	terrain_constants terrain_constants_pointer;

	// List of grey bricks
	std::vector<grey_brick> grey_brick_list;

	// List of players
	std::vector<player> player_list;
	// List of bombs
//	std::vector<bomb> bomb_list;

	// Hash map for red bricks
	std::map<int, red_brick> red_brick_map;

	// Hash map for bomb
	std::map<int, bomb> bomb_map;

	// Pointer to collision matrix
	std::shared_ptr<iMatrix> collision_matrix;

public:

	explicit terrain(std::shared_ptr<iMatrix> collision_matrix);
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
	void initialize_players();
	// Constructs bomb at given location and adds to bomb list
	void construct_bomb(int matrix_value, int i_index, int j_index);
	// Creates red brick at given location and adds to red brick map and collision matrix
	void create_red_brick(int matrix_value, double x, double y);
	// Creates red brick at given location and adds to grey brick list and collision matrix
	void create_grey_brick(double x, double y);


#pragma endregion

#pragma region Draw functions

	void draw_grey_bricks() const;
	void draw_red_bricks() const;
	void draw_terrain() const;
	void draw_players() const;
	void draw_bombs() const;
	void draw_map() const;

#pragma endregion

#pragma region Remove functions

	// Erases player from player list
	void erase_player(int index);

	// Removes red brick from map
	void destroy_red_brick(int matrix_value);

	// Removes bomb from map
	void destroy_bomb(int matrix_value);

#pragma endregion

#pragma region Get Lists

	std::vector <grey_brick> get_grey_brick_list() const;

	grey_brick* get_grey_brick(int index);

	std::vector <player> get_player_list() const;

	player* get_player(int index);

	std::map<int, bomb> get_bomb_map() const;

	std::map<int, bomb>* get_bomb_map_pointer();

	bomb* get_bomb_pointer(int matrix_value);

	std::map<int, bomb>::iterator get_bomb_iterator(int value);

#pragma endregion
};

