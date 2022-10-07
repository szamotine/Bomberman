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

using namespace std;

//used for the start_picker function
int start_pos[4] = { 0,0,0,0 };


// function to choose the start position of the player 
int player::start_picker() {
	//-------NEED TO WORK ON--------

	// seed for the random generator 
	long int s = -7;
	//should give us a number between 0 and 1
	double picker = ran(s);


	// checking where picker is between 0 and 1
	// either between 0 and 0.25, 0.25 and 0.5, 0.5 and 0.75 and 1
	if (picker < 0.25) {
		if (start_pos[0] == 0) {
			start_pos[0] = 1; 
			cout << picker;
			return 0; 
		}
		picker += 0.25; 
	}

	if ((0.25 <= picker) && (picker < 0.5)) {
		if (start_pos[1] == 0) {
			start_pos[1] = 1;
			cout << picker;
			return 1;
		}
		picker += 0.25;
	}

	if ((0.5 <= picker) && (picker < 0.75)) {
		if (start_pos[2] == 0) {
			start_pos[2] = 1;
			cout << picker;
			return 2;
		}
		picker += 0.25;
	}

	if ((0.75 <= picker) && (picker < 1)) {
		if (start_pos[3] == 0) {
			start_pos[3] = 1;
			cout << picker;
			picker -= 0.75;
			return 3;
		}
		
	}

};

double player::get_x_co() {
	return player_x_co;
};

double player::get_y_co() {
	return player_y_co;
};

double player::get_orientation() {
	return player_orientation;
};

void player::set_x_co(double value) {
	player_x_co = value;
};

void player::set_y_co(double value) {
	player_y_co = value; 
}

void player::set_orientation(double value) {
	player_orientation = value; 
};

void player::draw_player() {

	if (player_orientation == 270) {

		draw_sprite(bottom_sprite_id, player_x_co, player_y_co, player_angle, player_sprite_scale);
	}

	if (player_orientation == 0) {

		draw_sprite(right_sprite_id, player_x_co, player_y_co, player_angle, player_sprite_scale);
	}

	if (player_orientation == 90) {

		draw_sprite(top_sprite_id, player_x_co, player_y_co, player_angle, player_sprite_scale);
	}

	if (player_orientation == 180) {

		draw_sprite(left_sprite_id, player_x_co, player_y_co, player_angle, player_sprite_scale);
	}
	
	
};


//constructor to initialize the player position and skin 
player::player(int n_player) {

	
	//intialize with bottom_player to have the player facing us
	//changes the color of the skin depending on the player number
	
	
	if (n_player == 0 && n_objects == 0) {
		create_sprite(PLAYER_BOTTOM, bottom_sprite_id);
		create_sprite(PLAYER_TOP, top_sprite_id);
		create_sprite(PLAYER_LEFT, left_sprite_id);
		create_sprite(PLAYER_RIGHT, right_sprite_id);
		player_x_co = start_x_co[0];
		player_y_co = start_y_co[0];
	}
	else if (n_player == 1 && n_objects == 1) {
		create_sprite(PLAYER2_BOTTOM, bottom_sprite_id);
		create_sprite(PLAYER2_TOP, top_sprite_id);
		create_sprite(PLAYER2_LEFT, left_sprite_id);
		create_sprite(PLAYER2_RIGHT, right_sprite_id);
		player_x_co = start_x_co[1];
		player_y_co = start_y_co[1];
		
	}
	else if (n_player == 2 && n_objects == 2) {
		create_sprite(PLAYER3_BOTTOM, bottom_sprite_id);
		create_sprite(PLAYER3_TOP, top_sprite_id);
		create_sprite(PLAYER3_LEFT, left_sprite_id);
		create_sprite(PLAYER3_RIGHT, right_sprite_id);
		player_x_co = start_x_co[2];
		player_y_co = start_y_co[2];
		
	}
	else if (n_player == 3 && n_objects == 3) {
		create_sprite(PLAYER4_BOTTOM, bottom_sprite_id);
		create_sprite(PLAYER4_TOP, top_sprite_id);
		create_sprite(PLAYER4_LEFT, left_sprite_id);
		create_sprite(PLAYER4_RIGHT, right_sprite_id);
		player_x_co = start_x_co[3];
		player_y_co = start_y_co[3];
		
	}
	else if (n_player < 0 || n_player > 3 ) {
		cout << "\nInvalid number of players. See error in player::player\n";
		return; 
	}

	player_orientation = 270; 

	//update the count of objects
	n_objects++;
};

//deconstructor of the player matrix 
player::~player() {
	cout << "\ndestructor for player";
};
