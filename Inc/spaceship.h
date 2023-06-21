/*
 * spaceship.h
 *
 *  Created on: 11. jun. 2023
 *      Author: oscar
 */

#ifndef SPACESHIP_H_
#define SPACESHIP_H_

#include "stm32f30x_conf.h"
#include "pins.h"
#include "uart.h"
#include <math.h>
#include "vector.h"

typedef struct {

	int16_t posX;
	int16_t posY;
	int8_t life;

} spaceship_t;

//extern int8_t spaceShipLife;

void initSpaceship(spaceship_t* spaceship);
void createSpaceship(spaceship_t* spaceship);
void updateSpaceship(spaceship_t* spaceship, uint8_t joystickState);
void removeSpaceship(spaceship_t* spaceship);

#endif /* SPACESHIP_H_ */
