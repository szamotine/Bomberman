#pragma once
#include "calculator.h"

int calculator::calculate_index(double coordinate) {
	double xmin = 21;
	double dx = 42;
	int index;
	double d_index;
	d_index = (coordinate - xmin) / dx;
	index = (int)(d_index + 0.5);
	return index;
}

double calculator::calculate_coordinate(int index) {
	//xmin represents offset from left side of the frame
	//dx is the length of the side of each square area 
	double xmin = 21;
	double dx = 42;
	int coordinate;
	coordinate = (int)(index * dx + xmin);
	return coordinate;
}

int calculator::matrix_value(int i, int j) {
	int matrix_value = (17 + 1) * i + j;
	return matrix_value;
}