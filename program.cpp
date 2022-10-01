
#include <iostream>
#include <cstdio>
#include <cmath>
#include <Windows.h>
#include "2D_graphics.h"
#include "bomb.h"
#include "timer.h"
#include "ran.h"
#include "player.h"
#include "map.h"
#include "iMatrix.h"
//#include "menu.h"
#include "red_brick.h"
#include "World.h"

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


int main(){

	


	// initialize and setup the 2D graphics library
	initialize_graphics();

	clear();
	
	
	
	World W1(4,0);
		


	// graphics drawing / animation loop
	while(1) {
		if (!init) 
		{

			t0 = high_resolution_time(); // initial clock time (s)

			// initialize previous time
			t = high_resolution_time() - t0; // current time

			tp = t; // initialize the previous clock time

			init = 1;

			//cout << "\nInitialization section complete";
		} // end of initialization section

		clear(); // clear the previous drawing

		W1.input(); // moves player

		W1.sim_step(); // checks for collisions with contour wall

		W1.collision_map(); // checks for collisions with grey/red bricks, bombs

		W1.draw(); 

		FPS();
		
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