#include "terrain.h"
#include <iostream>
#include "2D_graphics.h"

terrain::~terrain() {
	cout << "\nTerrain Destructed";
}

terrain::terrain() {
	cout << "\nTerrain Constructed";
}

void terrain::initialize_terrain() {
	create_sprite(background, background_sprite_id);
	create_sprite(grey_bricks, grey_brick_sprite_id);
	create_sprite(red_bricks, red_brick_sprite_id);

	grey_brick_list = std::vector<grey_brick>();
	red_brick_list = std::vector<red_brick>();
	initialize_grey_bricks();
}

void terrain::initialize_red_bricks() {}

void terrain::initialize_grey_bricks() {
	int n = 18;

	for (double i = 1; i <= n; i++) {

		grey_brick temp = grey_brick(((i * 42) - 21), ((i * 42) - 21));
		grey_brick_list.push_back(grey_brick(temp));
	}

	cout << "\nGrey Bricks Initialized: " << grey_brick_list.size();
}

void terrain::draw_grey_bricks(){
	if (grey_brick_list.size() > 0) {
		for (grey_brick gb : grey_brick_list) {
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

void terrain::draw_map() {
	draw_grey_bricks();
}

void terrain::draw_player(){}

void terrain::draw_red_bricks(){}