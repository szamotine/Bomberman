#include "red_brick.h"
#include <iostream>

red_brick::red_brick(double x, double y) {
	x_coordinate = x;
	y_coordinate = y;
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
