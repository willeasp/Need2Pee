/* 
	Fil som gör att main.c kan hitta funktionen need2pee
*/
#include <pic32mx.h>

#define BUTTON_4 (PORTD >> 7) & 1	// Up	/	Left
#define BUTTON_3 (PORTD >> 6) & 1	// Down
#define BUTTON_2 (PORTD >> 5) & 1	// Enter	/	Right
#define BUTTON_1 (PORTF >> 1) & 1			// Back

#define DISPLAY_SET_TO_COMMAND_MODE (PORTFCLR = 0x10)
#define DISPLAY_SET_TO_DATA_MODE (PORTFSET = 0x10)

/*
	Globala variabler
*/
extern int highest_score;
extern int last_game;
extern int points;
extern char char_highscore[];  // plats för char array som används för highscore och last game score.
extern char char_lasttry[]; 

/*
	Funktioner för spelet
*/	
void need2pee ( void );
void start_game( void );
extern char game_on;
void init_objects( void );
extern char difficulty;
extern int objects_passed;
void init_variables ( void );
void crash ( void );
void get_highscore(int points);


/*
	Funktioner för menyer
*/
void main_menu ( void );
void options_menu ( void );
void set_difficulty ( int setting);



/*
	Funktioner för grafik
*/
void display_intarray( uint32_t a[] , int arr_length , char shift_x );
void graphics_init ( void );
void buffer2display ( void );
int randnr ( int max );
void point2buffer ( int x, int y );
void display_car ( void );
void display_obstacle ( int page, int x, int ON );
void buffer_clear( void );
void screen_clear( void );
void display_explosion ( void );
void car_slide_init ( void );
void display_road ( void );


extern uint32_t road[8];
extern const uint8_t const car[13];
extern const uint8_t const obstacle[13];
extern uint32_t explosion[32];
extern char car_shift;
extern uint32_t car_slide[13];
extern uint32_t lambo[128];

extern int car_pos;
extern char Rhold;		// Boolean Holding button 2
extern char Lhold;		// Boolean Holding button 4
extern char x;
extern char obstacle_speed_x;
extern int time_until_next_obstacle;		// interruptcycles til next object comes 
extern char obstaclecount;		// for startup of objects
extern char collision_true;
extern char game_on;
extern char car_shift;		// 0 = no movement, 1 = left, 2 = right
extern char car_shift_position;
extern char slide_amt;					// slides car 



/*	spel	*/
// extern struct Obstacle;
typedef struct{
	int page;
	int x;
	int ON;	
	char speed_offset;
} Obstacle;


/*	interrupts */
void user_isr ( void );



/*	testing	*/
void test_game_no_interrupts(void);
