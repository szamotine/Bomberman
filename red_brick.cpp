#include <iostream>
#include <cstdio>
#include <cmath>
#include <Windows.h>
#include "2D_graphics.h"
#include <time.h>
#include <chrono>
#include "timer.h"
#include "ran.h"
#include "player.h"
#include "red_brick.h"

using namespace std;


//constructor to initialize red brick object
red_brick::red_brick() 
{
	cout << "\nConstructor to initialize the red bricks";
	//getchar();

	create_sprite(red_bricks, red_bricks_sprite_id);

	int i, k;
	int j = 11;


	// array size determined by loop below (n_red_bricks)
	x_red_bricks = new double[164];
	y_red_bricks = new double[164];

	n_red_bricks = 0;
	// initializes red brick coordinates:

	//drawing each 4 sides 
	for (i = 0; i < j; i++) {
		x_red_bricks[n_red_bricks] = (147 + i * 42);
		y_red_bricks[n_red_bricks] = 63;
		n_red_bricks++;
	}

	for (i = 0; i < j; i++) {
		x_red_bricks[n_red_bricks] = (147 + i * 42);
		y_red_bricks[n_red_bricks] = 651;
		n_red_bricks++;
	}

	for (i = 0; i < j; i++) {
		x_red_bricks[n_red_bricks] = 63;
		y_red_bricks[n_red_bricks] = (147 + i * 42);
		n_red_bricks++;
	}
	for (i = 0; i < j; i++) {
		x_red_bricks[n_red_bricks] = 651;
		y_red_bricks[n_red_bricks] = (147 + i * 42);
		n_red_bricks++;
	}

	//drawing the horizontal lines 

	for (i = 0; i < 6; i++) {
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


}

red_brick::~red_brick() 
{
	cout << "/nRed Brick deconstructor";
}

red_brick::red_brick(double x, double y) 
{
	x_coordinate = x;
	y_coordinate = y;

	create_sprite(red_bricks, bricks_sprite_id);


}

void red_brick::red_bricks_draw() 
{//to be removed
	int i;

	for (i = 0; i < n_red_bricks; i++) {
		draw_sprite(red_bricks_sprite_id, x_red_bricks[i], y_red_bricks[i], brick_angle, brick_scale);

	}

}

void red_brick::draw() {
	draw_sprite(red_bricks_sprite_id, x_coordinate, y_coordinate, brick_angle, brick_scale);

}


