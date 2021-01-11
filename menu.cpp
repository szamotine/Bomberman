#include <iostream>
#include <cstdio>
#include <cmath>
#include <Windows.h>

#include "2D_graphics.h"

#include "timer.h"
#include "ran.h"
#include "menu.h"

using namespace std;

void menu::rectangle(double x, double y, double Lx, double Ly,
	double r, double g, double b)
{
	int i;
	double xt[3];
	double yt[3];
	double R[3];
	double G[3];
	double B[3];

	for (i = 0; i < 3; i++) {
		R[i] = r;
		G[i] = g;
		B[i] = b;
	}

	// draw triangle 1-2-3
	xt[0] = x - Lx / 2;
	yt[0] = y - Ly / 2;
	xt[1] = x + Lx / 2;
	yt[1] = y - Ly / 2;
	xt[2] = x + Lx / 2;
	yt[2] = y + Ly / 2;
	triangle(xt, yt, R, G, B);

	// draw triangle 1-3-4
	xt[0] = x - Lx / 2;
	yt[0] = y - Ly / 2;
	xt[1] = x + Lx / 2;
	yt[1] = y + Ly / 2;
	xt[2] = x - Lx / 2;
	yt[2] = y + Ly / 2;
	triangle(xt, yt, R, G, B);

}

void menu::loading_screen() {

	x_background = y_background = q_background = 0.0;
	scale_background = -1.0;

	// draw background by setting x=y=q=0 and scale=-1
	draw_sprite(background_2_sprite_id, x_background, y_background, q_background, scale_background);
		
	draw_sprite(logo_sprite_id, x_logo, y_logo, q_logo, scale_logo);

	update();

	//Sleep(3000); 
	
}; 



void menu::menu_selection() {

	bool player_choice = false; 

	while (player_choice == false) {
		draw_sprite(background_2_sprite_id, x_background, y_background, q_background, scale_background);
		
		draw_sprite(title_sprite_id, x_title, y_title, q_title, scale_title);

	
		// create a rectangular box for text display
		rectangle(357, 600, 514, 60, 0.0012, 0.48, 0.76);
		rectangle(357, 400, 514, 60, 0.0012, 0.48, 0.76);
		rectangle(357, 200, 514, 60, 0.0012, 0.48, 0.76);

		// display text options
		text(str_local, 295, 625);
		text(str_online, 280, 425);
		text(str_settings, 270, 225);


		//display letters to press for player input		
		text("Q", 150, 625);
		text("W", 150, 425);
		text("E", 150, 225);

		update();

		if (input() == 'Q') {
			local();
			player_choice = true;
		}
		if (input() == 'W') {
			player_choice = true;
			online();
		}
		if (input() == 'E') {
			player_choice = true;
			settings();
		}
	
	}
};

void menu::settings() {

	// value to track the state of the player choice
	// false =  no choice made
	// true = choice made
	bool state = false;


	while (state == false) {

		draw_sprite(background_2_sprite_id, x_background, y_background, q_background, scale_background);

		// create a rectangular box for text display
		rectangle(357, 800, 514, 60, 0.0012, 0.48, 0.76);
		rectangle(357, 600, 514, 60, 0.0012, 0.48, 0.76);
		rectangle(357, 400, 514, 60, 0.0012, 0.48, 0.76);
		rectangle(357, 100, 314, 30, 0.0012, 0.48, 0.76);

		// display text options
		text(str_settings, 270, 825, 1);
		text(str_sound, 295, 625);
		text(str_volume, 280, 425);
		text(str_back, 330, 115, 0.5);

		//display letters to press for player input
		text("Q", 150, 625);
		text("W", 150, 425);
		text("R", 270, 115, 0.5);

		if (input() == 'Q') {
	
		}
		if (input() == 'W') {
	
		}
		if (input() == 'R') {
			menu_selection();
		}

		update();
	}
};


void menu::local() {
	
	bool player_choice = false;
 
	while (player_choice == false) {

		draw_sprite(background_2_sprite_id, x_background, y_background, q_background, scale_background);

		// create a rectangular box for text display
		rectangle(357, 800, 514, 60, 0.0012, 0.48, 0.76);
		rectangle(357, 600, 514, 60, 0.0012, 0.48, 0.76);
		rectangle(357, 400, 514, 60, 0.0012, 0.48, 0.76);
		rectangle(357, 200, 514, 60, 0.0012, 0.48, 0.76);
		rectangle(357, 100, 314, 30, 0.0012, 0.48, 0.76);
	

		// display text options
		text(str_player_number, 170, 825, 1);
		text("2", 357, 625);
		text("3", 357, 425);
		text("4", 357, 225);
		text(str_back, 330, 115, 0.5);

		//display letters to press for player input
		text("Q", 150, 625);
		text("W", 150, 425);
		text("E", 150, 225);
		text("R", 270, 115, 0.5);

		update();

		if (input() == 'Q') {
			player_number = 2;
			player_choice = true;
			local_game = true;
		}
		if (input() == 'W') {
			player_number = 3;
			player_choice = true;
			local_game = true;
		}
		if (input() == 'E') {
			player_number = 4;
			player_choice = true;
			local_game = true;
		}
		if (input() == 'R') {
			menu_selection();
		}
	}
};


char menu::input() {
	if (KEY('Q')) return 'Q';
	if (KEY('W')) return 'W';
	if (KEY('E')) return 'E'; 
	if (KEY('R')) return 'R';
}

void menu::online() {
	
	bool player_choice = false;

	while (player_choice == false) {

		draw_sprite(background_2_sprite_id, x_background, y_background, q_background, scale_background);

		// create a rectangular box for text display
		rectangle(357, 800, 514, 60, 0.0012, 0.48, 0.76);
		rectangle(357, 600, 514, 60, 0.0012, 0.48, 0.76);
		rectangle(357, 400, 514, 60, 0.0012, 0.48, 0.76);
		rectangle(357, 200, 514, 60, 0.0012, 0.48, 0.76);
		rectangle(357, 100, 314, 30, 0.0012, 0.48, 0.76);


		// display text options
		text(str_player_number, 170, 825, 1);
		text("2", 357, 625);
		text("3", 357, 425);
		text("4", 357, 225);
		text(str_back, 330, 115, 0.5);

		//display letters to press for player input
		text("Q", 150, 625);
		text("W", 150, 425);
		text("E", 150, 225);
		text("R", 270, 115, 0.5);

		update();

		if (input() == 'Q') {
			player_number = 2;
			player_choice = true;
			online_game = true;
		}
		if (input() == 'W') {
			player_number = 3;
			player_choice = true;
			online_game = true;
		}
		if (input() == 'E') {
			player_number = 4;
			player_choice = true;
			online_game = true;
		}
		if (input() == 'R') {
			menu_selection();
		}
	}
};

bool menu::check() {

	if (game_state == false) {
		return false; 
	}

	return true; 

};

menu::menu() {
	
	x_background = y_background = q_background = 0.0;
	scale_background = -1.0;

	create_sprite(background, background_sprite_id);
	create_sprite(background_2, background_2_sprite_id);
	create_sprite(title, title_sprite_id);
	create_sprite(logo, logo_sprite_id);

	// draw background by setting x=y=q=0 and scale=-1
	draw_sprite(background_2_sprite_id, x_background, y_background, q_background, scale_background);

	update();
	
};

// destructor 
menu::~menu() {

}; 
