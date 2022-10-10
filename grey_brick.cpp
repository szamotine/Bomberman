#include "grey_brick.h"
#include <iostream>

grey_brick::grey_brick(double x, double y) {
	x_coordinate = x;
	y_coordinate = y;
}

grey_brick::~grey_brick() {
	std::cout << "Grey Brick destructor";
}

double grey_brick::get_x_coordinate() {
	return x_coordinate;
}

double grey_brick::get_y_coordinate() {
	return y_coordinate;
}