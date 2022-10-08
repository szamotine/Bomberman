class brick {

private:

	//coordinates
	double x_coordinate;
	double y_coordinate;

	//store image sprite id
	int bricks_sprite_id;

	//stores the bricks index
	int i_index = 0, j_index = 0;

	// bricks angle 
	double bricks_angle = 0.0;

	// bricks_scale
	double bricks_scale = 1.0;


public:

	//constructor to initialize brick
	brick(double x, double y);

	//destructor for bricks
	~brick();




};