#include <pic32mx.h>
#include <stdint.h>
#include "n2p.h"
/* Variabler och funktioner för highscore */

//char lvl = 1;                   // börjar på lvl 1
//int last_game = 0;            // Ska vara en funktion
int highest_score = 0;        // tidigare högsta rekord
char char_highscore[] = "HIGHSCORE:         ";
char char_lasttry[] =   "LAST GAME:         ";



// lvlup ska göra så att spelet går snabbare, eventuellt interrupt?
/*
void lvlup (void){
    points++;
    lvl = 1 + (points / 10);
}
*/

/* funktion för att göra färdigt strängarna som visar poängen i main menu */

void get_highscore(int points){
    int i = 15;
    int temp, score;
    score = points + (points * (difficulty+1) * 3 * obstacle_speed_x);
    temp = score;

    do {
        char_lasttry[i--] = '0' +(temp%10);
        temp /=10;
        } while (temp != 0);                   
    int j = 15;

    if (score >= highest_score) {
        highest_score = score;
        temp = score;

        do {
        char_highscore[j--] = '0' +(temp%10);
        temp /=10;
        } while (temp != 0);
        /* highest_score = points;
        while(j < 8) {            
            char_highscore[j] = char_lasttry[j];
            j--;
        } */
    }
}