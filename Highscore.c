#include <pic32mx.h>
#include <stdint.h>
#include "n2p.h"

char lvl = 0;
int points = 0;
int highest_score = 0;
int last_game = 0;
int score = 0;
int game_on;
int highest_score;

void highscore (void){
    if (game_on = 1) {
        points++;
        if (points = 1000) {
            lvl++;
            points = 0;
            score = lvl * 1000 + points;
        }
    }
    else {    
        last_game = score;
        if (score > highest_score) {
        highest_score = points;
        }
    }
}
