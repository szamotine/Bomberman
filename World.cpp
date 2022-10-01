
#include <iostream>
#include <cstdio>
#include <cmath>
#include <Windows.h>
#include "2D_graphics.h"
#include "bomb.h"
#include "timer.h"
#include "ran.h"
#include "player.h"
#include "map.h"
#include "iMatrix.h"
//#include "menu.h"
#include "red_brick.h"
#include "World.h"

using namespace std;

// direct_x window size
const int width = 714;
const int height = 914;

// number of squares x and y direction: for collision matrix index
const int N_map = 17, M_map = 17; 

iMatrix World::Grey(N_map, M_map);


void World::remove_bomb(int bomb_id) {
	int is, js;

	cout << "\n\nRemoval of bomb_id: " << bomb_id;
	// local variable for bomb index location
	is = pointer_bomb[bomb_id]->i_index;
	js = pointer_bomb[bomb_id]->j_index;

//	cout << "\n is, js is: " << is << "," << js;
	remove_red_brick(is, js);
	
	// marks bomb location as unoccupied
	Grey.e(is, js) = 0;

	//cout << "\n remove_bomb called";
	int N = total_bomb_count;
	
	//safe delete
	if (pointer_bomb[bomb_id] != NULL) {

		if(N>1)
		{
			cout << "\n Not last bomb, bomb count is: " << total_bomb_count;
			cout << "\n Not last bomb, bomb id being removed is is " << bomb_id << endl;
			pointer_bomb[bomb_id] = pointer_bomb[N-1];
			delete pointer_bomb[N - 1];
			
			cout << "\n Bomb pointer switched and deleted pointer " << N-1; //, bomb count is : " << total_bomb_count;
		}
		else {
			cout << "\n Last bomb, bomb count is " << total_bomb_count;
			cout << "\n Last bomb, bomb id being removed is is " << bomb_id << endl;

			delete pointer_bomb[bomb_id];
			pointer_bomb[bomb_id] = NULL;
			
			cout << "\n Bomb pointer deleted"; //, bomb count is: " << total_bomb_count;


		}

		

	}
	else {
		cout << "/nRemove_bomb error";
			return;
	}
	total_bomb_count--;
	cout << "\nTotal Bomb count at end of Remove Bomb function is: " << total_bomb_count << endl;

	//cout << "/n bomb index is" << is << "," << js;

}

//creates a new bomb in front of the player
void World::new_bomb(int player_number) {
	
	//cout << "\n World::New bomb called";
	total_bomb_count++;
	//cout << "\n Total bomb count at start of new_bomb function is: " << total_bomb_count;
	
	double x_shift = 35.0 ;
	double y_shift_down = 40.0;
	double y_shift_up = 30.0;
	double x = pointer_player[player_number]->player_x_co;
	double y = pointer_player[player_number]->player_y_co;


	// places bomb in front of player
	if (player_orientation[player_number] == 0.0) {
		x += x_shift;
	}
	if (player_orientation[player_number] == 90.0) {
		y += y_shift_up;
	}
	if (player_orientation[player_number] == 180.0) {
		x -= x_shift;
	}
	if (player_orientation[player_number] == 270.0) {
		y -= y_shift_down;
	}

	if (bomb_collision(x,y) == TRUE) {
		
		//cout << "\n Calling bomb index(" << player_number << "," << x << "," << y << ")";
		bomb_index(player_number, x, y);

	}


		
}

// creates entries in collision matrix index for bomb location
void World::bomb_index(int player_number, double bomb_x_co, double bomb_y_co) {
	
	double is, js;
	int i_index, j_index;

	if (pointer_bomb[total_bomb_count] == NULL) {
		//cout << "\nerror in bomb_index";
		//getchar();
		pointer_bomb[total_bomb_count] = new bomb(total_bomb_count);

	}

	if (pointer_bomb[total_bomb_count] == NULL) {
		cout << "\nerror in bomb_index";
		getchar();
		pointer_bomb[total_bomb_count] = new bomb(total_bomb_count);

	}
	
	double x = bomb_x_co, y = bomb_y_co;

	//cout << "\n bomb coordinates are " << x << "," << y << ";" << bomb_x_co << "," << bomb_y_co;
	//int z;
		
	if ((x < width) && (y < height))
	{
		
		//bomb index as double
		is = (x - xmin) / dx;
		js = (y - ymin) / dy;

		//bomb index as int
		i_index = (int)(is + 0.5);
		j_index = (int)(js + 0.5);

		if (Grey.e(i_index, j_index) == 1 || Grey.e(i_index, j_index) == 2 || Grey.e(i_index, j_index) == 3) {
			cout << "\nError:cannot produce bomb: index " << i_index << "," << j_index << " is occupied";
			total_bomb_count--;
			cout << "\nTotal bomb count is returned to : " << total_bomb_count <<endl;

			return;

		}

		// inserts 3 into index indicating bomb location
		if (Grey.e(i_index, j_index) != 1 || Grey.e(i_index, j_index) != 2 || Grey.e(i_index, j_index) != 3){
			if ((i_index < N_map) && (i_index > 0) && (j_index > 0) && (j_index < M_map))
			{
				Grey.e(i_index, j_index) = 3;
				pointer_bomb[total_bomb_count]->bomb_x_co = x;
				pointer_bomb[total_bomb_count]->bomb_y_co = y;

				//cout << "\nPointer to bomb object #: " << total_bomb_count << " sets bomb x_co to : " << pointer_bomb[total_bomb_count]->bomb_x_co;
				//cout << "\nPointer to bomb object #: " << total_bomb_count << " sets bomb y_co to : " << pointer_bomb[total_bomb_count]->bomb_y_co;

							
				pointer_bomb[total_bomb_count]->bomb_id = total_bomb_count;

				cout << "\nBomb Index function sets Bomb ID to : " << pointer_bomb[total_bomb_count]->bomb_id;
				cout << "\nTotal bomb count in bomb_index is : " << total_bomb_count;

				pointer_bomb[total_bomb_count]->i_index = i_index;
				pointer_bomb[total_bomb_count]->j_index = j_index;
				
				cout << "\nPointer to bomb object #: " << total_bomb_count << " sets bomb I Index to : " << pointer_bomb[total_bomb_count]->i_index;
				cout << "\nPointer to bomb object #: " << total_bomb_count << " sets bomb J Index to : " << pointer_bomb[total_bomb_count]->j_index << endl;


				//z = pointer_bomb[total_bomb_count]->i_index;

				//cout <<"/n" << i_index << "," << z;
				

				cout << "\nbomb_count of player #" << player_number << " is: " << bomb_count[player_number] <<  endl;
				bomb_count[player_number]++;
				cout << "\nbomb_count of player #" << player_number << " is: " << bomb_count[player_number] << endl;
				//total_bomb_count++;
				

				//cout << "\nTotal bomb count is :" << total_bomb_count;
				//cout << "\n Bomb ID is: " << (int)pointer_bomb[total_bomb_count]->bomb_id;
				//cout << "\n Bomb index created at " << i_index << "," << j_index;
			
			}

		}

	}
	cout << "\nTotal bomb count after New Bomb function and Bomb Index is: " << total_bomb_count;
	//getchar();
}


boolean World::bomb_collision(double x,double y) 
{
	double is, js;
	int i_index, j_index;

	//bomb index as double
	is = (x - xmin) / dx;
	js = (y - ymin) / dy;

	//bomb index as int
	i_index = (int)(is + 0.5);
	j_index = (int)(js + 0.5);

	if (Grey.e(i_index, j_index) == 1 || Grey.e(i_index, j_index) == 2 || Grey.e(i_index, j_index) == 3) {
		cout << "\nError:bomb_collision: cannot produce bomb: index " << i_index << "," << j_index << " is occupied";
		total_bomb_count--;
		cout << "\nTotal bomb count is returned to : " << total_bomb_count;

		return FALSE;

	}
	else {
		return TRUE;
	}


}
// player/bomb interaction
void World::remove_player(int i) {

	
	
}

void World::remove_red_brick(int i_index, int j_index) {
	int i;
	int m = 1;
	int is = i_index;
	int js = j_index;

	//cout << "\n is, js is: " << is << "," << js;
	
	int x = (int)(is * (double)dx + xmin);
	int y = (int)(js * (double)dy + ymin);

	//cout << "\n x,y is: " << x << "," << y;
	//getchar();
	int n_red_bricks_orig= n_red_bricks;

	//cout << " coords are: " << x << "," << y;
	
	
	for (m = -1; m < 2; m++) {

	
		
		if (Grey.e(is + m, js) == 2)
		{
			int x = (int)((is + m) * (double)dx + xmin);

			for (i = 0; i < n_red_bricks_orig; i++)
			{
				if ((x == xc_red[i]) && (y == yc_red[i]))
				{

					//cout << "\nRemoving brick at " << pointer_map->x_red_bricks[i] << "," << pointer_map->y_red_bricks[i];
					cout << "\nRemoving red brick at " << is + m << "," << js;
					Grey.e(is + m, js) = 0;


					pointer_map->x_red_bricks[i] = 10.0 * width;//pointer_map->x_red_bricks[n_red_bricks];
					pointer_map->y_red_bricks[i] = 10.0 * width;//pointer_map->y_red_bricks[n_red_bricks];
				}
			}

			if (Grey.e(is + 2*m, js) == 2) 
			{
				cout << "\nGrey.e(is+2m, js) ==2 : Positive";
				int x = (int)((is + 2*m) * (double)dx + xmin);
				for (i = 0; i < n_red_bricks_orig; i++)
				{
					if ((x == xc_red[i]) && (y == yc_red[i]))
					{

						//cout << "\nRemoving brick at " << pointer_map->x_red_bricks[i] << "," << pointer_map->y_red_bricks[i];
						cout << "\nRemoving red brick at " << is + 2*m << "," << js;
						Grey.e(is + 2*m, js) = 0;


						pointer_map->x_red_bricks[i] = 10.0 * width;//pointer_map->x_red_bricks[n_red_bricks];
						pointer_map->y_red_bricks[i] = 10.0 * width;//pointer_map->y_red_bricks[n_red_bricks];
					}
				}
			}
		}

		if (Grey.e(is, js + m) == 2)
		{
			int y = (int)((js + m) * (double)dy + ymin);

			for (i = 0; i < n_red_bricks_orig; i++)
			{
				if ((x == xc_red[i]) && (y == yc_red[i]))
				{

					//cout << "\nRemoving brick at " << pointer_map->x_red_bricks[i] << "," << pointer_map->y_red_bricks[i];
					cout << "\nRemoving red brick at " << is << "," << js + m;
					Grey.e(is, js + m) = 0;


					pointer_map->x_red_bricks[i] = 10.0 * width;//pointer_map->x_red_bricks[n_red_bricks];
					pointer_map->y_red_bricks[i] = 10.0 * width;//pointer_map->y_red_bricks[n_red_bricks];
				}
			}
			if (Grey.e(is, js + 2 * m) == 2)
			{
				cout << "\nGrey.e(is, js + 2m) ==2 : Positive";
				int y = (int)((js + 2 * m) * (double)dy + ymin);
				for (i = 0; i < n_red_bricks_orig; i++)
				{
					if ((x == xc_red[i]) && (y == yc_red[i]))
					{

						//cout << "\nRemoving brick at " << pointer_map->x_red_bricks[i] << "," << pointer_map->y_red_bricks[i];
						cout << "\nRemoving red brick at " << is << "," << js + 2*m;
						Grey.e(is, js + 2*m) = 0;


						pointer_map->x_red_bricks[i] = 10.0 * width;//pointer_map->x_red_bricks[n_red_bricks];
						pointer_map->y_red_bricks[i] = 10.0 * width;//pointer_map->y_red_bricks[n_red_bricks];
					}
				}
			}
		}
		
	}

	//if ((Grey.e(is + 1, js) == 2) && (Grey.e(is, js) == 2) && (Grey.e(is+2, js) == 2))
	//{
	//	int x = (int)((is+2) * (double)dx + xmin);
	//	int y = (int)((js) * (double)dy + ymin);
	//	
	//	for (i = 0; i < n_red_bricks_orig; i++)
	//	{
	//		if ((x == xc_red[i]) && (y == yc_red[i]))
	//		{

	//			//cout << "\nRemoving brick at " << pointer_map->x_red_bricks[i] << "," << pointer_map->y_red_bricks[i];
	//			cout << "\nRemoving red brick at " << is + 2 << "," << js;
	//			Grey.e(is + 2, js) = 0;


	//			pointer_map->x_red_bricks[i] = 10.0 * width;//pointer_map->x_red_bricks[n_red_bricks];
	//			pointer_map->y_red_bricks[i] = 10.0 * width;//pointer_map->y_red_bricks[n_red_bricks];
	//		}
	//	}
	//}
	//else {
	//	cout << "\nGrey.e(is/is+1/is+2) == FALSE";
	//}

	//if ((Grey.e(is, js +1 ) == 2) && (Grey.e(is, js) == 2) && (Grey.e(is, js + 2) == 2))
	//{
	//	int x = (int)((is) * (double)dx + xmin);
	//	int y = (int)((js +2) * (double)dy + ymin);

	//	for (i = 0; i < n_red_bricks_orig; i++)
	//	{
	//		if ((x == xc_red[i]) && (y == yc_red[i]))
	//		{

	//			//cout << "\nRemoving brick at " << pointer_map->x_red_bricks[i] << "," << pointer_map->y_red_bricks[i];
	//			cout << "\nRemoving red brick at " << is<< "," << js + 2;
	//			Grey.e(is, js+2) = 0;


	//			pointer_map->x_red_bricks[i] = 10.0 * width;//pointer_map->x_red_bricks[n_red_bricks];
	//			pointer_map->y_red_bricks[i] = 10.0 * width;//pointer_map->y_red_bricks[n_red_bricks];
	//		}
	//	}
	//}
	//else {
	//	cout << "\nGrey.e(js/js+1/js+2) == FALSE";
	//}
	
}

//testing the remove_red_brick function
void World::cheat_remove_red_brick(int i_index, int j_index) {

	int i;
	int x = (int)(i_index * (double)dx + xmin);
	int y = (int)(j_index * (double)dy + ymin);
	int n_red_bricks_orig;

	n_red_bricks_orig = n_red_bricks;

	//cout << " coords are: " << x << "," << y;

	// key 1 is for testing the function. substitute bomb placement 
	for (i = 0; i < n_red_bricks_orig; i++) {
		if (KEY('1') && (x == xc_red[i]) && (y == yc_red[i])) {

			cout << "\nRemoving brick with cheat function at " << i_index << "," << j_index << " ; " << pointer_map->x_red_bricks[i] << "," << pointer_map->y_red_bricks[i];
			Grey.e(i_index, j_index) = 0;
			pointer_map->x_red_bricks[i] = 10.0 * width;//pointer_map->x_red_bricks[n_red_bricks];
			pointer_map->y_red_bricks[i] = 10.0 * width;//pointer_map->y_red_bricks[n_red_bricks];
			//pointer_map->n_red_bricks--;






		}

	}

}


void World::draw() {
	int i; 
	
	//cout << "\nTotal bomb count before draw is: " << total_bomb_count;
	
	// map generation with destructible elements 
	if (map_type == 0) {
		pointer_map->basic_map();
	}
	else if (map_type == 1) {
		pointer_map->random_map();
	}


	// player generation
	for (i = 0; i < n_player; i++) {
		pointer_player[i]->draw_player();
	}

	// bomb generation
	for (i = 1; i <= total_bomb_count; i++) {
		//cout << "\nDrawing bomb  i= #: " << i;
		//cout << "\n Total bomb count at bomb draw call is: " << total_bomb_count;
		pointer_bomb[i]->draw_bomb();
		
	}
	

	

}

void World::sim_step() {
	
	
	int i;
	int m = 3; // size of step movement
	//int k = 13; // size of player sprite from center
	//int l = 21; // length of grey brick from center
	// check for collisions and calculate collision response

	// 4 sides 
	for (i = 0; i < n_player; i++) {
		if (player_x_co[i] <= 55) {
			player_x_co[i] = player_x_co[i] + m;
			pointer_player[i]->set_x_co(player_x_co[i]);
		}
		if (player_x_co[i] >= 660) {
			player_x_co[i] = player_x_co[i] - m;
			pointer_player[i]->set_x_co(player_x_co[i]);
		}
		//  this value needs to be changed to 63 to compensate with the middle of the player sprite 
		if (player_y_co[i] <= 63) {
			player_y_co[i] = player_y_co[i] + m;
			pointer_player[i]->set_y_co(player_y_co[i]);
		}
		if (player_y_co[i] >= 660) {
			player_y_co[i] = player_y_co[i] - m;
			pointer_player[i]->set_y_co(player_y_co[i]);
		}
	}
	
};

void World::input() {
	int i; 
	int m = 3;
	// player input

	//cout << "check input 1";

	if (KEY('D')) player_x_co[0] += m;
	if (KEY('D')) player_orientation[0] = 0.0;

	if (KEY('A')) player_x_co[0] -= m;
	if (KEY('A')) player_orientation[0] = 180.0;

	if (KEY('W')) player_y_co[0] += m;
	if (KEY('W')) player_orientation[0] = 90.0;

	if (KEY('S')) player_y_co[0] -= m;
	if (KEY('S')) player_orientation[0] = 270.0;
	
	if (KEY('X')) {
		if (bomb_count[0] < 3) {
			new_bomb(0);
			
		}
	}

	if (KEY('Z')) {
		if ((total_bomb_count > 0) && (bomb_count[0] > 0)) {
				
			cout << "\n\n Bomb Remove called for Player 0 bomb_count : " << bomb_count[0];
				remove_bomb(1);
				Sleep(250);
				bomb_count[0] --;
			
		}
		else {
			cout << "\nTotal bomb count is not above 0: " << total_bomb_count;
		}
		
	}

	if (KEY('L')) player_x_co[1] += m;
	if (KEY('L')) player_orientation[1] = 0.0;

	if (KEY('J')) player_x_co[1] -= m;
	if (KEY('J')) player_orientation[1] = 180.0;

	if (KEY('I')) player_y_co[1] += m;
	if (KEY('I')) player_orientation[1] = 90.0;

	if (KEY('K')) player_y_co[1] -= m;
	if (KEY('K')) player_orientation[1] = 270.0;
	
	if (KEY('M')){
		if (bomb_count[1] < 3) {
			new_bomb(1);
		}
	}

	for (i = 0; i < n_player; i++) {
		pointer_player[i]->set_x_co(player_x_co[i]);
		pointer_player[i]->set_y_co(player_y_co[i]);
		pointer_player[i]->set_orientation(player_orientation[i]);
	}

};


World::World(int n_player, int map_type) {
	//cout << "\nConstructor to initialize the World";
	//getchar();

	int i,j;
	int m = 3;
	int grey_count = 0;
	
	this->n_player = n_player;
	this->map_type = map_type;

	pointer_map = new map();

	if (pointer_map == NULL) {
		cout << "\nallocation error in pointer_map";
		return;
	}

	n_grey_bricks = pointer_map->n_grey_bricks;
	n_red_bricks = pointer_map->n_red_bricks;

	player_x_co = new double [n_player];
	player_y_co = new double[n_player];
	player_orientation = new double[n_player];
	

	if (player_x_co == NULL) {
		cout << "\nallocation error in player_x_co";
		return;
	}
	if (player_y_co == NULL) {
		cout << "\nallocation error in player_y_co";
		return;
	}
	if (player_orientation == NULL) {
		cout << "\nallocation error in player_orientation";
		return;
	}
	

	for (i = 0; i < n_player; i++) {

		pointer_player[i] = new player(i);
	
		if (pointer_player[i] == NULL) {
			cout << "\nallocation error in pointer_player";
			return;
		}
		
		player_x_co[i] = pointer_player[i]->get_x_co();
		player_y_co[i] = pointer_player[i]->get_y_co();
		player_orientation[i] = pointer_player[i]->get_orientation();

		pointer_player[i]->player_x_co = player_x_co[i];
		pointer_player[i]->player_y_co = player_y_co[i];
		pointer_player[i]->player_orientation = player_orientation[i];
		
		//cout << player_x_co[i] <<" " <<player_y_co[i] << " " << player_orientation[i] << "\n";
	}

	// calls bomb constructor x30. Allocates memory for an array of "N_max_bombs" possible bombs
	//Creates dynamic array of pointers to Bomb objects
	for (i = 0; i < N_max_bombs; i++) {
		//cout << "\nBomb ID = " << bomb_id << " in  bomb constructor # " << i;
		pointer_bomb[i] = new bomb(bomb_id);
		bomb_id++;
		
		if (pointer_bomb[i] == NULL) {
			cout << "\nAllocation error in pointer_bomb";
			getchar();
			return;
		}

	}

	
	// initializes bomb_count for each player to 0
	bomb_count = new int[n_player];

	for (i = 0; i < n_player; i++) {
		bomb_count[i] = 0;

		if (pointer_bomb[i] == NULL) {
			cout << "\nAllocation error in pointer_bomb";
			getchar();
			return;
		}

		
	}
	

	//cout << "check constructor 2";
	/*
	for (i = 0; i < n_player; i++) {
		player_x_co[i] = pointer_player[i]->player_x_co;
		player_y_co[i] = pointer_player[i]->player_y_co;
		player_orientation[i] = 270;
	}
	cout << "check constructor 3";
	*/

	//Initializes coordinates of grey squares for checker board pattern
	//for (i = 0; i < 7; i++) {
	//	xc_grey[i] = 105 + 84 * i;
	//	yc_grey[i] = 105 + 84 * i;

	//}
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			xc_grey[grey_count] = 105 + 84 * i;
			yc_grey[grey_count] = 105 + 84 * j;
			grey_count++;
		}
		
	}
	for (i = 0; i < 17; i++) {
		xc_grey[grey_count] = 21 + 42 * i;
		yc_grey[grey_count] = 21;
		grey_count++;
	}
	for (i = 0; i < 17; i++) {
		xc_grey[grey_count] = 21 + 42 * i;
		yc_grey[grey_count] = 693;
		grey_count++;
	}
	for (i = 0; i < 16; i++) {
		xc_grey[grey_count] = 21 ;
		yc_grey[grey_count] = 21 + 42 * i;
		grey_count++;
	}
	for (i = 0; i < 16; i++) {
		xc_grey[grey_count] = 693; 
		yc_grey[grey_count] = 21 + 42 * i;
		grey_count++;
	}
	

	//cout << "\n grey count: " << grey_count;
	//getchar();

	xc_red = new double[164];
	yc_red = new double[164];
	
	// Initializes coordinates of red squares
	for (i = 0; i < 164; i++) {
		xc_red[i] = pointer_map->x_red_bricks[i];
		yc_red[i] = pointer_map->y_red_bricks[i];

		
	}
	
	// generate map for collision

	double x;
	double y; 
	int k;
	
	xmax = width - xmin;
	ymax = width - ymin;
	
	for (i = 0; i < N_map; i++)
	{
		for (j = 0; j < M_map; j++)
		{
			// creates collision matrix
			x = xmin + i * dx;
			y = ymin + j * dy;

			//loop for marking sectors containing grey bricks
			for (k = 0; k < grey_count; k++)
			{
				
					// checks if sector is occupied by grey brick, marks with 1
					if ((x == xc_grey[k]) && (y == yc_grey[k])) {
						Grey.e(i, j) = 1;

					}
				
			}
		
			//loop for marking sectors containing red bricks
			for (k = 0; k < 164; k++)
			{
				// checks if sector is occupied by red brick, marks with 2
				if ((x == xc_red[k]) && (y == yc_red[k])) {
						Grey.e(i, j) = 2;
				
				}
			}

		}
	}
};

World::~World() {
	int i;

	for (i = 0; i < n_player; i++) {

		// safe delete
		if (pointer_player[i] == NULL) {
			cout << "\nerror in ~World";
			break; 
		}
		else {
			delete pointer_player[i];
			pointer_player[i] = NULL;
		}
	}

	// safe delete
	if (pointer_map == NULL) {
		cout << "\nerror in ~World";
	}
	else {
		delete pointer_map;
		pointer_map = NULL;
	}

	if (player_x_co == NULL) {
		cout << "\nerror in ~World";
		return;
	}
	else {
		delete player_x_co;
		player_x_co = NULL;

	}
	if (player_y_co == NULL) {
		cout << "\nerror in ~World";
		return;
	}
	else {
		delete player_y_co;
		player_y_co = NULL;

	}
	if (player_orientation == NULL) {
		cout << "\nerror in ~World";
		return;
	}
	else {
		delete player_orientation;
		player_orientation = NULL;

	}

	for (i = 0; i < total_bomb_count; i++) {

		// safe delete
		if (pointer_bomb[i] == NULL) {
			cout << "\nerror in ~World";
			break;
		}
		else {
			delete pointer_bomb[i];
			pointer_bomb[i] = NULL;
		}
	}

		
};

//Check for collisions with map, provides response
void World::collision_map() {
	double x;
	double y;
	double is, js;
	int i,i_index, j_index;
	int x_shift = 5;
	int y_shift_down = 22;
	int y_shift_up = 20;
	

	
	// tests each players position vs index
	for (i = 0; i < n_player; i++)
	{
		x = pointer_player[i]->player_x_co;
		y = pointer_player[i]->player_y_co;
	
	
	// corrects for player/square overlap of sprites
		if (player_orientation[i] == 0.0) {
			x += x_shift;
		}
		if (player_orientation[i] == 90.0) {
			y += y_shift_up;
		}
		if (player_orientation[i] == 180.0) {
			x -= x_shift;
		}
		if (player_orientation[i] == 270.0) {
			y -= y_shift_down;
		}

		//coordinate test
		//if (i==0)cout << "\n player #" << i << " x coord is: " << player_x_co[i];
		//if (i==0) cout << "\n player #" << i << " y coord is: " << player_y_co[i];

		//player location index as double
		is = (x - xmin) / dx;
		js = (y - ymin) / dy;

		//player index as int
		i_index = (int)(is + 0.5);
		j_index = (int)(js + 0.5);

		//index test
		//if (i==0) cout << "\n player #" << i << " i_index is: " << i_index;
		//if (i==0) cout << "\n player #" << i << " j_index is: " << j_index;

		
		// Motion impeding response: If player index matches grey brick, input command is reversed for that player
		if (Grey.e(i_index, j_index) == 1) {
		
			//cout << "\n grey brick collision detected";
			//cout << "\n player #" << i << " x coord is: " << player_x_co[i];
			//cout << "\n player #" << i << " y coord is: " << player_y_co[i];
			//cout << "\n player #" << i << " i_index is: " << i_index;
			//cout << "\n player #" << i << " j_index is: " << j_index;
			//cout << "\n player #" << i << " orientation is: " << player_orientation[i];
			reverse_input(i);
		
		}

		// player/red brick response: if player index matches red brick index, input command is reversed for that player
		if (Grey.e(i_index, j_index) == 2) {
			
			//cout << "\n red brick collision index is " << i_index << "," << j_index;
			cheat_remove_red_brick(i_index, j_index);

			

			reverse_input(i);
			
		}
		if (Grey.e(i_index, j_index) == 3) {

			//cout << "\n bomb collision index is " << i_index << "," << j_index;
			//remove_red_brick(i_index, j_index);



			reverse_input(i);

		}
		
		
	}
	


}

// Reverses input command in case of collision
void World::reverse_input(int i) {
	int j;
	int m = -3; // step size movement
	// player input

	//cout << "check input 1";

	if ((KEY('D')) && (i == 0)) player_x_co[0] += m;
	if ((KEY('D')) && (i == 0)) player_orientation[0] = 0.0;

	if ((KEY('A')) && (i == 0)) player_x_co[0] -= m;
	if ((KEY('A')) && (i == 0)) player_orientation[0] = 180.0;

	if ((KEY('W')) && (i == 0)) player_y_co[0] += m;
	if ((KEY('W')) && (i == 0)) player_orientation[0] = 90.0;

	if ((KEY('S')) && (i == 0)) player_y_co[0] -= m;
	if ((KEY('S')) && (i == 0)) player_orientation[0] = 270.0;


	if (KEY('L') && (i == 1)) player_x_co[1] += m;
	if (KEY('L') && (i == 1)) player_orientation[1] = 0.0;

	if (KEY('J') && (i == 1)) player_x_co[1] -= m;
	if (KEY('J') && (i == 1)) player_orientation[1] = 180.0;

	if (KEY('I') && (i == 1)) player_y_co[1] += m;
	if (KEY('I') && (i == 1)) player_orientation[1] = 90.0;

	if (KEY('K') && (i == 1)) player_y_co[1] -= m;
	if (KEY('K') && (i == 1)) player_orientation[1] = 270.0;


	for (j = 0; j < n_player; j++) {
		pointer_player[j]->set_x_co(player_x_co[j]);
		pointer_player[j]->set_y_co(player_y_co[j]);
		pointer_player[j]->set_orientation(player_orientation[j]);
	}

}