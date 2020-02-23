#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"


int main(void) {
	setup_chipkit();

	display_init();	
	graphics_init();

	timerinit();
	buttonsinit();
	interruptinit();
	
	need2pee();

		
	for(;;) ;
	return 0;
}

