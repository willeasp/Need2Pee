#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"


int tk1 = 0;	//timekeeper 1
int car_pos = 1; 
char Rhold = 0;		// Boolean Holding button 2
char Lhold = 0;		// Boolean Holding button 4
char x = 0;


/* struct Obstacle{
	int x;	// -14 - 128
	int y; // 0 - 3
} */


void update_graphic( void ){
	buffer_clear();
	display_car(car_pos);
	point2buffer(x++, 24);
	buffer2display();	
	if(x == 127)
		x = 0;
}

/*
	Left: Button 4
	Right: Button 2
*/
void update_movement ( void ){
	// Moves car and moves objects
	//	Car:
		
	if(!BUTTON_2)
		Rhold = 0;			
	if(!BUTTON_4)
		Lhold = 0;
	if((BUTTON_2 & !Rhold) & (car_pos < 3)){
		Rhold = 1;
		++car_pos;
	}
	if((BUTTON_4 & !Lhold) & (car_pos > 0)){
		Lhold = 1;
		--car_pos;
	}
}


int collision_check( void ){
	return;
}

void user_isr ( void ){
	IFS(0) = 0;
		
	update_movement();
	update_graphic();
	
}