//This class has for purpose to: 
//	-create the red brick skin 
//	-store the red brick coordinates 
//	

class red_brick {

public:

	// stores the number of red bricks
	int n_red_bricks;
	
	// store the images sprite id
	int red_bricks_sprite_id;

	// store the red bricks image name for ease of use 
	char red_bricks[15] = "red_bricks.png";
	
	// pointers to store coordinates of red bricks
	double *x_red_bricks, *y_red_bricks;

	//stores the red bricks index
	int i_index=0, j_index=0;
		
	// bricks angle 
	double bricks_angle = 0.0;

	// bricks_scale
	double bricks_scale = 1.0;

	//constructor to initialize red brick object
	red_brick();

	//deconstructor for red bricks
	~red_brick();

	//constructor to generate red bricks
	red_brick(double x, double y);

	//this function is called after the map generation and fills the gaps with red bricks
	void red_bricks_draw();

	void red_bricks_initialization();


};