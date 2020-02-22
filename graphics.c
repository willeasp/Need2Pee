#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"

#define DISPLAY_CHANGE_TO_COMMAND_MODE (PORTFCLR = 0x10)
#define DISPLAY_CHANGE_TO_DATA_MODE (PORTFSET = 0x10)

char displaybuffer[4][128];

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

void display_frame( void ){
	int i, j, shift;
	shift = 8;
	for(i = 0; i<4; ++i){
		for(j = 0; j<128; ++j){
			displaybuffer[i][j] = displaybuffer[i][j] | ((frame[j] >> (shift * i)) & 0xFF);
		}
	}
}

void buffer2display ( void ){
	int i, j;
	
	for(i = 0; i < 4; i++) {
		DISPLAY_CHANGE_TO_COMMAND_MODE;
		spi_send_recv(0x22);		// set page address to write to
		spi_send_recv(i);			// page address to be written
		
		spi_send_recv(0x00);		// set lower nibble column start address
		spi_send_recv(0x00);		// set higher nibble column start address
		
		DISPLAY_CHANGE_TO_DATA_MODE;
		
		for(j = 0; j < 128; j++)
			spi_send_recv(displaybuffer[i][j]);
	}
}

void point2buffer (int x, int y){
	int page;


	displaybuffer[page][x] = displaybuffer[page][x] |  
}