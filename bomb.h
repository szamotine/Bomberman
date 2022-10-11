#pragma once

class bomb 
{
private:
	double x_coordinate;
	double y_coordinate;

	double time;
	bool bomb_removal_flag;


public:

	~bomb();
	bomb(double x, double y, double t);

	void set_x_coordinate(double value);
	void set_y_coordinate(double value);
	void set_time(double value);
	

	double get_x_coordinate();
	double get_y_coordinate();
	double get_time();
};