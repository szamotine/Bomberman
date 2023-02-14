#pragma once

#include "calculator.h"

int calculator::calculate_index(double coordinate)
{
	double xmin = 21, dx = 42;
	double d_index = (coordinate - xmin) / dx;
	int index = (int)(d_index + 0.5);
	return index;
}

double calculator::calculate_coordinate(int index)
{
	//xmin represents offset from left side of the frame
	//dx is the length of the side of each square area 
	double xmin = 21, dx = 42;
	int coordinate = (int)(index * dx + xmin);
	return coordinate;
}