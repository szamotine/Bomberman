#pragma once

#include "red_brick_logic.h"

red_brick_logic::~red_brick_logic() {

}
red_brick_logic::red_brick_logic(world w) {
	world_pointer = &w;
	terrain_pointer = world_pointer->pointer_terrain;
}

