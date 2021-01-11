//This class is for: 
//	-create the bomb skin 
//	-store the bomb coordinates 


//	test_branch_1 merge



const int N = 4;


class bomb {

public: 

	// store the bomb image name for ease of use 
	char bomb_ch[9] = "bomb.png";

	// bomb x coordinates 
	double bomb_x_co;

	// bomb y coordinates 
	double bomb_y_co;
	
	//bomb angle 
	double bomb_angle=0;

	//sprite scale
	double bomb_sprite_scale = 1;

	//sprite ids
	int bomb_sprite_id;

	//bomb id number for array location
	int bomb_id;

	//store index location for matrix
	int i_index, j_index;
		
	void draw_bomb();
	void end_bomb();
	

	//constructor
	bomb(int bomb_id);


	//constructor to initialize the bomb position and skin 
	//bomb(double player_x_co, double player_y_co);

	//deconstructor 
	~bomb();

};
