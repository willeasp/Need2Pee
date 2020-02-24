#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"

#define BUTTON_4 PORTD & (1 << 7)	// Up	/	Left
#define BUTTON_3 PORTD & (1 << 6)	// Down
#define BUTTON_2 PORTD & (1 << 5)	// Enter	/	Right
#define BUTTON_1 PORTF & 2			// Back

void options_menu (void);
void set_difficulty(int setting);
int get_input(void);

int which_menu = 0;
int menu_select = 0;

void main_menu (void){

    menu_select = 0;

    display_string(0, "Highscore:");
	display_string(1, "Last game");
	display_string(2, "Start");
	display_string(3, "Options");
	display_update();
	
    /*
	display_image();    om vi ska ha en bild på en bil i menyerna
    */

	
	while(1) {
		// enter
		if (BUTTON_2) {
			while (BUTTON_2) {}
				if (menu_select == 0) {
				display_string(2, "Start game");
				display_update();
				}
			else {
				options_menu();
			}
		}
		// down
		if (BUTTON_3) {
			while (BUTTON_3) {}
				if (menu_select){
					menu_select = 0;
					// invertera menu_select(0)
				}
				else {
					menu_select = 1;
					// invertera menu_select(1)
				}
		}
		// up
		if (BUTTON_4) {
			while (BUTTON_4) {}
				if (menu_select){
					menu_select = 0;
					// invertera menu_select(0)
				}
				else {
					menu_select = 1;
					// invertera menu_select(1)
				}
		}
	}
}

void options_menu (void) {

    menu_select = 0;

	display_string(0, "Difficulty:");				
	display_string(1, "Easy");						
	display_string(2, "Hard");						
	display_string(3, "Extreme");
	display_update();

	while (1) {
		// back
		if (BUTTON_1) {
			while (BUTTON_1) {}
			main_menu();
		}
        // enter
		if (BUTTON_2) {
			while (BUTTON_2) {}
            	if (menu_select == 0){
				display_string(0, "Easy");
                display_update();
				}
				if (menu_select == 1) {
                display_string(0, "Hard");
                display_update();
				}
				if (menu_select == 2) {
				display_string(0, "Extreme");
                display_update();
				}			
		}			
		// down
		if (BUTTON_3) {
			while (BUTTON_3) {}
				if (menu_select == 0){
					menu_select = 1;
					// invertera menu_select(1)
				}
				if (menu_select == 1) {
					menu_select = 2;
					// invertera menu_select(2)
				}
				if (menu_select == 2) {
					menu_select = 0;
					// invertera menu_select(0)
				}
		}
		// up
		if (BUTTON_4) {
			while (BUTTON_4) {}
				if (menu_select == 0) {
					menu_select = 2;
					// invertera menu_select(2)
				}
				if (menu_select == 1) {
					menu_select = 0;
					// invertera menu_select(0)
				}
				if (menu_select == 2) {
					menu_select = 1;
					// invertera menu_select(1)
				}
        }
    }
}