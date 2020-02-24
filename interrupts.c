#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"

int x = 0;
int y = 0;
int tk1 = 0;	//timekeeper 1

void user_isr ( void ){
	IFS(0) = 0;
	if(activity){
		//display_intarray(frame);
		point2buffer(x, y);
		buffer2display();
		x++;
		if(x == 7){
			x = 0;
			y++;
			if(y == 7)
				y = 0;	
		}
			
	}
}