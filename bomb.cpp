#include <iostream>
#include <cstdio>
#include <cmath>
#include <Windows.h>
#include "2D_graphics.h"
#include <time.h>
#include <chrono>
#include "timer.h"
#include "ran.h"
#include "player.h"
#include "bomb.h"
#include "iMatrix.h"

//testing test_branch_1

using namespace std;

bomb::bomb(int bomb_id) {
	
	//cout << "\nConstructor to initialize a bomb";
	//getchar();
	this->bomb_id = bomb_id;
	//cout << "\n Constructor Bomb ID is :" << bomb_id;

	create_sprite(bomb_ch, bomb_sprite_id);
	i_index = 0;
	j_index = 0;
	
	
	
}


void bomb::draw_bomb() {
	
	draw_sprite(bomb_sprite_id, bomb_x_co, bomb_y_co, bomb_angle, bomb_sprite_scale);
	if (bomb_id < 0 || bomb_x_co < 1 || bomb_y_co < 1)
	{
		cout << "\nDrawing bomb # " << bomb_id << " at : " << bomb_x_co << "," << bomb_y_co;
		cout << "\nDrawing bomb # " << bomb_id << " at : " << i_index << "," << i_index;
	}
	
}

void bomb::end_bomb() {

}

bomb::~bomb() {
	

	cout << "\ndestructor for bomb";
}