#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"

int x = 0;
int y = 0;
int tk1 = 0;	//timekeeper 1
char position = 2; 
char holding;
char lastinput;
int obstacle_pos = 128;

void update_movement ( void ){
	return;
}

void update_graphic( void ){
	display_car(position);
	display_obstacle( 1, obstacle_pos );
	buffer2display();
		
}

int collision_check( void ){
	
}

void user_isr ( void ){
	IFS(0) = 0;
	if(activity){
		update_graphic();	
		update_movement();
	}
}