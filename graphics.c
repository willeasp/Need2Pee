#include <pic32mx.h>
#include <stdint.h>
#include <stdlib.h>
#include "labresources.h"
#include "n2p.h"

#define DISPLAY_CHANGE_TO_COMMAND_MODE (PORTFCLR = 0x10)
#define DISPLAY_CHANGE_TO_DATA_MODE (PORTFSET = 0x10)

uint8_t displaybuffer[4][128];

uint32_t frame[128];

uint32_t zero[128];



void graphics_init ( void ){
	int i, j, shift;

	/* blacken screen */
	shift = 8;
	for(i = 0; i < 4; i++) {
		DISPLAY_CHANGE_TO_COMMAND_MODE;
		spi_send_recv(0x22);		// set page address to write to
		spi_send_recv(i);			// page address to be written
		
		spi_send_recv(0x00);		// set lower nibble column start address
		spi_send_recv(0x00);		// set higher nibble column start address
		
		DISPLAY_CHANGE_TO_DATA_MODE;
		
		for(j = 0; j < 128; j++)
			spi_send_recv((zero[j] >> (shift * i)) & 0xFF);
	}

	/* init frame */
	frame[0] = ~0x0;
	for(i = 1; i<127; ++i){
		frame[i] = 0x80000001;
	}
	frame[127] = ~0x0;
}

void display_intarray( uint32_t a[] ){
	int i, j, shift;
	shift = 8;
	for(i = 0; i<4; ++i){
		for(j = 0; j<128; ++j){
			displaybuffer[i][j] = displaybuffer[i][j] | ((a[j] >> (shift * i)) & 0xFF);
		}
	}
}

void buffer2display ( void ){
	int i, j;
	
	for(i = 0; i < 4; i++) {
		DISPLAY_CHANGE_TO_COMMAND_MODE;
		spi_send_recv(0x22);		// set page address to write to
		spi_send_recv(i);			// page address to be written
		
		spi_send_recv(0x21);		// set higher nibble column start address
		spi_send_recv(0);
		spi_send_recv(127);
		
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
	
	/* if(displaybuffer[page][x] & (0x1 << shift))
		displaybuffer[page][x] = displaybuffer[page][x] & ~(0x1 << shift);
	else */
		displaybuffer[page][x] = displaybuffer[page][x] | (0x1 << shift);
}

int randnr ( int max ) {
   return TMR2 % max;      
}

void display_car ( int page ){
	int i;
	for(i = 0; i<13; ++i){
		displaybuffer[page][i] = car[i];
	}
}

void display_obstacle ( int page, int x ){
	int i;
	for(i = 0; i<14; ++i){
		displaybuffer[page][x + i] = obstacle[i];
	}
}