

class red_brick {

private:

	// store the red bricks image name for ease of use 
	char* red_bricks = "red_bricks.png";

	//Coordinates of the red brick object
	double x_coordinate;
	double y_coordinate;

	//store image sprite id
	int bricks_sprite_id;

	//stores the red bricks index
	int i_index{};
	int	j_index{};

public:

	// stores the number of red bricks
	int n_red_bricks;
	
	// store the images sprite id
	int red_bricks_sprite_id;

	
	// pointers to store coordinates of red bricks
	double* x_red_bricks;
	double* y_red_bricks;

	// bricks angle 
	static constexpr double brick_angle = 0.0;

	// bricks_scale
	static constexpr double brick_scale = 1.0;

	//constructor to initialize red brick object
	red_brick();

	//Draws a red brick
	void draw();

	//deconstructor for red bricks
	~red_brick();

	//constructor to generate red bricks
	red_brick(double x, double y);

	//this function is called after the map generation and fills the gaps with red bricks
	void red_bricks_draw();

};