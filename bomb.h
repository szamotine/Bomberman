#pragma once

class bomb 
{
private:
	double x_coordinate;
	double y_coordinate;


public:

	~bomb();
	bomb(double x, double y);

	void set_x_coordinate(double value);
	void set_y_coordinate(double value);
	double get_x_coordinate();
	double get_y_coordinate();

};