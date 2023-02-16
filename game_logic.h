#pragma once
#include "iMatrix.h"
#include "terrain.h"
#include<memory>

class game_logic
{
#pragma region Private Fields and Members
private:
	// Pointers to red brick objects
	red_brick* rb_pointer{};
	// Pointers to grey brick objects
	grey_brick* gb_pointer{};
	// Pointers to terrain
	std::shared_ptr<terrain> terrain_pointer;
	// Pointers to player objects
	player* player_pointer{};
	// Pointers to collision matrix
	std::shared_ptr<iMatrix> collision_pointer;
	// Pointers to bomb objects
	bomb* bomb_pointer{};

	// collision matrix values
	enum Collision_Type
	{
		None,
		Indestructible,
		Destructible,
		Bomb
	};

	// used to store current time
	double current_time{};

	//player orientations
	static constexpr double RIGHT = 0.0;
	static constexpr double UP = 90.0;
	static constexpr double LEFT = 180.0;
	static constexpr double DOWN = 270.0;

	// player step movement size for smooth gameplay
	int movement_size = 3;
#pragma endregion

public:
#pragma region Constructors
	~game_logic();

	game_logic(std::shared_ptr<terrain> pointer_terrain, std::shared_ptr<iMatrix>  collision_matrix);

#pragma endregion

#pragma region Player Movement and Actions
	// Checks for player input from keyboard
	void player_input();

	void player_1_input(player* p);
	void player_2_input(player* p);

	// Logic to allow player to move in commanded direction
	bool validate_player_movement(const player* p);

	// Checks player surroundings for obstacles
	bool check_player_offset(double x, double y);

	// Creates new bomb in front of player
	void new_bomb(player* p);

	// Logic to allow bomb to be placed in front of player
	bool validate_bomb_collison(const player* p);

	// Delays bomb placement input
	void validate_bomb_flag_time(player* p);

	void print_player_coordinates(const player* p) const;

#pragma endregion

#pragma region Bomb Explosion

	// Sets off bomb explosion
	void explode_bomb(const bomb* bomb);

	// Checks for other bombs in proximity to the exploding bomb
	void validate_exploding_bomb_proximity(const bomb* b);

	// Marks bombs for removal
	void flag_chain_bomb(int i_index, int j_index);

	// Flags players that are in proximity of exploding bombs for removal
	void validate_player_bomb_interaction(const bomb* b);

	// Checks if player is in proximity of an exploding bomb
	bool validate_player_bomb_proximity(const player* p, const bomb* b);

	// Destroys red bricks that are in bomb proximity
	void validate_red_brick_bomb_interactions(int bomb_i_index, int bomb_j_index);


#pragma endregion

#pragma region Matrix Operations

	// Initializes collision matrix
	void collision_matrix_init();

	// Adds each existing grey brick to the collision matrix
	void collision_matrix_init_grey_bricks();

	// Checks if given matrix space is occupied by a bomb
	bool validate_matrix_for_bomb(int i_index, int j_index);

	// Checks if given matrix space is unoccupied
	bool validate_matrix_for_empty_space(int i, int j);

	// Checks if given matrix space is occupied by a grey brick
	bool validate_matrix_for_grey_brick(int i, int j);

	// Marks given matrix space as unoccupied
	void set_matrix_to_empty_space(int i, int j);

	// Marks given matrix space as occupied by bomb
	void set_matrix_to_bomb(int i, int j);



#pragma endregion

#pragma region Flag Operations

	// Checks bomb timer to flag for explosion
	void validate_bomb_timer();

	// Erases flagged bombs from list
	void remove_flagged_bombs();

	// Erases flagged players from list
	void remove_flagged_players();

#pragma endregion

};

