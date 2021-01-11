//This class has for purpose to: 
//	-create the player skin 
//	-store the player coordinates 
//	-move the player on the map

extern int start_pos[4];
extern int n_objects;

class player {

public: 

	// declare and store the 4 possible start position in array 
	// they correspond to each corner of the map 
	double start_x_co[4] = {63.0,651.0,63.0,651.0};
	double start_y_co[4] = {63.0,63.0,651.0,651.0};
	
	//player x coordinates
	double player_x_co;

	//player y coordinates
	double player_y_co;


	
	//player angle 
	double player_angle=0;

	//sprite scale
	double player_spirte_scale = 0.67;

	//player orientation
	double player_orientation; 



	//sprite ids
	int bottom_sprite_id;
	int top_sprite_id;
	int left_sprite_id;
	int right_sprite_id;
	//int bomb;

	double get_x_co(); 
	double get_y_co(); 
	double get_orientation();

	void set_x_co(double value);
	void set_y_co(double value);
	void set_orientation(double value);


	// function to choose the start position of the player 
	int start_picker();

	//function to draw the player skin
	void draw_player();

	//constructor to initialize the player position and skin 
	player(int n_player);

	//deconstructor 
	~player();

};
