
extern int start_pos[4];

static int n_objects = 0;

// declare and store the 4 possible start position in array 
// they correspond to each corner of the map 
static double start_x_co[4] = { 63.0,651.0,63.0,651.0 };
static double start_y_co[4] = { 63.0,63.0,651.0,651.0 };

//player sprite file names
static  char* PLAYER_BOTTOM = "player_bottom.png";
static  char* PLAYER_TOP = "player_top.png";
static  char* PLAYER_LEFT = "player_left.png";
static  char* PLAYER_RIGHT = "player_right.png";

static  char* PLAYER2_BOTTOM = "player_bottom_2.png";
static  char* PLAYER2_TOP = "player_top_2.png";
static  char* PLAYER2_LEFT = "player_left_2.png";
static  char* PLAYER2_RIGHT = "player_right_2.png";

static  char* PLAYER3_BOTTOM = "player_bottom_3.png";
static  char* PLAYER3_TOP = "player_top_3.png";
static  char* PLAYER3_LEFT = "player_left_3.png";
static  char* PLAYER3_RIGHT = "player_right_3.png";

static  char* PLAYER4_BOTTOM = "player_bottom_4.png";
static  char* PLAYER4_TOP = "player_top_4.png";
static  char* PLAYER4_LEFT = "player_left_4.png";
static  char* PLAYER4_RIGHT = "player_right_4.png";

class player {

private:
	//player x coordinates
	double player_x_co{};

	//player y coordinates
	double player_y_co{};

	//player angle 
	double player_angle = 0;

	//sprite scale
	double player_sprite_scale = 0.67;

	//player orientation
	double player_orientation{};

	//sprite ids
	int bottom_sprite_id{};
	int top_sprite_id{};
	int left_sprite_id{};
	int right_sprite_id{};

public: 

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
