#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"

void need2pee ( void ) {
	display_string(0, "goddag");
	display_string(1, "i stugan");
	display_string(2, "->");
	display_string(3, "wowza");
	display_update();
	
	display_image(96, icon); 
}

void main_menu ( void ){
	
}