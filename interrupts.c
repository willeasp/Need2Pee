#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"

int counter;
void user_isr ( void ){
	counter++;
	if(counter == 100){
		randompageinvert();
		counter = 0;
	}
		
}