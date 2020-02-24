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

void options_menu (void);
void set_difficulty(int setting);
int get_input(void);

void start_game ( void ){
/*	int i;
	DISPLAY_SET_TO_COMMAND_MODE;
	for(i = 0; i < 2){
		spi_send_recv(0xA7);
		delay(100000);
		spi_send_recv(0xA6);
		delay(100000);
	} */

int activity = 0;
	interruptinit();

	for(;;);
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