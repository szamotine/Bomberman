#pragma once
#include <iostream>
#include <cstdio>
#include <cmath>
#include <Windows.h>
#include "2D_graphics.h"
#include "timer.h"
#include "ran.h"
#include "iMatrix.h"
#include "world.h"
#include "red_brick_logic.h"




using namespace std;

static int init = 0; // initialization flag
static double t; // clock time from start of program
static double t0; // initial clock time
// * tp is the previous clock time -- ie the clock time from 
// the previous function call.
// we want tp static so it's remembered between function calls
static double tp;

double T, fps;


void FPS();
void grid_overlay();
void initialize();



world W1 = world();
red_brick_logic RBL = red_brick_logic(W1);



int main()
{
		
	// graphics drawing / animation loop
	while(1) {
		
		if (!init) 
		{
			initialize();
			// initialize and setup the 2D graphics library
			initialize_graphics();

			clear();

			W1.initialize_world();
		}

		clear(); // clear the previous drawing

		//W1.input(); // moves player

		//W1.sim_step(); // checks for collisions with contour wall

		//W1.collision_map(); // checks for collisions with grey/red bricks, bombs

		//W1.draw(); 

//		FPS();
		W1.player1_input();
		W1.check_bomb_timer();
		W1.draw_world();
		grid_overlay();
		update(); // update the drawing


	}
	
	
	return 0;
}

void FPS() 
{
	// read clock time (resolution is 0.1 microseconds)
	t = high_resolution_time() - t0; // time since the program started (s)

	// calculate period / time interval of function -- ie time 
	// to draw a frame 
	T = t - tp; // current time - previous time

	// save the previous time for next time in the function
	// -- update tp *after* it has been used in the functio 
	tp = t;

	// calculate fps
	fps = 1 / T;

	//cout << "\n FPS is: " << fps;

	int xt = 15;
	int yt = 21;
	double scale = 0.4;
	text("FPS = ", xt, yt, scale);

	xt += 80; // move text cursor right

	text(fps, xt, yt, scale);

}

void grid_overlay() 
{
	int x = 42;
	int y = 21;

	int x2 = 1;
	int y2 = 63;


	double scale = 0.4;

	for (int i = 1; i < 16; i++)
	{
		text(i, x, y, scale);
		text(i, x2, y2, scale);
		x += 42;
		y2 += 42;
	}
}

void initialize() {

	t0 = high_resolution_time(); // initial clock time (s)

	// initialize previous time
	t = high_resolution_time() - t0; // current time

	tp = t; // initialize the previous clock time

	init = 1;

	//cout << "\nInitialization section complete";

}
