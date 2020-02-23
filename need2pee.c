/*
	Spelet styrs här ifrån. När spelet startar kommer man till en meny och
*/

#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"

#define BUTTON_4 PORTD & (1 << 7)
#define BUTTON_3 PORTD & (1 << 6)
#define BUTTON_2 PORTD & (1 << 5)
#define BUTTON_1 PORTF & 2

int activity = 0;
int which_menu = 0;
int menu_select = 0;

void options_menu ();
void set_difficulty();


void main_menu (void){

	display_string(0, "Highscore:");
	display_string(1, "Last game");
	display_string(2, "Start");
	display_string(3, "Options");
	display_update();
	
	display_image(96, icon);

	while(){
		if (BUTTON_1) {									// BUTTON_1 enter
			if (which_menu & menu_select) == 0; {		// Om Start game är vald
				/* activity = 1;						// Sätt activity 1
				/* start_game(); */						// Start game
			if (menu_select);							// Om Options är vald
			which_menu++;								// Sätt which_menu 1
			menu_select = 0;							// sätt menu_select till 0
			options_menu(menu_select);					// Hoppa till options menu
			}
		}
								
		if (BUTTON_2) {									// BUTTON_2 ändra plats i menyn
			if (menu_select) {							// Om menu_select är 1
				menu_select = 0;						// sätt menu select till 0
				//invert_graphic_(bottom_page);			// Invertera grafiken i main_menu
			}
			else {										// Else (om menu_select är 0)
				menu_select = 1;						// Sätt menu_select till 1
				//invert_graphic_(bottom_page);			// Invertera grafiken i main_menu
			}
		}
		if (BUTTON_3) {									// BUTTON_3 ändra plats i menyn
			if (menu_select) {							// Om menu_select är 1
				menu_select = 0;						// sätt menu select till 0
				//invert_graphic_(bottom_page);			// Invertera grafiken i main_menu
			}
			else {										// Else (om menu_select är 0)
				menu_select = 1;						// Sätt menu_select till 1
				//invert_graphic_(bottom_page);			// Invertera grafiken i main_menu
			}
		}
	}
}

void options_menu (void) {

	display_string(0, "Difficulty:");				
	display_string(1, "Easy");						
	display_string(2, "Hard");						
	display_string(3, "Extreme");
	display_update();
	display_image(96, icon);

	//invert_grapic(menu_select);

	while (){
		if (BUTTON_1) {									//BUTTON_1 Välj svårighetsgrad
			set_difficulty(menu_select);
			//invert_graphic(menu_select);
		}
		if (BUTTON_2) {									//BUTTON_2 back
			which_menu--;
			main_menu(which_menu);
		}
		if (BUTTON_3) {									//BUTTON_3 ändra plats i menyn
			if (menu_select) {
				menu_select = 0;
				//invert_graphic_(menu_select);
			}
			else {
				menu_select = 1;
				//invert_graphic_(menu_select);
			}
		}
		if (BUTTON_4) {								//BUTTON_4 ändra plats i menyn
			if (menu_select) {
				menu_select = 0;
				//invert_graphic_(menu_select);
			}
			else {
				menu_select = 1;
				//invert_graphic_(menu_select);
			}
		}
	}
}

void hello ( void ){
	display_string(0, "goddag");
	display_string(1, "i stugan");
	display_string(2, "->");
	display_string(3, "wowza");
	display_update();
	
	display_image(96, icon); 
}


/*	Function called by main	*/
void need2pee ( void ) {
	main_menu();
	
}

void options_menu (){
	display_string(0, "Options");
	display_update();
}
void set_difficulty(){
	display_string(0, "Set difficulty");
	display_update();
}