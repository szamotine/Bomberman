#pragma once
#include <iostream>

#include "bomb.h"
#include "calculator.h"

#pragma region Constructors

bomb::~bomb() = default;
bomb::bomb(int i, int j, double t) :time(t), i_index(i), j_index(j) {
	x_coordinate = calculator::calculate_coordinate(i);
	y_coordinate = calculator::calculate_coordinate(j);
}

#pragma endregion

#pragma region Setters

void bomb::set_x_coordinate(double value) {
	x_coordinate = value;
}
void bomb::set_y_coordinate(double value) {
	y_coordinate = value;
}
void bomb::set_time(double value) {
	time = value;
}
void bomb::set_bomb_removal_flag() {
	bomb_removal_flag = true;
}

#pragma endregion

#pragma region Getters

double bomb::get_x_coordinate() const {
	return x_coordinate;
}
double bomb::get_y_coordinate() const {
	return y_coordinate;
}
bool bomb::get_bomb_removal_flag() const {
	return bomb_removal_flag;
}
double bomb::get_time() const {
	return time;
}
int bomb::get_bomb_i_index() const {
	return i_index;
}
int bomb::get_bomb_j_index() const {
	return j_index;
}

#pragma endregion