#pragma once
#include "world.h"
#include <iostream>
#include <Windows.h>
#include "timer.h"



using namespace std;
world::world() {
	pointer_terrain = new terrain();
	
	
	collision_matrix = new iMatrix(area, area);

	pointer_game_logic = new game_logic(pointer_terrain, collision_matrix);

	if (pointer_terrain == NULL) {
		cout << "Error: pointer_terrain allocation";
	}

	if (collision_matrix == NULL) {
		cout << "Error: collision_matrix allocation";
	}
	
}
world::~world() {

}
void world::initialize_world() {

	pointer_terrain->initialize_terrain(number_of_players);
	pointer_game_logic->collision_matrix_init();

}
void world::draw_world() {
	pointer_terrain->draw_map();
}

void world::run() {
	pointer_game_logic->player_input();
	pointer_game_logic->check_bomb_timer();
	draw_world();
}

/*
void world::check_bomb_time(player* p) {
	
	double current_time = high_resolution_time();

	if (current_time - pointer_player->get_bomb_time() > 0.5) {
		pointer_player->set_bomb_flag(true);
	}
	

}

void world::new_bomb_coordinates(player* p) {
	double x_shift = 35.0;
	double y_shift_down = 40.0;
	double y_shift_up = 30.0;

	// Get Player coordinates
	double x = p->get_x_coordinate();
	double y = p->get_y_coordinate();

	// adjust for bomb sprite size

	if (p->get_orientation() == 0.0) {
		x += x_shift;
	}
	if (p->get_orientation() == 90.0) {
		y += y_shift_up;
	}
	if (p->get_orientation() == 180.0) {
		x -= x_shift;
	}
	if (p->get_orientation() == 270.0) {
		y -= y_shift_down;
	}

	pointer_terrain->create_bomb(x, y);
	p->set_bomb_flag(false);
}
*/

/*
void world::check_bomb_timer() {

	
	double current_time;
	double duration;

	for (int i = 0; unsigned(i) < pointer_terrain->bomb_list.size(); i++) {
		pointer_bomb = &pointer_terrain->bomb_list[i];
		current_time = high_resolution_time();
		duration = current_time - pointer_bomb->get_time();
		
		if ( duration > 3) {
			cout << "\nBomb explode!";
			pointer_terrain->remove_bomb(i);

		}

	}

}
*/