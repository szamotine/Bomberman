
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
#include "menu.h"
#include "red_brick.h"
#include "World.h"

using namespace std;




int main(){


	// initialize and setup the 2D graphics library
	initialize_graphics();

	clear();
	
	
	
	World W1(4,0);
		


	// graphics drawing / animation loop
	while(1) {
		

		clear(); // clear the previous drawing

		W1.input(); // moves player

		W1.sim_step(); // checks for collisions with contour wall

		W1.collision_map(); // checks for collisions with grey/red bricks, bombs

		W1.draw(); 

		update(); // update the drawing
	}
	
	return 0;
}

