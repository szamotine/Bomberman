#pragma once

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

static char* PLAYER_1_SPRITE_NAMES[4] = { PLAYER_RIGHT, PLAYER_TOP,PLAYER_LEFT,PLAYER_BOTTOM };
static char* PLAYER_2_SPRITE_NAMES[4] = { PLAYER2_RIGHT, PLAYER2_TOP,PLAYER2_LEFT,PLAYER2_BOTTOM };
static char* PLAYER_3_SPRITE_NAMES[4] = { PLAYER3_RIGHT, PLAYER3_TOP,PLAYER3_LEFT,PLAYER3_BOTTOM };
static char* PLAYER_4_SPRITE_NAMES[4] = { PLAYER4_RIGHT, PLAYER4_TOP,PLAYER4_LEFT,PLAYER4_BOTTOM };




// declare and store the 4 possible start position in array 
// they correspond to each corner of the map 
static constexpr double start_x_co[4] = { 63.0,651.0,63.0,651.0 };
static constexpr double  start_y_co[4] = { 63.0,63.0,651.0,651.0 };


class player
{
private:
	double x_coordinate;
	double y_coordinate;
	double orientation;

	double player_angle = 0;
	double player_sprite_scale = 0.67;
	
	//sprite ids array -> {right, top, left, bottom}
	int* sprite_id;

	// delay bomb drop
	double bomb_time;
	bool bomb_flag;

public:

	player(int player_number);
	~player();

	double get_x_coordinate();
	double get_y_coordinate();
	double get_orientation();
	double get_angle();
	double get_scale();
	int get_sprite_id();
	bool get_bomb_flag();

	double get_bomb_time();

	void set_x_coordinate(double value);
	void set_y_coordinate(double value);
	void set_orientation(double value);
	void set_scale(double value);
	void set_bomb_time(double value);
	void set_bomb_flag(bool flag);

	void initialize_sprites(int player_number);

	void move_player_x(double value);
	void move_player_y(double value);

};

