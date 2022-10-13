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

void world::run() {
	pointer_game_logic->player_input();
	pointer_game_logic->check_bomb_timer();
	pointer_game_logic->remove_flagged_bricks();
	pointer_terrain->draw_map();
}

