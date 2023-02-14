#include "timer.h"
#include "terrain.h"
#include <iostream>
#include "2D_graphics.h"

#pragma region Constructors
terrain::~terrain() = default;


terrain::terrain() = default;
#pragma endregion

#pragma region Initialization/Creation functions

void terrain::initialize_terrain(int number) {

	number_of_players = number;
	create_sprite(terrain_constants_pointer.get_background_filename(), background_sprite_id);
	create_sprite(terrain_constants_pointer.get_grey_bricks_filename(), grey_brick_sprite_id);
	create_sprite(terrain_constants_pointer.get_red_bricks_filename(), red_brick_sprite_id);
	create_sprite(terrain_constants_pointer.get_bomb_filename(), bomb_sprite_id);

	grey_brick_list = std::vector<grey_brick>();
	red_brick_list = std::vector<red_brick>();
	player_list = std::vector<player>();
	bomb_list = std::vector<bomb>();
	initialize_grey_bricks();
	initialize_red_bricks();
	initialize_players(number);
}

void terrain::initialize_red_bricks() {

	// create red brick pattern
	initialize_red_bricks_outer_perimeter();
	initialize_red_bricks_horizontal_lines();
	initialize_red_bricks_horizontal_lines_between_grey_bricks();

}

void terrain::initialize_red_bricks_outer_perimeter() {
	// coordinates for red bricks
	double x;
	double y;

	//creates pattern on outer perimeter to confine players to corners
	for (int i = 1; i <= 9; i++)
	{
		x = (147 + (i * 42));
		y = x;

		red_brick_list.emplace_back(x, 63);
		red_brick_list.emplace_back(x, 651);

		red_brick_list.emplace_back(63, y);
		red_brick_list.emplace_back(651, y);
	}
}

void terrain::initialize_red_bricks_horizontal_lines() {
	// coordinates for red bricks
	double x;
	double y;

	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 13; k++)
		{
			x = (105 + k * 42);
			y = (147 + i * 84);
			red_brick_list.emplace_back(x, y);
		}
	}
}

void terrain::initialize_red_bricks_horizontal_lines_between_grey_bricks() {
	// coordinates for red bricks
	double x;
	double y;

	for (int i = 0; i < 7; i++)
	{
		for (int k = 0; k < 6; k++)
		{
			x = (147 + k * 84);
			y = (105 + i * 84);
			red_brick_list.emplace_back(x, y);
		}
	}
}

void terrain::initialize_grey_bricks() {
	int n = 16;
	double x_coordinate;
	double y_coordinate;

	// create the top/bottom of the enclosed terrain
	for (int i = 2; i <= n; i++)
	{

		x_coordinate = ((i * 42) - 21);

		grey_brick_list.emplace_back(x_coordinate, 21);
		grey_brick_list.emplace_back(x_coordinate, 693);
	}

	// create the side walls of the enclosed terrrain
	for (int i = 1; i <= n + 1; i++)
	{
		y_coordinate = ((i * 42) - 21);

		grey_brick_list.emplace_back(21, y_coordinate);
		grey_brick_list.emplace_back(693, y_coordinate);
	}

	// create the checkerboard pattern 
	for (int i = 3; i < 16; i = i + 2)
	{
		for (int j = 0; j < 7; j++)
		{
			x_coordinate = ((i * 42) - 21);
			y_coordinate = ((j * 84.0) + 105.0);
			grey_brick_list.emplace_back(x_coordinate, y_coordinate);
		}
	}
}

void terrain::initialize_players(int number_of_players) {
	for (int i = 0; i < number_of_players; i++)
	{
		player_list.emplace_back(i);
	}
}


void terrain::construct_bomb(int i, int j) {
	bomb_list.emplace_back(i, j, high_resolution_time());
}

#pragma endregion

#pragma region Draw functions


void terrain::draw_grey_bricks() const {
	

	if (!grey_brick_list.empty())
	{
		for (grey_brick gb : grey_brick_list)
		{
			draw_sprite
			(
				grey_brick_sprite_id,
				gb.get_x_coordinate(),
				gb.get_y_coordinate(),
				terrain_constants_pointer.get_angle(),
				terrain_constants_pointer.get_scale()
			);
		}
	}
}


void terrain::draw_red_bricks() const {

	if (!red_brick_list.empty())
	{

		for (red_brick rb : red_brick_list)
		{
			draw_sprite
			(
				red_brick_sprite_id,
				rb.get_x_coordinate(),
				rb.get_y_coordinate(),
				terrain_constants_pointer.get_angle(),
				terrain_constants_pointer.get_scale()
			);
		}

	}
}

void terrain::draw_terrain() const {
	draw_sprite(background_sprite_id, terrain_constants_pointer.get_background_coordinates(), terrain_constants_pointer.get_background_coordinates(), terrain_constants_pointer.get_background_coordinates(), terrain_constants_pointer.get_background_scale());
}

void terrain::draw_players() const {
	if (!player_list.empty())
	{
		for (player p : player_list)
		{
			draw_sprite
			(
				p.get_sprite_id(),
				p.get_x_coordinate(),
				p.get_y_coordinate(),
				p.get_angle(),
				p.get_scale()
			);
		}
	}
}

void terrain::draw_bombs() const {
	if (!bomb_list.empty())
	{
		for (bomb b : bomb_list)
		{
			draw_sprite
			(
				bomb_sprite_id,
				b.get_x_coordinate(),
				b.get_y_coordinate(),
				terrain_constants_pointer.get_angle(),
				terrain_constants_pointer.get_scale()
			);
		}
	}
}

void terrain::draw_map() const {

	draw_terrain();
	draw_grey_bricks();
	draw_red_bricks();
	draw_players();
	draw_bombs();
}

#pragma endregion

#pragma region Remove functions

void terrain::erase_bomb(int index) {
	bomb_list.erase(bomb_list.begin() + index);
}

void terrain::erase_red_brick(int index) {
	red_brick_list.erase(red_brick_list.begin() + index);
}
void terrain::erase_player(int index) {
	player_list.erase(player_list.begin() + index);
}

#pragma endregion