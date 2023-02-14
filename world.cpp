#pragma once
#include "world.h"
#include <iostream>
#include <Windows.h>
#include "timer.h"



using namespace std;
world::world() = default;
world::~world() = default;

void world::initialize_world() {
	pointer_terrain->initialize_terrain(number_of_players);
	pointer_game_logic->collision_matrix_init();
}

void world::run() const {
	pointer_game_logic->player_input();
	pointer_game_logic->validate_bomb_timer();
	pointer_game_logic->remove_flagged_bricks();
	pointer_game_logic->remove_flagged_bombs();
	pointer_game_logic->remove_flagged_players();
	pointer_terrain->draw_map();

}

