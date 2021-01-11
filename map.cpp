#include <iostream>
#include <cstdio>
#include <cmath>
#include <Windows.h>
#include "2D_graphics.h"

#include "timer.h"
#include "ran.h"
#include "map.h"

using namespace std;

//github edit test


void map::red_bricks_generation() {
	// transfered to red_brick class
	int i;
	
	for (i=0; i < n_red_bricks; i++) {
		draw_sprite(red_bricks_sprite_id, x_red_bricks[i], y_red_bricks[i], bricks_angle, bricks_scale);
		
	}
	
};

void map::random_map() {


};

void map::basic_map() {

	draw_sprite(background_sprite_id, x_background, y_background, q_background, scale_background);

	int n = 18; 
	x_buffer = new double[n];
	y_buffer = new double[n];

	if (x_buffer == NULL || y_buffer == NULL) {
		cout << "\n x_buffer/y_buffer allocation error";
		return;
	}
 
	// initializing the x and y coordinates
	// due to the fact that the icon is square the disctinctions between y and x is uncessary
	// however for clarity it was still decided to use both x and y 
	for (int i = 1; i <= n; i++) {
		x_buffer[i] = (i * 42) - 21;
		y_buffer[i] = (i * 42) - 21;


	}
	
	// draw the countour of the map 
	// current iteration repeat all 4 corners
	// would be better to replace with just the right amount of entities
	for (int i = 1; i < n; i++) {
		draw_sprite(grey_bricks_sprite_id, x_buffer[i], 21, bricks_angle, bricks_scale);
		draw_sprite(grey_bricks_sprite_id, x_buffer[i], 693, bricks_angle, bricks_scale);
		draw_sprite(grey_bricks_sprite_id, 21, y_buffer[i], bricks_angle, bricks_scale);
		draw_sprite(grey_bricks_sprite_id, 693, y_buffer[i], bricks_angle, bricks_scale);
	}
	
	// the value 49 is found from the loop below
	n_grey_bricks = 49; 
	x_grey_bricks = new double[n_grey_bricks];
	y_grey_bricks = new double[n_grey_bricks];

	int count = 0; 

	// create the check pattern 
	// we jump one element of the array so that we have a checkboard pattern
	// to vary the height, we use the number of pixels as a reference and a small arithmetic calculation
	for (int i = 3; i < n-2; i= i+2) {
		for (int j = 0; j < 7; j ++) {
			draw_sprite(grey_bricks_sprite_id, x_buffer[i], double((j*84.0)+105.0), bricks_angle, bricks_scale);
			x_grey_bricks[count] = x_buffer[i];
			y_grey_bricks[count] = double((j * 84.0) + 105.0);
			count++;
		}
	}
	
	red_bricks_generation();


};

//constructor to initialize the map 
map::map() {
	//cout << "\nConstructor to initialize the map";
	//getchar();

	int i = 0;
	int k = 0;
	x_background = y_background = q_background = 0.0;
	scale_background = -1.0;

	create_sprite(background, background_sprite_id);
	create_sprite(grey_bricks, grey_bricks_sprite_id);
	create_sprite(red_bricks, red_bricks_sprite_id);
	
	// draw background by setting x=y=q=0 and scale=-1
	draw_sprite(background_sprite_id, x_background, y_background, q_background, scale_background);
	
	
	// array size determined by loop below (n_red_bricks)
	x_red_bricks = new double[164];
	y_red_bricks = new double[164];

	if (x_red_bricks == NULL || y_red_bricks == NULL) {
		cout << "\n x/y_red_bricks allocation error";
		return;
	}

	//initialize number of red bricks count
	n_red_bricks = 0;
	int j = 11;

	// initializes red brick coordinates:
	
	//drawing each 4 sides 
	for (i = 0; i < j; i++) {
		x_red_bricks[n_red_bricks] = (147 + i * 42);
		y_red_bricks[n_red_bricks] = 63;
		n_red_bricks++;
	}

	for (i=0; i < j; i++) {
		x_red_bricks[n_red_bricks] = (147 + i * 42);
		y_red_bricks[n_red_bricks] = 651;
		n_red_bricks++;
	}

	for (i=0; i < j; i++) {
		x_red_bricks[n_red_bricks] = 63;
		y_red_bricks[n_red_bricks] = (147 + i * 42);
		n_red_bricks++;
	}
	for (i=0; i < j; i++) {
		x_red_bricks[n_red_bricks] = 651;
		y_red_bricks[n_red_bricks] = (147 + i * 42);
		n_red_bricks++;
	}

	//drawing the horizontal lines 

	for (i = 0; i < 6;i++) {
		for (k = 0; k < 13; k++) {
			x_red_bricks[n_red_bricks] = (105 + k * 42);
			y_red_bricks[n_red_bricks] = (147 + i * 84);
			n_red_bricks++;
		}
	}

	// drawing the check pattern 
	for (i = 0; i < 7; i++) {
		for (k = 0; k < 6; k++) {
			x_red_bricks[n_red_bricks] = (147 + k * 84);
			y_red_bricks[n_red_bricks] = (105 + i * 84);
			n_red_bricks++;
		}
	}

	
	
};

//deconstructor of the player matrix 
map::~map() {

	if (x_grey_bricks == NULL || y_grey_bricks == NULL) {
		cout << "\nError in Map Destructor";

	}
	else{
		delete[]x_grey_bricks;
		delete[]y_grey_bricks;
		cout << "\ndestructor for map";
	}
	
};
