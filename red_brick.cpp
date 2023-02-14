#include "red_brick.h"
#include <iostream>

red_brick::red_brick(double x, double y) {
	x_coordinate = x;
	y_coordinate = y;
	flag_delete = false;
	/*
	double x_index = ((x + 21) / 42) - 1;
	double y_index = ((y + 21) / 42) - 1;
	std::cout << "\nRed Brick Constructed at x: " << x_index << ", y: " << y_index;
	*/
}

red_brick::~red_brick() {
	//std::cout << "Red Brick destructor";
}

double red_brick::get_x_coordinate() {
	return x_coordinate;
}

double red_brick::get_y_coordinate() {
	return y_coordinate;
}

int red_brick::get_i_index()
{
	return i_index;
}

int red_brick::get_j_index()
{
	return j_index;
}

bool red_brick::get_flag() {
	return flag_delete;
}

void red_brick::set_i_index(int value)
{
	i_index = value;
}

void red_brick::set_j_index(int value)
{
	j_index = value;
}

void red_brick::set_flag_false() {
	flag_delete = true;
}
