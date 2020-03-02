/*	File written 2020 by William Asp	*/

#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"


int main(void) {
	setup_chipkit();	// startup setting

	display_init();		// startup routine for display
	
	buttonsinit();
	timerinit();
	interruptinit();
	
	graphics_init();

	display_intarray(lambo, 128, 0);
	buffer2display();

	delay(20000000);

	/* välj vilket som ska köras för test */

	// test_game_no_interrupts();
	
	//start_game();
	need2pee();
	//highscore();
		
	for(;;) ;
	return 0;
}

