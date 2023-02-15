#pragma once
class red_brick
{
private:
	double x_coordinate;
	double y_coordinate;
	int i_index;
	int j_index;
	int matrix_value;

	bool flag_delete = false;

public:

	red_brick(double x, double y);
	~red_brick();

	double get_x_coordinate() const;
	double get_y_coordinate() const;

	int get_i_index() const;
	int get_j_index() const;

	bool get_flag() const;
	void set_flag_false();

};

