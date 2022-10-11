#include "world.h"
#include <iostream>
#include <Windows.h>
#include "timer.h"

using namespace std;
world::world() {
	pointer_terrain = new terrain();

	if (pointer_terrain == NULL) {
		cout << "Error: pointer_terrain allocation";
	}
	
}
world::~world() {

}
void world::initialize_world() {

	pointer_terrain->initialize_terrain(4);

}
void world::draw_world() {
	pointer_terrain->draw_map();
}

void world::player1_input() {
	int m = 3;

	// pointer to player 1 of terrain player_list
	pointer_player = & pointer_terrain->player_list[0];
	check_bomb_time(pointer_player);
	
	if (KEY('D')) {
		pointer_player->move_player_x(m);
		pointer_player->set_orientation(0.0);
	}
	if (KEY('A')) {
		pointer_player->move_player_x(-m);
		pointer_player->set_orientation(180.0);
	}
	if (KEY('W')) {
		pointer_player->move_player_y(m);
		pointer_player->set_orientation(90.0);
	}
	if (KEY('S')) {
		pointer_player->move_player_y(-m);
		pointer_player->set_orientation(360.0);
	}

	if (KEY('X')) {
		
		if (pointer_player->get_bomb_flag()) {
			pointer_player->set_bomb_time(high_resolution_time());
			new_bomb_coordinates(pointer_player);
			cout << "\nBomb dropped for player 1";
		}
		
	}

	// player 2
	pointer_player = &pointer_terrain->player_list[1];
	check_bomb_time(pointer_player);

	if (KEY('L')) {
		pointer_player->move_player_x(m);
		pointer_player->set_orientation(0.0);
	}
	if (KEY('J')) {
		pointer_player->move_player_x(-m);
		pointer_player->set_orientation(180.0);
	}
	if (KEY('I')) {
		pointer_player->move_player_y(m);
		pointer_player->set_orientation(90.0);
	}
	if (KEY('K')) {
		pointer_player->move_player_y(-m);
		pointer_player->set_orientation(270.0);
	}

	if (KEY('M')) {
		 
		if (pointer_player -> get_bomb_flag()) {
			pointer_player->set_bomb_time(high_resolution_time());
			new_bomb_coordinates(pointer_player);
			cout << "\nBomb dropped for player 2";
		}
	}

}

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

void world::check_bomb_timer() {

	pointer_player = &pointer_terrain->player_list[0];
	double current_time;
	double duration;

	for (int i = 0; i < pointer_terrain->bomb_list.size(); i++) {
		pointer_bomb = &pointer_terrain->bomb_list[i];
		current_time = high_resolution_time();
		duration = current_time - pointer_bomb->get_time();
		
		if ( duration > 3) {
			cout << "\nBomb explode!";
			pointer_terrain->remove_bomb(i);

		}

	}

}