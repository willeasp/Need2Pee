/*	File written 2020 by Joel Maanmies & William Asp	*/

#include <pic32mx.h>
#include <stdint.h>
#include "n2p.h"
/* Variabler och funktioner för highscore */

//char lvl = 1;                   // börjar på lvl 1
//int last_game = 0;            // Ska vara en funktion
int highest_score = 0;        // tidigare högsta rekord
char char_highscore[] = "HIGHSCORE:         ";
char char_lasttry[20]; 
char lastgame[] =   "LAST GAME:         ";



// lvlup ska göra så att spelet går snabbare, eventuellt interrupt?
/*
void lvlup (void){
    points++;
    lvl = 1 + (points / 10);
}
*/

/* funktion för att göra färdigt strängarna som visar poängen i main menu */

/*  memcpy found on github  */
void *
memcpy (void *dest, const void *src, int len)
{
  char *d = dest;
  const char *s = src;
  while (len--)
    *d++ = *s++;
  return dest;
}

void get_highscore(int points){
    memcpy(char_lasttry, lastgame, sizeof(char_lasttry));
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