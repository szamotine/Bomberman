#pragma once
class red_brick
{
private:
	double x_coordinate;
	double y_coordinate;

	int i_index{};
	int j_index{};

public:

	red_brick(double x, double y);
	~red_brick();

	double get_x_coordinate();
	double get_y_coordinate();

	int get_i_index();
	int get_j_index();

	void set_i_index(int value);
	void set_j_index(int value);

};

