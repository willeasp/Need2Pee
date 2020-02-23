/* 
	Fil som gör att main.c kan hitta funktionen need2pee
*/

/*
	Funktioner för spelet
*/
void need2pee ( void );


/*
	Funktioner för grafik
*/
void display_frame( void );
void graphics_init ( void );
void buffer2display ( void );
int randnr ( int max );


/*	interrupts */
void user_isr ( void );
extern int activity;
extern int which_menu;
extern int menu_select;