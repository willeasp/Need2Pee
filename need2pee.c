/*
	Spelet styrs här ifrån. När spelet startar kommer man till en meny och
*/

#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"

char difficulty = 1;

void set_difficulty(int setting);

void start_game ( void ){
	
	graphics_init();
	
	init_objects();

	init_variables();
	
	for(;;);
}

/*	Caller by user_isr when a crash happens */
void crash ( void ){
	screen_clear();
	buffer_clear();
	display_explosion();
	buffer2display();
	delay(10000000);
	display_string(1, "    YOU DIED");
	display_string(2, "     loser");
	display_update();
	while(1){
		display_string(3, "Press 1 restrt");
		display_update();
		if(BUTTON_2){
			display_string(0, "Start game initiated");
			display_update();
			delay(1000000);
			start_game();
		}
			
	}
	
}


/*	Function called by main	*/
void need2pee ( void ) {
	get_highscore(points);
	main_menu();
	
}


void set_difficulty( int setting ){
	display_string(0, "Set difficulty");
	display_update();
}

