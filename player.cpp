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
