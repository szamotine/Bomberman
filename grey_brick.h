#pragma once
class grey_brick
{
private:

	double x_coordinate;
	double y_coordinate;


public:

	grey_brick(double x, double y);
	grey_brick(grey_brick& source);
	~grey_brick();

	double get_x_coordinate();
	double get_y_coordinate();

};

