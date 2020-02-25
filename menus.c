#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"
                                    // I meny   /   I spel
#define BUTTON_4 PORTD & (1 << 7)	// Up       /   Left
#define BUTTON_3 PORTD & (1 << 6)	// Down
#define BUTTON_2 PORTD & (1 << 5)	// Enter    /   Right
#define BUTTON_1 PORTF & 2			// Back       

void options_menu (void);                       /* Introducera funktioner och variabler som används i menyerna */
void set_difficulty(int setting);               // Sätter svårighetsgrad
int which_menu;                                 // Håller reda på vilken meny som används
int menu_select;                                // Håller reda på vilken menyrad som är vald

void main_menu (void){                          // Main menu
    which_menu = 0;                             
    menu_select = 2;                            

    display_string(0, "HIGHSCORE: xxxx");
	display_string(1, "LAST GAME: xxxx");
	display_string(2, "<START>");
	display_string(3, " OPTIONS");
	display_update();
	
    /*
	display_image();    om vi ska ha en bild på en bil i menyerna
    */

	
	while(1) {
		if (BUTTON_2) {                             // enter
			while (BUTTON_2) {}
                if (which_menu == 0) {
				    if (menu_select == 2) {
				        display_string(2, "START GAME");
				        display_update();
				    }
			        else {
				        options_menu();
                    }
			    }
		}
		if (BUTTON_3) {                             // down
			while (BUTTON_3) {}
				if (menu_select == 2){
					menu_select = 3;
	                display_string(2, " START");
	                display_string(3, "<OPTIONS>");
	                display_update();
				}
		}
		if (BUTTON_4) {                             // up
			while (BUTTON_4) {}
				if (menu_select == 3){
					menu_select = 2;
	                display_string(2, "<START>");
	                display_string(3, " OPTIONS");
	                display_update();
				}

		}
	}
}

void options_menu (void) {
    which_menu = 1;
    menu_select = 1;

	display_string(0, "DIFFICULTY:");				
	display_string(1, "<EASY>");						
	display_string(2, " HARD");						
	display_string(3, " EXTREME");
	display_update();

	while (1) {
		// back
		if (BUTTON_1) {
			while (BUTTON_1) {}
            which_menu = 0;
			main_menu();
		}
        // enter
		if (BUTTON_2) {
			while (BUTTON_2) {}
                    if (which_menu == 1) {
                        if (menu_select == 1){
                            display_string(0, "EASY");
                            display_update();
                        //    set_difficulty(0);
                        }
                    if (menu_select == 2) {
                            display_string(0, "HARD");
                            display_update();
                        //    set_difficulty(1);
                        }
                    if (menu_select == 3) {
                            display_string(0, "EXTREME");
                            display_update();
                        //    set_difficulty(2);
                        }
                    }
		}			
		// down
		if (BUTTON_3) {
			while (BUTTON_3) {}
				if (menu_select == 1) {
                    menu_select = 2;				
                    display_string(1, " EASY");						
	                display_string(2, "<HARD>");						
	                display_update();
                }
                else if (menu_select == 2) {
                    menu_select = 3;					
                    display_string(2, " HARD");						
                    display_string(3, "<EXTREME>");
                    display_update();
                }
        } 
		// up
		if (BUTTON_4) {
			while (BUTTON_4) {}
                if (menu_select == 3) {
                    menu_select = 2;									    
	                display_string(2, "<HARD>");						
	                display_string(3, " EXTREME");
	                display_update();  
                }
                else if (menu_select == 2) {
                    menu_select = 1;				
                    display_string(1, "<EASY>");						
	                display_string(2, " HARD");						
	                display_update();
                }  
        } 
    }  
} 