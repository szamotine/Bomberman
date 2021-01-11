
class map {

public: 
	
	// store the background image name for ease of use 
	char background[15] = "background.png";

	// store the grey bricks image name for ease of use
	//the grey bricks should be indestructible 
	char grey_bricks[16] = "grey_bricks.png";

	// store the red bricks image name for ease of use 
	// the red bricks should be destroyable
	char red_bricks[15] = "red_bricks.png";

	// store the images sprite ids
	int background_sprite_id;
	int grey_bricks_sprite_id;
	int red_bricks_sprite_id;

	// background coordinates to have a background image
	double x_background, y_background, q_background, scale_background;

	// bricks angle 
	double bricks_angle = 0.0;

	// bricks_scale
	double bricks_scale = 1.0;

	// buffer to create the map 
	double* x_buffer, * y_buffer;

	// number of grey bricks for check pattern 
	int n_grey_bricks; 

	// grey_bricks coordinates
	double* x_grey_bricks, * y_grey_bricks;

	// number of red bricks
	int n_red_bricks; 

	// red_bricks coordinates
	double* x_red_bricks, * y_red_bricks;

	// random_map and basic_map are creating the grey brick layout
	// random base itself on a random generation 
	// basic base itself on a prebuilt model
	void random_map();
	void basic_map();

	// this function is called after the map generation and fills the gaps with red bricks
	void red_bricks_generation();

	//constructor to initialize the player position and skin 
	map();

	//deconstructor 
	~map();


};