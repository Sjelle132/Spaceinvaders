/*

powerup.c*
Created on: 14. jun. 2023
Author: filip
*/

#include "powerup.h"
#include "spaceship.h"
#include "bullet.h"

void initPowerup(powerup_t* powerup) {
    powerup->posX = 20;
    powerup->posY = 20;
    powerup->enable = 1;
    powerup->flag = 0;
}

//create powerup
void drawPowerup(powerup_t* powerup){
    if (powerup->enable){
        gotoxy(powerup->posX,powerup->posY);
        printf("%c",244);
        gotoxy(powerup->posX,powerup->posY+1);
        printf("%c",244);
        gotoxy(powerup->posX,powerup->posY-1);
        printf("%c",244);
        gotoxy(powerup->posX+1,powerup->posY);
        printf("%c",244);
        gotoxy(powerup->posX+2,powerup->posY);
        printf("%c",244);
    }
}

void removePowerup(powerup_t* powerup){
    if(powerup -> enable){
    gotoxy(powerup->posX,powerup->posY);
    printf("%c",32);
    gotoxy(powerup->posX,powerup->posY+1);
    printf("%c",32);
    gotoxy(powerup->posX,powerup->posY-1);
    printf("%c",32);
    gotoxy(powerup->posX+1,powerup->posY);
    printf("%c",32);
    gotoxy(powerup->posX+2,powerup->posY);
    printf("%c",32);
    }
}

void collisionDetection(powerup_t* powerup, spaceship_t* spaceship) {
    if ((spaceship->posX +2 >= powerup->posX  && spaceship->posX -2 <= powerup->posX) &&
            (spaceship->posY +1>= powerup->posY && spaceship->posY-2<= powerup->posY)) {
        removePowerup(powerup);
        powerup->flag = 1;
        powerup->enable = 0;
    }
}
