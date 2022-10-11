#include "world.h"
#include <iostream>

using namespace std;
world::world() {
	pointer_terrain = new terrain();

	if (pointer_terrain == NULL) {
		cout << "Error: pointer_terrain allocation";
	}

	
}
world::~world() {

}
void world:: initialize_world() {

	pointer_terrain->initialize_terrain(4);

}
void world::draw_world() {
	pointer_terrain->draw_map();
}