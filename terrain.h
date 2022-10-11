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

	// store the images sprite ids
	int background_sprite_id;
	int grey_brick_sprite_id;
	int red_brick_sprite_id;
	int bomb_sprite_id;

	// List of grey bricks
	vector<grey_brick> grey_brick_list;
	int number_of_players;

public:
	// List of red bricks
	vector<red_brick> red_brick_list;
	//List of players
	vector<player> player_list;
	vector<bomb> bomb_list;


	terrain();

	~terrain();

	void initialize_terrain(int number);
	void initialize_player_coordinates();
	void initialize_grey_bricks();
	void initialize_red_bricks();
	void initialize_players(int number_of_players);

	void draw_grey_bricks();
	void draw_red_bricks();
	void draw_terrain();
	void draw_players();
	void draw_bombs();
	void draw_map();

	void create_bomb(double x, double y);
	void remove_bomb(int index);
	
};

