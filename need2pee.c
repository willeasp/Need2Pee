/*
	Spelet styrs här ifrån. När spelet startar kommer man till en meny och
*/

#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"

int which_menu = 0;		/* Håller reda på vilken meny spelet befinner sig i */
int menu_select = 0;			/* Håller reda på vilken rad i menyn spelet befinner sig i */
int buttons;
main_menu(*menu_select);

void main_menu ( int *select ){
	//display_frame();

	//invert_grapic(menu_select);
	display_string(0, "Highscore:");
	display_string(1, "Last game");
	display_string(2, "Start");
	display_string(3, "Options");
	display_update();
	
	display_image(96, icon); 

	buttons = getbtns;

	if (buttons & 0x00000010) {	//button_1 enter
		if (which_menu & menu_select) == 0; {
		/* start_game(); */
		if (menu_select);
		which_menu++;
		options_menu();
		}
	}
							
	if (buttons & 0x00000040) {	//button_3 ändra plats i menyn
		if (menu_select) {
			menu_select = 0;
			//invert_graphic_(menu_select);
		}
		else {
			menu_select = 1;
			//invert_graphic_(menu_select);
		}
	}
	if (buttons & 0x00000040) {	//button_3 ändra plats i menyn
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

void options_menu (void) {
	//display_frame();
	//buffer2display();

	//invert_grapic(menu_select);

	if (buttons & 0x00000020) {	//button_2 back
		if (which_menu == 1)
		which_menu--;
		main_menu();
	}
		if (buttons & 0x00000040) {	//button_3 ändra plats i menyn
		if (menu_select) {
			menu_select = 0;
			//invert_graphic_(menu_select);
		}
		else {
			menu_select = 1;
			//invert_graphic_(menu_select);
		}
	}
	if (buttons & 0x00000040) {	//button_3 ändra plats i menyn
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
