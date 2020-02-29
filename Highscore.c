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

void get_highscore(int points){
    if (points > highest_score) {
        highest_score = points;
        int i = 15;
        while (points != 0){
            char_highscore[i--] = '0' +(points%10);
            points /=10;
        }
    }                   
    int j = 9;
    while(j < 16) {
        char_lasttry[j] = char_highscore[j];
        j++;
    }
}