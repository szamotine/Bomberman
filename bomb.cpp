#pragma once

#include "bomb.h"

bomb::~bomb() {

}

bomb::bomb(double x, double y) {
	x_coordinate = x;
	y_coordinate = y;
}

void bomb::set_x_coordinate(double value) {
	x_coordinate = value;
}
void bomb::set_y_coordinate(double value) {
	y_coordinate = value;
}
double bomb::get_x_coordinate() {
	return x_coordinate;
}
double bomb::get_y_coordinate() {
	return y_coordinate;
}
