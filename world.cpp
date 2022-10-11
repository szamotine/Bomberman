#include "world.h"
#include <iostream>
#include <Windows.h>

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

void world::player_input() {
	int m = 3;

	
	pointer_player = & pointer_terrain->player_list[0];
	
	
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
	

}