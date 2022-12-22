#include "timer.h"
#include "terrain.h"
#include <iostream>
#include "2D_graphics.h"

terrain::~terrain() {
	cout << "\nTerrain Destructed";
}

terrain::terrain() {
	cout << "\nTerrain Constructed";
}

void terrain::initialize_terrain(int number) {
	number_of_players = number;
	create_sprite(background, background_sprite_id);
	create_sprite(grey_bricks, grey_brick_sprite_id);
	create_sprite(red_bricks, red_brick_sprite_id);
	create_sprite(bomb_file, bomb_sprite_id);

	grey_brick_list = std::vector<grey_brick>();
	red_brick_list = std::vector<red_brick>();
	player_list = std::vector<player>();
	bomb_list = std::vector<bomb>();
	initialize_grey_bricks();
	initialize_red_bricks();
	initialize_players(number);
}

void terrain::initialize_red_bricks() {
	//create red bricks, add them to red_brick_list

	// coordinates for red bricks
	double x;
	double y;

	for (double i = 1; i <= 9; i++) {

		x = (147 + (i * 42));
		y = x;

		red_brick_list.push_back(red_brick(x, 63));
		red_brick_list.push_back(red_brick(x, 651));

		red_brick_list.push_back(red_brick(63, y));
		red_brick_list.push_back(red_brick(651, y));
	}
	 
	for (double i = 0; i < 6; i++) {
		for (double k = 0; k < 13; k++) {
			x = (105 + k * 42);
			y = (147 + i * 84);
			red_brick_list.push_back(red_brick(x, y));
		}
	}
	for (double i = 0; i < 7; i++) {
		for (double k = 0; k < 6; k++) {
			x = (147 + k * 84);
			y = (105 + i * 84);
			red_brick_list.push_back(red_brick(x, y));
		}
	}
}

void terrain::initialize_grey_bricks() {
	int n = 16;

	// create the top/bottom of the enclosed terrain
	for (double i = 2; i <= n; i++) {

		double x_coordinate = ((i * 42) - 21);
		
		grey_brick_list.push_back(grey_brick(x_coordinate, 21));
		grey_brick_list.push_back(grey_brick(x_coordinate, 693));
	}
	
	// create the side walls of the enclosed terrrain
	for (double i = 1; i <= n+1; i++) {
		double y_coordinate = ((i * 42) - 21);

		grey_brick_list.push_back(grey_brick(21, y_coordinate));
		grey_brick_list.push_back(grey_brick(693, y_coordinate));
	}
		
	// create the check pattern 
	for (int i = 3; i < 16; i = i + 2) {
		for (int j = 0; j < 7; j++) {
			double x_coordinate = ((i * 42) - 21);
			double y_coordinate = ((j * 84.0) + 105.0);
			grey_brick_list.push_back(grey_brick(x_coordinate, y_coordinate));
		}
	}

}


void terrain::initialize_players(int number_of_players)
{
	for (int i = 0; i < number_of_players; i++) {
		
		player_list.push_back(player(i));
	}
}

void terrain::draw_grey_bricks(){
	
	if (grey_brick_list.size() > 0) {
		for (grey_brick gb : grey_brick_list) {
			
			//cout << "\nDrawing grey brick at x: " << gb.get_x_coordinate() << " y: " << gb.get_y_coordinate();

			draw_sprite
			(
				grey_brick_sprite_id,
				gb.get_x_coordinate(),
				gb.get_y_coordinate(),
				brick_angle,
				brick_scale
			);
		}
	}
}

void terrain::draw_red_bricks()
{
	if (red_brick_list.size() > 0) {
		for (red_brick rb : red_brick_list) {

			//cout << "\nDrawing grey brick at x: " << gb.get_x_coordinate() << " y: " << gb.get_y_coordinate();

			draw_sprite
			(
				red_brick_sprite_id,
				rb.get_x_coordinate(),
				rb.get_y_coordinate(),
				brick_angle,
				brick_scale
			);
		}
	}

}

void terrain::draw_terrain(){
	draw_sprite(background_sprite_id, x_background, y_background, q_background, scale_background);
}

void terrain::draw_players(){

	if (player_list.size() > 0) {
		for (player p : player_list) {


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

void terrain::draw_bombs() {

	
	if (bomb_list.size() > 0) {
		for (bomb b : bomb_list) {


			draw_sprite
			(
				bomb_sprite_id,
				b.get_x_coordinate(),
				b.get_y_coordinate(),
				bomb_angle,
				bomb_scale
			);
		}
	}
}

void terrain::draw_map() {

	draw_terrain();
	draw_grey_bricks();
	draw_red_bricks();
	draw_players();
	draw_bombs();
}

void terrain::create_bomb(double x, double y) {
	bomb_list.push_back(bomb(x,y,high_resolution_time()));
}

void terrain::remove_bomb(int index) {
	bomb_list.erase(bomb_list.begin() +index);
}

void terrain::remove_red_brick(int index) {
	red_brick_list.erase(red_brick_list.begin() + index);
}