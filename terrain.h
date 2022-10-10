#pragma once
#include <vector>
#include "grey_brick.h"
#include "red_brick.h"
#include "player.h"
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

	// bricks angle 
	double brick_angle = 0.0;

	// bricks_scale
	double brick_scale = 1.0;

	// background coordinates to have a background image
	double x_background = 0;
	double y_background = 0;
	double q_background = 0;
	double scale_background = -1.0;

	// store the images sprite ids
	int background_sprite_id;
	int grey_brick_sprite_id;
	int red_brick_sprite_id;

	// List of grey bricks
	vector<grey_brick> grey_brick_list;
	// List of red bricks
	vector<red_brick> red_brick_list;

	//List of players
	vector<player> player_list;


public:



	terrain();

	~terrain();

	void initialize_terrain();

	void initialize_grey_bricks();
	void initialize_red_bricks();

	void draw_grey_bricks();
	void draw_red_bricks();

	void draw_map();
	void draw_terrain();
	void draw_player();
	
};

