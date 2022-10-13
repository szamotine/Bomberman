#pragma once
#include <iostream>

#include "bomb.h"

bomb::~bomb() {
	
}

bomb::bomb(double x, double y, double t) {
	x_coordinate = x;
	y_coordinate = y;
	time = t;
	bomb_removal_flag = false;
	/*
	int x_index = (int)((x + 21) / 42) - 1;
	int y_index = (int)((y + 21) / 42) - 1;
	std::cout << "\nBomb Constructed at x: " << x_index << ", y: " << y_index;
	*/
}

void bomb::set_x_coordinate(double value) {
	x_coordinate = value;
}
void bomb::set_y_coordinate(double value) {
	y_coordinate = value;
}
void bomb::set_time(double value) {
	time = value;
}
void bomb::set_bomb_removal_flag()
{
	bomb_removal_flag = true;
}
double bomb::get_x_coordinate() {
	return x_coordinate;
}
double bomb::get_y_coordinate() {
	return y_coordinate;
}

double bomb::get_time() {
	return time;
}

bool bomb::get_bomb_removal_flag()
{
	return bomb_removal_flag;
}
