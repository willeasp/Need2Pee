/*
	Spelet styrs här ifrån. När spelet startar kommer man till en meny och
*/

#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"

#define BUTTON_4 PORTD & (1 << 7)	// Up	/	Left
#define BUTTON_3 PORTD & (1 << 6)	// Down
#define BUTTON_2 PORTD & (1 << 5)	// Enter	/	Right
#define BUTTON_1 PORTF & 2			// Back

int activity = 0;		// 0 = menu, 1 = game
int which_menu = 0;
int menu_select = 0;

void options_menu (void);
void set_difficulty(int setting);
int get_input(void);

void start_game ( void ){
	interruptinit();
	activity = 1;

	for(;;);
}


void main_menu (void){
	int select;

	display_string(0, "Highscore:");
	display_string(1, "Last game");
	display_string(2, "Start");
	display_string(3, "Options");
	display_update();
	
	display_image(96, icon);

	

	while(1){
		select = get_input();
		switch(select){
			case 1:{
				display_string(0, "Up");
				display_update();
			}				
			case 2:{
				display_string(0, "Down");
				display_update();
			}				
			case 3:{
				display_string(0, "Enter");
				display_update();
			}				
			case 4:{
				display_string(0, "Back");
				display_update();
			}					
			default:{
				display_string(0, "Too many arguments");
				display_update();
			}				
		}
	}
}

void options_menu (void) {

	display_string(0, "Difficulty:");				
	display_string(1, "Easy");						
	display_string(2, "Hard");						
	display_string(3, "Extreme");
	display_update();

while(1){
		if(BUTTON_4){
			display_string(0, "Up");
			display_update();
			while(BUTTON_4){}			
		}		
		if(BUTTON_3){
			display_string(0, "Down");
			display_update();
			while(BUTTON_3){}			
		}		
		if(BUTTON_2){
			display_string(0, "Enter");
			display_update();
			while(BUTTON_2){}			
		}
		if(BUTTON_1){
			display_string(0, "Back");
			display_update();
			main_menu();
			while(BUTTON_1){}			
		}
	}
}

void hello ( void ){
	display_string(0, "goddag");
	display_string(1, "i stugan");
	display_string(2, "->");
	display_string(3, "wowza");
	display_update();
	
	display_image(96, icon); 
}


/*	Function called by main	*/
void need2pee ( void ) {
	main_menu();
	
}


void set_difficulty( int setting ){
	display_string(0, "Set difficulty");
	display_update();
}

int get_input(void){
	int i;
	while(1){
		if(getbtns()){
			i = getbtns();
			return i;
		}			
	}
}