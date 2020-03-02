/*	File written 2020 by William Asp	*/

#include <pic32mx.h>
#include <stdint.h>
#include <stdlib.h>
#include "labresources.h"
#include "n2p.h"

#define DISPLAY_CHANGE_TO_COMMAND_MODE (PORTFCLR = 0x10)
#define DISPLAY_CHANGE_TO_DATA_MODE (PORTFSET = 0x10)

uint8_t displaybuffer[4][128];

uint32_t road[8];

uint32_t car_slide[13];

// sends intarray to displaybuffer
void display_intarray( uint32_t a[] , int arr_length , char shift_x ){
	int i, j, shift;
	shift = 8;
	for(i = 0; i<4; ++i){
		for(j = 0; j<arr_length; ++j){
			displaybuffer[i][j + shift_x] = displaybuffer[i][j + shift_x] | ((a[j] >> (shift * i)) & 0xFF);
		}
	}
}

void display_explosion ( void ){
	int i, j, shift;
	shift = 8;
	for(i = 0; i<4; ++i){
		for(j = 0; j<32; ++j){
			displaybuffer[i][j + 48] = displaybuffer[i][j + 48] | ((explosion[j] >> (shift * i)) & 0xFF);
		}
	}
}

void screen_clear( void ){
	int i, j, shift;
	shift = 8;
	for(i = 0; i < 4; i++) {
		DISPLAY_CHANGE_TO_COMMAND_MODE;
		spi_send_recv(0x22);		// set page address to write to
		spi_send_recv(i);			// page address to be written
		
		spi_send_recv(0x00);		// set lower nibble column start address
		spi_send_recv(0x00);		// set higher nibble column start address
		
		DISPLAY_CHANGE_TO_DATA_MODE;
		
		for(j = 0; j < 128; j++)
			spi_send_recv(0x00);
	}
}

void buffer_clear( void ){
	int i, j;
	for(i = 0; i<4; ++i){
		for(j = 0; j<128; ++j){
			displaybuffer[i][j] = 0x0;
		}
	}
}

void car_slide_init ( void ){
	int i;
	for(i = 0; i < 13; ++i){
		car_slide[i] = car[i];
		car_slide[i] = car_slide[i] << 12;
	}
}

void graphics_init ( void ){
	int i, j;

	/* blacken screen */
	screen_clear();

	/* init road */
	for(i = 0; i<3; ++i){
		road[i] = 0x81008081;
	}
	for(i = 3; i<8; ++i){
		road[i] = 0x80000001;
	}

	/* Blacken displaybuffer*/
	buffer_clear();

	/*	init car slide	*/
	car_slide_init();
}



// sends buffer to screen
void buffer2display ( void ){
	int i, j;
	
	for(i = 0; i < 4; i++) {
		DISPLAY_CHANGE_TO_COMMAND_MODE;
		spi_send_recv(0x22);		// set page address to write to
		spi_send_recv(i);			// page address to be written
		
		spi_send_recv(0x21);		// set higher nibble column start address
		spi_send_recv(0x0);
		spi_send_recv(0xFF);
		
		DISPLAY_CHANGE_TO_DATA_MODE;
		
		for(j = 0; j < 128; j++)
			spi_send_recv(displaybuffer[i][j]);
	}
}

void point2buffer (int x, int y){
	int page, shift;
	x = x % 128;
	y = y % 32;
	shift = 7 - (y % 8);
	if(y >= 0 & y < 8)
		page = 3;
	if(y >= 8 & y < 16)
		page = 2;	
	if(y >= 16 & y < 24)
		page = 1;
	if(y >= 24 & y < 32)
		page = 0;
	
	if(displaybuffer[page][x] & (0x1 << shift))
		displaybuffer[page][x] = displaybuffer[page][x] & ~(0x1 << shift);
	else
		displaybuffer[page][x] = displaybuffer[page][x] | (0x1 << shift);
}

int randnr ( int max ) {
   return TMR3 % max;      
}

// draws car on buffer

void display_car( void ){
	int i, page;
	/*	extreme difficulty	*/
	// car_shift: 0 = no movement, 1 = left, 2 = right
	if(difficulty){
		// shift left
		if(car_shift == 1){
			for(i = 0; i < 13; ++i){
				car_slide[i] = car_slide[i] >> slide_amt;
			}
		}
		// shift right
		if(car_shift == 2){
			for(i = 0; i < 13; ++i){
				car_slide[i] = car_slide[i] << slide_amt;
			}
		}
		display_intarray(car_slide, 13, 5);
	}
	else{
		/*	easy / hard difficulty*/
		for(i = 0; i < 13; ++i){
			displaybuffer[car_pos][i + 5] = car[i];
		}
	}

}

/*	if the car runs out of the screen, you start drawing the car
	from obstacle[abs(x)].
	if the car comes in at the far right, you don't draw anything if the car 
	is outside the screen	*/
void display_obstacle ( int page, int x, int ON ){
	if(ON && x < 128){
		int i;
		if(x < 0){
			for(i = 0; i<14 - x; ++i){
				displaybuffer[page][i] = obstacle[i - x];
			}
		}
		else{
			for(i = 0; i<14; ++i){
				if(!((x+i) > 127))
					displaybuffer[page][x + i] = obstacle[i];
			}
		}
	}	
}

char road_offset = 0;
void display_road ( void ){
	int i, j, loops, shift, r;
	r = road_offset;
	shift = 8;
	for(i = 0; i<4; ++i){
		for(j = 0; j<128; ++j){
			displaybuffer[i][j] = displaybuffer[i][j] | ((road[r] >> (shift * i)) & 0xFF);
			r += (obstacle_speed_x);
			if(r >= 7)
				r = 0;
		}
	}
	road_offset += (obstacle_speed_x);
	if(road_offset >= 7)
		road_offset = 0;
}