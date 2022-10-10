#include "player.h"

player::player(double x, double y, double angle)
{
	x_coordinate = x;
	y_coordinate = y;
	orientation = angle;
}

player::~player()
{
}

double player::get_x_coordinate()
{
	return x_coordinate;
}

double player::get_y_coordinate()
{
	return y_coordinate;
}

double player::get_orientation()
{
	return orientation;
}

void player::set_x_coordinate(double value)
{
	x_coordinate = value;
}

void player::set_y_coordinate(double value)
{
	y_coordinate = value;
}

void player::set_orientation(double value)
{
	orientation = value;
}
