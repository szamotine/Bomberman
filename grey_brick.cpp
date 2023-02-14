#include "grey_brick.h"
#include <iostream>
#include "calculator.h"

grey_brick::grey_brick(double x, double y) : x_coordinate(x), y_coordinate(y) {
	i_index = calculator::calculate_index(x);
	j_index = calculator::calculate_index(y);
}

grey_brick::~grey_brick() = default;

double grey_brick::get_x_coordinate() const {
	return x_coordinate;
}

double grey_brick::get_y_coordinate() const {
	return y_coordinate;
}

int grey_brick::get_i_index() const {
	return i_index;
}

int grey_brick::get_j_index() const {
	return j_index;
}
