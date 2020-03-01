#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"

#define BUTTON_4 (PORTD >> 7) & 1	// Up	/	Left
#define BUTTON_3 (PORTD >> 6) & 1	// Down
#define BUTTON_2 (PORTD >> 5) & 1	// Enter	/	Right
#define BUTTON_1 (PORTF >> 2) & 1			// Back


char car_posi = 1; 
char RHOLD = 1;		// Boolean Holding button 2
char LHOLD = 0;		// Boolean Holding button 4

char RHOLD_string[2];
char LHOLD_string[2];
char *BUTTON_2_string = "balle";
char BUTTON_4_string[2];

void does_button_work (void){
	if(!(BUTTON_2)){
		display_string(0, "Button 2");
	}
	else{
		display_string(0, " ");
	}

	if(!(BUTTON_4)){
		display_string(1, "Button 4");
	}
	else{
		display_string(1, " ");
	}
	display_update();
}

void test_game_no_interrupts(void){
/* 	while(1){
		does_button_work();
	}
	RHOLD_string[1] = 0x00;
	LHOLD_string[1] = 0x00;
	//BUTTON_2_string[1] = 0x00;
	BUTTON_4_string[1] = 0x00;

	display_string(3, "DISPLAYTEST");
	display_update();
	delay(1000000);
	display_string(3, "STARTED");
	display_update(); */
	while(1){
		/* buffer_clear();
		display_car(car_posi);
		buffer2display(); */

/* 
		RHOLD_string[0] = RHOLD + 0x30;
		LHOLD_string[0] = LHOLD + 0x30;
		//*BUTTON_2_string = "kuks";		//BUTTON_2 & 0x30;
		BUTTON_4_string[0] = 0x6E + 0x31;

		display_string(0, RHOLD_string);
		display_string(1, LHOLD_string);
		display_string(2, BUTTON_2_string);
		display_string(3, BUTTON_4_string);

		RHOLD++;
		if(RHOLD == 20)
			RHOLD = 0;

		display_update(); */

		//display_string(2, "hoj");
		//display_update();
		if(!(BUTTON_2)){
			RHOLD = 0;	
			display_string(0, "RHOLD = 0");
		}				
		if(!(BUTTON_4)){
			LHOLD = 0;
			display_string(1, "LHOLD = 0");
		}
		if((BUTTON_2 & !(RHOLD)) & (car_posi < 3)){
			RHOLD = 1;
			display_string(0, "RHOLD = 1");
			++car_posi;
			display_string(2, "++");
		}
		if((BUTTON_4 & !(LHOLD)) & (car_posi > 0)){
			LHOLD = 1;
			display_string(1, "LHOLD = 1");
			--car_posi;
			display_string(2, "--");
		}
		display_update();
	}

}