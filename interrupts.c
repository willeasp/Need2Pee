#include <pic32mx.h>
#include <stdint.h>
#include "labresources.h"
#include "n2p.h"


/*	for update_movement	*/
int car_pos; 
char Rhold;		// Boolean Holding button 2
char Lhold;		// Boolean Holding button 4
char x;
char obstacle_speed_x;
int time_until_next_obstacle;		// interruptcycles til next object comes 
const char tuno_reset = 120;
char obstaclecount;		// for startup of objects
char collision_true = 0;
char game_on = 0;
char car_shift;		// 0 = no movement, 1 = left, 2 = right
char car_shift_position; 	// bottom = 0, top = 24

int objects_passed;



Obstacle Obs_A;	
Obstacle Obs_B;
Obstacle Obs_C;


void update_graphic( void ){
	buffer_clear();
	display_car();
	display_obstacle(Obs_A.page, Obs_A.x, Obs_A.ON);
	display_obstacle(Obs_B.page, Obs_B.x, Obs_B.ON);
	display_obstacle(Obs_C.page, Obs_C.x, Obs_C.ON);

	buffer2display();	
	
}

/*
	Left: Button 4
	Right: Button 2
*/
void update_movement ( void ){
	// Moves car and moves objects
	//	Car:
	if(difficulty){
		car_shift = 0;
		if(BUTTON_2 & car_shift_position < 24){
			car_shift = 2;
			car_shift_position += 2;
		} 
		if(BUTTON_4 & car_shift_position > 0){
			car_shift = 1;
			car_shift_position -= 2;
		}	
		if(BUTTON_2 & BUTTON_4)	
			car_shift = 0;
	} 
	/* if(difficulty){
		car_shift = 0;
		if(car_shift_position > 0 & car_shift_position < 24){
			if(BUTTON_2){
				car_shift = 2;
				++car_shift_position;
			}
			if(BUTTON_4){
				car_shift = 1;
				--car_shift_position;
			}
			if(BUTTON_2 & BUTTON_4)	
			car_shift = 0;
		}		
	}  */	
	else {					// difficulty easy / hard
		if(!(BUTTON_2))
			Rhold = 0;			
		if(!(BUTTON_4))
			Lhold = 0;
		if((BUTTON_2 & !(Rhold)) & (car_pos < 3)){
			Rhold = 1;
			++car_pos;
		}
		if((BUTTON_4 & !(Lhold)) & (car_pos > 0)){
			Lhold = 1;
			--car_pos;
		}
	}		
	

	//	Obstacles:
	--time_until_next_obstacle;
	if(time_until_next_obstacle == 0){
		time_until_next_obstacle = tuno_reset;
		if(obstaclecount < 3){
			switch(obstaclecount){
				case 0: {
					Obs_A.ON = 1;
					Obs_A.x = 128;
					Obs_A.page = 0;
					break;
				}
				case 1: {
					Obs_B.ON = 1;
					Obs_B.x = 128;
					Obs_B.page = 1;
					break;
				}
				case 2: {
					Obs_C.ON = 1;
					Obs_C.x = 128;
					Obs_C.page = 2;
					break;
				}
			}
			++obstaclecount;
		}
	}
	

	// 	Obstacle movement
	Obs_A.x -= obstacle_speed_x;
	Obs_B.x -= obstacle_speed_x;
	Obs_C.x -= obstacle_speed_x;

	if(Obs_A.x < -14){
		Obs_A.x = Obs_A.x + 300;
		Obs_A.page = randnr(4);
		++objects_passed;
	}
	if(Obs_B.x < -14){
		Obs_B.x = Obs_B.x + 301;
		Obs_B.page = randnr(4);
		++objects_passed;
	}
	if(Obs_C.x < -14){
		Obs_C.x = Obs_C.x + 400;
		Obs_C.page = randnr(4);
		++objects_passed;
	}
		
}

double abs ( double d ){
	if(d >= 0)
		return d;
	else
		return d * (-1);	
}

/* int collision_check( void ){
	
	// if(	(Obs_A.ON && Obs_A.x < 14 && Obs_A.x >= -13 && Obs_A.page == car_pos) || 
	// 	(Obs_B.ON && Obs_B.x < 14 && Obs_B.x >= -13 && Obs_B.page == car_pos) ||
	// 	(Obs_C.ON && Obs_C.x < 14 && Obs_C.x >= -13 && Obs_C.page == car_pos) ) {
	// 		return 1;
	// 	}
	if(	(Obs_A.ON && Obs_A.x < 14 && Obs_A.x >= -13) || 
		(Obs_B.ON && Obs_B.x < 14 && Obs_B.x >= -13) ||
		(Obs_C.ON && Obs_C.x < 14 && Obs_C.x >= -13) ) {

		if(difficulty){
			double pos = (double)car_shift_position / (double) 8;
			if( abs(pos - Obs_A.page) < 1 ||
				abs(pos - Obs_B.page) < 1 ||		// när du kollar här måste bilen som jämförs med vara den enda som jämförs.
				abs(pos - Obs_C.page) < 1	)		// de andra bilarna ligger på andra pages men är inte i farozonen.
				return 1;
			return 0;	
		} 
		else {
			if(	Obs_A.page == car_pos ||
					Obs_A.page == car_pos ||
					Obs_A.page == car_pos	)
				return 1;
		}
			
	}	
} */

int collision_check( Obstacle Obs ){	
	// if(	(Obs_A.ON && Obs_A.x < 14 && Obs_A.x >= -13 && Obs_A.page == car_pos) || 
	// 	(Obs_B.ON && Obs_B.x < 14 && Obs_B.x >= -13 && Obs_B.page == car_pos) ||
	// 	(Obs_C.ON && Obs_C.x < 14 && Obs_C.x >= -13 && Obs_C.page == car_pos) ) {
	// 		return 1;
	// 	}
	if(Obs.ON && Obs.x < 14 && Obs.x >= -13) {
		if(difficulty){
			double pos = (double)car_shift_position / 8.0;
			if( abs(pos - (double)Obs.page) < 1.0 )		// de andra bilarna ligger på andra pages men är inte i farozonen.
				return 1;	
			else
				return 0;	
		} 
		// else {
		// 	if(	Obs.page == car_pos)
		// 		return 1;
		// }			
	}	
	return 0;
}

void user_isr ( void ){
	IFS(0) = 0;
	if(game_on && !(collision_true)){
		update_graphic();	
		update_movement();
		if(	collision_check(Obs_A) || 
			collision_check(Obs_B) || 
			collision_check(Obs_C)	){
			collision_true = 1;
			game_on = 0;
			crash();
		}
	}
}

void init_objects( void ){	
	Obs_A.page = 0;
	Obs_A.x = 0;
	Obs_A.ON = 0;

	Obs_B.page = 0;
	Obs_B.x = 0;
	Obs_B.ON = 0;

	Obs_C.page = 0;
	Obs_C.x = 0;
	Obs_C.ON = 0;
}

void init_variables ( void ){
	car_pos = 1; 
	Rhold = 0;		// Boolean Holding button 2
	Lhold = 0;		// Boolean Holding button 4
	x = 0;
	obstacle_speed_x = 4;
	time_until_next_obstacle = 120;		// interruptcycles til next object comes 
	obstaclecount = 0;		// for startup of objects	
	car_shift = 0;		// 0 = no movement, 1 = left, 2 = right
	car_shift_position = 12; 
	objects_passed = 0;

	collision_true = 0;
	game_on = 1;
}