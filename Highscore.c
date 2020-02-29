#include <pic32mx.h>
#include <stdint.h>
#include "n2p.h"
/* Variabler och funktioner för highscore */

char lvl = 1;                   // börjar på lvl 1
int points = 999;               // points ska vara 0, 999 TESTVÄRDE
// int last_game = 0;            // Ska vara en funktion
int highest_score = 0;        // tidigare högsta rekord
char char_highscore[] ="HISCORE:           ";
char char_lasttry[] ="LASTTRY:           ";



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
    int temp;
    temp = points;
    while (temp != 0){
        char_lasttry[i--] = '0' +(temp%10);
        temp /=10;
        }                   
    int j = 9;
    if (points > highest_score) {
        while(j < 16) {
            highest_score = points;
            char_highscore[j] = char_lasttry[j];
            j++;
        }
    }
}