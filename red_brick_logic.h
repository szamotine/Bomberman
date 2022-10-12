#pragma once
#include "red_brick.h"
#include "terrain.h"
#include "world.h"

class red_brick_logic 
{
private:

	red_brick* rb_pointer{};
	terrain* terrain_pointer{};
	world* world_pointer;

public:

	~red_brick_logic();
	red_brick_logic(world w);

	void red_brick_remove();


};