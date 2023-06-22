/*

powerup.h*
Created on: 14. jun. 2023
Author: filip
 */

#ifndef POWERUPH
#define POWERUPH

#include "stm32f30x_conf.h"
#include "spaceship.h"
#include "bullet.h"

typedef struct{
	int32_t posX, posY;
	int8_t enable;
	int8_t flag;
	int8_t collected;
} powerup_t;

void initPowerup(powerup_t* powerup);
void drawPowerup(powerup_t* powerup);
void removePowerup(powerup_t* powerup);
void collisionDetection(powerup_t* powerup, spaceship_t* spaceship);



#endif /* POWERUPH */
