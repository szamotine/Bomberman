#pragma once
class terrain_constants
{
private:
	// store the background image name for ease of use 
	char* background_filename = "background.png";

	// store the grey bricks image name for ease of use
	char* grey_bricks_filename = "grey_bricks.png";

	// store the red bricks image name for ease of use 
	char* red_bricks_filename = "red_bricks.png";

	// store the red bricks image name for ease of use 
	char* bomb_filename = "bomb.png";

	// angle for bricks and bomb
	double angle = 0.0;

	// scale for bricks and bomb
	double scale = 1.0;

	// background coordinates
	double background_coordinates = 0.0;

	// scale for background
	double background_scale = -1.0;
public:

	char* get_background_filename() const;
	char* get_grey_bricks_filename() const;
	char* get_red_bricks_filename() const;

	char* get_bomb_filename() const;
	double get_angle() const;
	double get_scale() const;
	double get_background_coordinates() const;
	double get_background_scale() const;

	terrain_constants();

};

