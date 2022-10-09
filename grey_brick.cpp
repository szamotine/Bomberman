
#include <iostream>

#include "grey_brick.h"
#include "2D_graphics.h"

using namespace std;


grey_brick:: grey_brick(double x, double y)
{

	x_coordinate = x;
	y_coordinate = y;
	
	create_sprite(grey_bricks, bricks_sprite_id);
	
}

void grey_brick:: draw() 
{
	draw_sprite(bricks_sprite_id, x_coordinate, y_coordinate, brick_angle, brick_scale);

}

grey_brick::~grey_brick() {

	cout << "/nGrey Brick deconstructor";
}