#pragma once
#include "terrain.h"

class world
{
private:
	//pointer to terrain object
	terrain* pointer_terrain;

public:

	world();
	~world();
	void initialize_world();
	void draw_world();

};

