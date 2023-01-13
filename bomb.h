#pragma once

class bomb 
{
private:
	double x_coordinate;
	double y_coordinate;
	double time;
	bool bomb_removal_flag;
	int i_index, j_index;
	
public:

	~bomb();
//	bomb(double x, double y, double t);
	bomb(int i_index, int j_index, double t);

	void set_x_coordinate(double value);
	void set_y_coordinate(double value);
	void set_time(double value);
	void set_bomb_removal_flag();
	void set_bomb_indices(double x, double y);

	double get_x_coordinate();
	double get_y_coordinate();
	double get_time();
	bool get_bomb_removal_flag();
	int get_bomb_i_index();
	int get_bomb_j_index();
};