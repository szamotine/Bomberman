#include "grey_brick.h"
#include <iostream>
using namespace std;

grey_brick::grey_brick(double x, double y) {
	x_coordinate = x;
	y_coordinate = y;
	/*
	double x_index = ((x + 21) / 42) -1;
	double y_index = ((y + 21) / 42) -1;
	cout << "\nGrey Brick Constructed at x: " << x_index << ", y: " << y_index;
	*/
}

grey_brick::grey_brick(grey_brick& source) {
	x_coordinate = source.get_x_coordinate();
	y_coordinate = source.get_y_coordinate();
}

grey_brick::~grey_brick() {
	//std::cout << "\nGrey Brick destructor";
}

double grey_brick::get_x_coordinate() {
	return x_coordinate;
}

double grey_brick::get_y_coordinate() {
	return y_coordinate;
}