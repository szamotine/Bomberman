#include "red_brick.h"
#include <iostream>

red_brick::red_brick(double x, double y) {
	x_coordinate = x;
	y_coordinate = y;
}

red_brick::~red_brick() {
	std::cout << "Red Brick destructor";
}

double red_brick::get_x_coordinate() {
	return x_coordinate;
}

double red_brick::get_y_coordinate() {
	return y_coordinate;
}
