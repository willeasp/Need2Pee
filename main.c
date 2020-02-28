#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"


int main(void) {
	setup_chipkit();	// startup setting

	display_init();		// startup routine for display
	graphics_init();	// draws and
	

	buttonsinit();
	timerinit();

	/* välj vilket som ska köras för test */

	// test_game_no_interrupts();
	
	//start_game();
	need2pee();
	//highscore();
		
	for(;;) ;
	return 0;
}

