/* 
	Fil som gör att main.c kan hitta funktionen need2pee
*/

/*
	Funktioner för spelet
*/
void need2pee ( void );
void start_game( void );


/*
	Funktioner för grafik
*/
void display_intarray( uint32_t a[] );
void graphics_init ( void );
void buffer2display ( void );
int randnr ( int max );
void point2buffer ( int x, int y );
extern uint32_t frame[128];


/*	interrupts */
void user_isr ( void );
extern int activity;
extern int which_menu;
extern int menu_select;