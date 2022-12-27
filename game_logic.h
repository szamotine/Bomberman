#pragma once
//#include "world.h"
#include "iMatrix.h"
#include "terrain.h"

class game_logic 
{
private:

	red_brick* rb_pointer{};
	grey_brick* gb_pointer{};
	terrain* terrain_pointer{};
//	world* world_pointer;
	player* player_pointer{};
	iMatrix* collision_pointer{};
	bomb* bomb_pointer{};

	// collision matrix values

	enum Collision_Type
	{
		None,
		Indestructible,
		Destructible,
		Bomb
	};

	//int collision_indestructible = 1; //grey bricks
	//int collision_destructible = 2; // red bricks
	//int collision_bomb = 3;

	// freq used to store current time
	double current_time{};

	//player orientations
	static constexpr double RIGHT = 0.0;
	static constexpr double UP = 90.0;
	static constexpr double LEFT = 180.0;
	static constexpr double DOWN = 270.0;

	


public:

	~game_logic();
	game_logic(terrain* pointer_terrain, iMatrix* collision_matrix);

	int calculate_index(double value);
	double calculate_coordinate(int index);

	void collision_matrix_init();

	bool check_player_movement(player* player);

	void player_input();

	void check_bomb_flag_time(player* p);
	void check_bomb_timer();
	void new_bomb(player* p);
	bool check_bomb_collison(player* p);
	void explode_bomb(bomb* bomb);

	void check_exploding_bomb_proximity(bomb* b);

	void flag_chain_bomb(int i, int j);

	void remove_flagged_bricks();

	void remove_flagged_bombs();

	void remove_flagged_players();

	void check_player_bomb_interaction(bomb* b);

	bool check_player_bomb_proximity(int i, int j);

	bool check_matrix_for_bomb(int i, int j);
	bool check_matrix_for_empty_space(int i, int j);

	void bomb_flag_red_bricks(int bomb_i_index, int bomb_j_index);
	void set_matrix_to_empty_space(int i, int j);
	void set_matrix_to_bomb(int i, int j);

};

