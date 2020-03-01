/*
	Spelet styrs här ifrån. När spelet startar kommer man till en meny och
*/

#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"

char difficulty = 0;

void set_difficulty(int setting);



/*	Caller by user_isr when a crash happens */
void crash ( void ){
	screen_clear();
	buffer_clear();
	display_explosion();
	buffer2display();
	DISPLAY_SET_TO_COMMAND_MODE;
	int i;
	for(i = 0; i < 8; ++i){
		spi_send_recv(0xA7);
		delay(200000);
		spi_send_recv(0xA6);
		delay(200000);
	}	

	display_string(0, ">   YOU DIED   <");
	display_string(1, ">              <");
	display_string(2, ">     PUSH 1   <");
	display_string(3, ">  TO CONTINUE <");
	display_update();
	while(1){
		if(BUTTON_1){
			while(BUTTON_1){}
			need2pee();
		}			
	}
	
}


/*	Function called by main	*/
void need2pee ( void ) {
	get_highscore(objects_passed);
	main_menu();
	
}


void set_difficulty( int setting ){
	difficulty = setting;
}

