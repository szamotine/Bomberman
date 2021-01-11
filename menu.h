// structure of the menu:

// loading screen with title for 3 sec and music kicking in
// menu with options:
//	-play locally
//	-play online 
//	-settings 

// play locally gives the world function inidication to only use the keyboard controls 

// play online gives the world function indication for one player on keyboard and others online 
// might need to ask for ip at this point 

// settings has: 
//	- music volume 
//	- sounds volume 



class menu {

public:
	// store the background image name for ease of use 
	char background[15] = "background.png";

	char background_2[17] = "background_2.png";

	char title[10] = "title.png";

	char logo[9] = "logo.png";

	// number of players
	int player_number; 

	// score for each player while in game
	double x_player_title[3]; 
	double y_player_title[3];

	double x_title = 357;
	double y_title = 764; 
	double q_title = 0; 
	double scale_title = 0.1; 

	double x_logo = 357;
	double y_logo = 457;
	double q_logo = 0;
	double scale_logo = 0.18;

	// background coordinates to have a background image
	double x_background, y_background, q_background, scale_background;

	// store the images sprite ids
	int background_sprite_id, background_2_sprite_id, title_sprite_id,logo_sprite_id;

	// menu selection strings

	char str_local[9] = "Local";
	char str_online[9] = "Online";
	char str_settings[9] = "Settings";

	char str_back[7] = "Back";

	char str_sound[9] = "Sound";
	char str_volume[10] = "Volume";

	char str_player_number[18] = "Number of Players";

	bool game_state = false; 

	bool local_game = false; 
	bool online_game = false;

	// function that blocks the program to the menu to have the player choose a few parameters
	// mainly number of players, sound on or off and volume, local or online game 
	// if online might be interesting to ask for the IP address there
	void menu_selection(); 

	void settings();

	void local(); 

	void online();

	char input(); 

	bool check();

	// function to draw a rectangle
	void rectangle(double x, double y, double Lx, double Ly,
		double r, double g, double b);

	void loading_screen(); 

	menu(); 

	// destructor 
	~menu();


};