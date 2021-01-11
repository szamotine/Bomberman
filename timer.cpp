
#include <iostream>
#include <cstdio>
#include <cmath>
#include <Windows.h>
#include <time.h>
#include "2D_graphics.h"

#include "timer.h"
#include "ran.h"
#include "player.h"
#include "map.h"
#include "menu.h"


using namespace std;

int main() {

	// time


	unsigned long sec = 0;
	int total_time = 0;
	int countdown_timemax = 3;
	int time_left = 3;
	clock_t start, count;

	start = clock();

	while (time_left > 0) {
		count = clock();
		sec = ((count - start)/ (CLOCKS_PER_SEC));
		time_left = countdown_timemax - sec;
		cout << time_left<<"\n"; 
	}
	}