#pragma once
#include <vector>
#include "grey_brick.h"
#include "red_brick.h"
#include "player.h"
#include "bomb.h"
using namespace std;

class terrain
{
private:

	// store the background image name for ease of use 
	char* background = "background.png";

	// store the grey bricks image name for ease of use
	char* grey_bricks = "grey_bricks.png";

	// store the red bricks image name for ease of use 
	char* red_bricks = "red_bricks.png";

	// store the red bricks image name for ease of use 
	char* bomb_file = "bomb.png";

	// bricks angle 
	double brick_angle = 0.0;

	// bricks_scale
	double brick_scale = 1.0;

	// bomb angle 
	double bomb_angle = 0.0;

	// bomb scale
	double bomb_scale = 1.0;

	// background coordinates to have a background image
	double x_background = 0;
	double y_background = 0;
	double q_background = 0;
	double scale_background = -1.0;

	// stores the images sprite ids
	int background_sprite_id = {};
	int grey_brick_sprite_id = {};
	int red_brick_sprite_id = {};
	int bomb_sprite_id = {};

	
	int number_of_players = {};

public:
	// List of grey bricks
	vector<grey_brick> grey_brick_list;
	// List of red bricks
	vector<red_brick> red_brick_list;
	// List of players
	vector<player> player_list;
	// List of bombs
	vector<bomb> bomb_list;


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

