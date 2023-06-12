/*
 * spaceship.c
 *
 *  Created on: 11. jun. 2023
 *      Author: oscar
 */

#include "spaceship.h"
#include "pins.h"
#include "uart.h"
#include <math.h>
#include "vector.h"


//initialize spaceship

void initSpaceship(spaceship_t* spaceship) {
	spaceship->posX = 0;
	spaceship->posY = 0;
	spaceship->velX = 0;
	spaceship->velY = 0;
	spaceship->life = 3;
}

//create spaceship
void createSpaceship(spaceship_t* spaceship) {
	if (spaceship->life > 0){
		gotoxy(spaceship->posX,spaceship->posY);
		printf("%c", 219);

	}
}

//update spaceship position
void updateSpaceship(spaceship_t* spaceship){
	spaceship->posX = spaceship->posX + spaceship->velX;
	spaceship->posY = spaceship->posY + spaceship->velY;

	//uint8_t joystickState = readJoystick();
	uint8_t joystickState = keyboardController();

	//pin down
	if (joystickState == 2){
		spaceship->posY += 1;
		spaceship->velY = 1;
		spaceship->velX = 0;
		//rotateVector((&spaceship->posX,&spaceship->posY), 5);

		//pin up
	}else if (joystickState == 1){
		spaceship->posY -= 1;
		spaceship->velY = -1;
		spaceship->velX = 0;
		//rotateVector((&spaceship->posX,&spaceship->posY), -5);

		//pin left
	}else if (joystickState == 4){
		spaceship->posX -= 1;
		spaceship->velY = 0;
		spaceship->velX = -1;

		//pin right
	}else if (joystickState == 8){
		spaceship->posX += 1;
		spaceship->velY = 0;
		spaceship->velX = 1;

		//pin center
	}else if (joystickState == 16){

		//else pos = pos, vel = vel
	}else {
		spaceship->posX = spaceship->posX;
		spaceship->posY = spaceship->posY;
		spaceship->velX = 0;
		spaceship->velY = 0;


	}


}

//delete the prev spaceship
void removeSpaceship(spaceship_t* spaceship){
	gotoxy(spaceship->posX,spaceship->posY);
	printf("%c", 32);
}








