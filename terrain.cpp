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
	//TODO : refactor commented code to produce checkerboard pattern with grey bricks

	int n = 16;
	int count = 0;


	// create the top/bottom of the enclosed terrain
	for (double i = 2; i <= n; i++) {

		double x_coordinate = ((i * 42) - 21);
		//grey_brick temp = grey_brick(((i * 42) - 21),21);
		//grey_brick temp2 = grey_brick(((i * 42) - 21), 693);
		
		grey_brick_list.push_back(grey_brick(x_coordinate, 21));
		grey_brick_list.push_back(grey_brick(x_coordinate, 693));


		count += 2;
		cout << "\nGrey Bricks Horizontal Count: " << count;
		
	}

	

	// create the side walls of the enclosed terrrain
	for (double i = 1; i <= n+1; i++) {
		double y_coordinate = ((i * 42) - 21);
		//grey_brick temp3 = grey_brick(21, ((i * 42) - 21));
		//grey_brick temp4 = grey_brick(693, ((i * 42) - 21));

		grey_brick_list.push_back(grey_brick(21, y_coordinate));
		grey_brick_list.push_back(grey_brick(693, y_coordinate));
		count += 2;
		cout << "\nGrey Bricks Vertical Count: " << count;
	}

	
	// create the check pattern 
	// we jump one element of the array so that we have a checkboard pattern
	// to vary the height, we use the number of pixels as a reference and a small arithmetic calculation
	
	for (int i = 3; i < 16; i = i + 2) {
		for (int j = 0; j < 7; j++) {
			double x_coordinate = ((i * 42) - 21);
			double y_coordinate = ((j * 84.0) + 105.0);
			//grey_brick temp = grey_brick(((i * 42) - 21), ((j * 84.0) + 105.0));
			grey_brick_list.push_back(grey_brick(x_coordinate, y_coordinate));
			count += 1;
			
		}
	}
	cout << "\nGrey Bricks Checkerboard Count: " << count;




	/*
	

	

	// the value 49 is found from the loop below
	n_grey_bricks = 49;
	x_grey_bricks = new double[n_grey_bricks];
	y_grey_bricks = new double[n_grey_bricks];

	int count = 0;

	// create the check pattern 
	// we jump one element of the array so that we have a checkboard pattern
	// to vary the height, we use the number of pixels as a reference and a small arithmetic calculation
	for (int i = 3; i < n - 2; i = i + 2) {
		for (int j = 0; j < 7; j++) {
			draw_sprite(grey_bricks_sprite_id, x_buffer[i], double((j * 84.0) + 105.0), bricks_angle, bricks_scale);
			x_grey_bricks[count] = x_buffer[i];
			y_grey_bricks[count] = double((j * 84.0) + 105.0);
			count++;
		}
	}
	*/
	cout << "\nGrey Bricks Count: " << count;
	cout << "\nGrey Bricks Initialized: " << grey_brick_list.size();
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

void terrain::draw_map() {
	
	draw_terrain();
	draw_grey_bricks();
}

void terrain::draw_terrain(){
	draw_sprite(background_sprite_id, x_background, y_background, q_background, scale_background);
}
void terrain::draw_player(){}

void terrain::draw_red_bricks(){}