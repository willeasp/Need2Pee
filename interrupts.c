#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"

int tk1 = 0;	//timekeeper 1
char car_pos = 2; 
char holding;
char lastinput;
int obstacle_init = 128;

#define bit1 car_pos & 2;	// bits in car_pos for movement logic
#define bit0 car_pos & 1;

struct Obstacle{
	int x;	// -14 - 128
	int y; // 0 - 3
}


void update_graphic( void ){
	display_car(car_pos);
	display_obstacle( randnr(4), obstacle_pos );
	buffer2display();
	obstacle_pos();
		
}

void update_movement ( void ){
	// Flyttar bilen och flyttar objekten
	// bit 1 i car_pos
	if((car_pos & 1)&() | ())
}


int collision_check( void ){
	return;
}

void user_isr ( void ){
	IFS(0) = 0;
	update_graphic();	
	update_movement();
}