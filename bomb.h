#pragma once

class bomb
{
private:
	double x_coordinate;
	double y_coordinate;
	double time;
	bool bomb_removal_flag = false;
	int i_index;
	int j_index;

public:

#pragma region Constructors
	~bomb();
	bomb(int i_index, int j_index, double t);
#pragma endregion

#pragma region Setters
	void set_x_coordinate(double value);
	void set_y_coordinate(double value);
	void set_time(double value);
	void set_bomb_removal_flag();

#pragma endregion

#pragma region Getters
	double get_x_coordinate() const;
	double get_y_coordinate() const;
	double get_time() const;
	bool get_bomb_removal_flag() const;
	int get_bomb_i_index() const;
	int get_bomb_j_index() const;
#pragma endregion
};