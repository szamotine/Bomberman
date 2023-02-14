#pragma once
class grey_brick
{
private:

	double x_coordinate;
	double y_coordinate;
	int i_index;
	int j_index;

public:

	grey_brick(double x, double y);
	~grey_brick();

	double get_x_coordinate() const;
	double get_y_coordinate() const;

	int get_i_index() const;
	int get_j_index() const;

};

