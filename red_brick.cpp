#include "red_brick.h"
#include <iostream>
#include "calculator.h"

red_brick::red_brick(double x, double y) : x_coordinate(x), y_coordinate(y) {
	i_index = calculator::calculate_index(x);
	j_index = calculator::calculate_index(y);

	if (i_index > 17 || i_index < 0)
	{
		throw std::out_of_range("Index error in red brick construction: i_index= " + i_index);
	}
	if (j_index > 17 || j_index < 0)
	{
		throw std::out_of_range("Index error in red brick construction: j_index= " + j_index);
	}
	matrix_value = calculator::matrix_value(i_index, j_index);
}

red_brick::~red_brick() = default;

double red_brick::get_x_coordinate() const {
	return x_coordinate;
}

double red_brick::get_y_coordinate() const {
	return y_coordinate;
}

int red_brick::get_i_index() const {
	if (i_index > 17 || i_index < 0)
	{
		throw std::out_of_range("Index error in get_i_index " + i_index);
	}
	return i_index;
}

int red_brick::get_j_index() const {
	if (j_index > 17 || j_index < 0)
	{
		throw std::out_of_range("Index error in get_j_index: " + j_index);
	}
	return j_index;
}

bool red_brick::get_flag()  const {
	return flag_delete;
}

void red_brick::set_flag_false() {
	flag_delete = true;
}

