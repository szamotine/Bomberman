#pragma once
#include <iostream>

#include "bomb.h"
#include "calculator.h"

bomb::~bomb() {
	
}
/*
bomb::bomb(double x, double y, double t) {
	x_coordinate = x;
	y_coordinate = y;
	time = t;
	bomb_removal_flag = false;
	set_bomb_indices(x, y);
	
	//std::cout << "\nBomb Constructed at i: " << i_index << ", j: " << j_index;
	
}
*/

bomb::bomb(int i, int j, double t)
{
	i_index = i;
	j_index = j;
	x_coordinate = calculator::calculate_coordinate(i);
	y_coordinate = calculator::calculate_coordinate(j);
	time = t;
	bomb_removal_flag = false;

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
void bomb::set_bomb_indices(double x, double y)
{
	this->i_index = calculator::calculate_index(x);
	this->j_index = calculator::calculate_index(y);
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

int bomb::get_bomb_i_index()
{
	return i_index;
}

int bomb::get_bomb_j_index()
{
	return j_index;
}