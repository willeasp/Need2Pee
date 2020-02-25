/* 
	Fil som gör att main.c kan hitta funktionen need2pee
*/

#define BUTTON_4 PORTD & (1 << 7)	// Up	/	Left
#define BUTTON_3 PORTD & (1 << 6)	// Down
#define BUTTON_2 PORTD & (1 << 5)	// Enter	/	Right
#define BUTTON_1 PORTF & 2			// Back

#define DISPLAY_CHANGE_TO_COMMAND_MODE (PORTFCLR = 0x10)
#define DISPLAY_CHANGE_TO_DATA_MODE (PORTFSET = 0x10)

/*
	Globala variabler
*/
extern int highest_score;
extern int last_game;
extern int game_on;

/*
	Funktioner för spelet
*/	
void need2pee ( void );
void start_game( void );
void main_menu ( void );
void options_menu ( void );
void set_difficulty ( int setting);
void highscore ( void );


/*
	Funktioner för grafik
*/
void display_intarray( uint32_t a[] );
void graphics_init ( void );
void buffer2display ( void );
int randnr ( int max );
void point2buffer ( int x, int y );
void display_car ( int page );
void display_obstacle ( int page, int x );
void buffer_clear( void );
void screen_clear( void );

extern uint32_t frame[128];
extern const uint8_t const car[13];
extern const uint8_t const obstacle[14];
// extern struct Obstacle;


/*	interrupts */
void user_isr ( void );



/*	testing	*/
void test_game_no_interrupts(void);
