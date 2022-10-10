#pragma once
class red_brick
{
private:
	double x_coordinate;
	double y_coordinate;

public:

	red_brick(double x, double y);
	~red_brick();

	double get_x_coordinate();
	double get_y_coordinate();
};

