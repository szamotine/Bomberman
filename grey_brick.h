

class grey_brick
{
private:
	
	// store the red bricks image name for ease of use 
	char* grey_bricks = "grey_bricks.png";

	//coordinates
	double x_coordinate;
	double y_coordinate;

	//store image sprite id
	int bricks_sprite_id;

	//stores the bricks index
	int i_index = 0, j_index = 0;



public:

	// bricks angle 
	static constexpr double brick_angle = 0.0;

	// bricks_scale
	static constexpr double brick_scale = 1.0;

	void draw();

	grey_brick(double x, double y);

	~grey_brick();

};