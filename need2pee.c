/*
	Spelet styrs här ifrån. När spelet startar kommer man till en meny och
*/

#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"


void main_menu ( void ){
	//display_frame();
	//buffer2display();
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
