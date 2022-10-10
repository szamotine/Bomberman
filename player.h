#pragma once
class player
{
private:
	double x_coordinate;
	double y_coordinate;

	double orientation;

public:

	player(double x, double y, double angle);
	~player();

	double get_x_coordinate();
	double get_y_coordinate();
	double get_orientation();

	void set_x_coordinate(double value);
	void set_y_coordinate(double value);
	void set_orientation(double value);
};

