#include <pic32mx.h>
#include <stdint.h>
#include "n2p.h"
/* Variabler och funktioner för highscore */
void int_to_hex(int);
void hex_to_char(void);

char lvl = 1;                   // börjar på lvl 1
int points = 999;               // points ska vara 0, 999 TESTVÄRDE
int last_game = 800;            // Ska vara en funktion
int highest_score = 900;        // tidigare högsta rekord
char char_points[] ="HISCORE:           ";
// int highest_score= 20;       // Ska köras genom funktionerna?


// lvlup ska göra så att spelet går snabbare, eventuellt interrupt?
/*
void lvlup (void){
    points++;
    lvl = 1 + (points / 10);
}
*/

/* 
Kollar om highscore ska sparas och kallar isf funktioner för detta
*/
void get_highscore (int points){
//  last_game = points; 
    if (points > highest_score){
        highest_score = points;
        int_to_hex(points);             // konverterar int till hexadecimalt
     //   hex_to_char();
    }
}

/*
konverterar int till hexadecimalt
*/

void int_to_hex(int points){
    char i = 15;
    char rest = 0;
    
    while (points != 0){
        rest = points % 16;
        if (rest < 10){
            char_points[i] = (rest  + ((char)48) );
        }
        else{
            char_points[i] = (rest +  ((char)55) );
        }
        points = points / 16;
        i--;
    }
}

/*
Tar ett hexadecimalt värde och omvandlar till char
*/
/*
void hex_to_char (void){
    int i = 16;                 // skriv till plats 16 först
    int j = 0;                 
    while (i > 8){
        char_points[i] = (((highest_score >> (j * 4)) & 0xf) + 48);
        i--;
        j++;
    }
}
*/