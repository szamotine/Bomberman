



const int N_PLAYER_MAX = 4;


const int N_max_bombs = N_PLAYER_MAX*3;

const int N_max_red_bricks = 200;


class World {

public:

	// number of players (max of 4)
	int n_player; 

	// Use an int to indicate which map generation (basic or random)
	int map_type; 

	//pointers to player coordinates and orientation
	double* player_x_co;
	double* player_y_co;
	double* player_orientation;

	// array of pointers to player objects
	player* pointer_player[N_PLAYER_MAX];

	// number of grey bricks for check pattern 
	int n_grey_bricks;

	// array of pointers to red brick objects;
	red_brick* pointer_red_brick [N_max_red_bricks];

	// number of red bricks for check pattern 
	int n_red_bricks;

	// single array of pointers to map objects
	map* pointer_map;

	//pointer to a red brick objects
	red_brick* pointer_rb;

	// array of bomb objects
	bomb* pointer_bomb[N_max_bombs];

	//tracker for number of bombs for player max bomb count
	int *bomb_count;

	int total_bomb_count=0;

	int bomb_id;
	
	// Array of Grey brick coordinates
	double xc_grey[115] = { 0 }, yc_grey[115] = { 0 };

	// red brick coordinates
	double *xc_red, *yc_red;
		

	// Collision Matrix for grey bricks
	static iMatrix Grey;
	
	double xmin=21, xmax, dx=42;
	double ymin=21, ymax, dy=42;

	void draw();

	void sim_step();

	void input();

	void collision_map();

	void reverse_input(int i);

	void remove_red_brick(int i_index, int j_index);

	void cheat_remove_red_brick(int i_index, int j_index);
	
	void remove_player(int i);

	World(int n_player,int map_type);

	void new_bomb(int player_number);

	void bomb_index(int player_number, double player_x_co, double player_y_co);

	void remove_bomb(int bomb_id);

	boolean bomb_collision(double x, double y);

	~World();

};
