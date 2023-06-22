/*
 * spaceship.c
 *
 *  Created on: 11. jun. 2023
 *      Author: oscar
 */

#include "spaceship.h"

//int8_t spaceShipLife = 0;

//initialize spaceship
void initSpaceship(spaceship_t* spaceship) {
	spaceship->posX = 5;
	spaceship->posY = 20;
	spaceship->life = 3;

}

//create spaceship
void createSpaceship(spaceship_t* spaceship) {
	//back of the spaceship (left side)
	gotoxy(spaceship->posX,spaceship->posY);
	printf("%c", 219);
	gotoxy(spaceship->posX ,spaceship->posY + 1);
	printf("%c", 219);
	gotoxy(spaceship->posX ,spaceship->posY + 2);
	printf("%c", 219);
	gotoxy(spaceship->posX ,spaceship->posY - 1);
	printf("%c", 219);
	gotoxy(spaceship->posX ,spaceship->posY - 2 );
	printf("%c", 219);

	//middle section of the spaceship
	gotoxy(spaceship->posX +1 ,spaceship->posY - 1 );
	printf("%c", 219);
	gotoxy(spaceship->posX +1 ,spaceship->posY  );
	printf("%c", 219);
	gotoxy(spaceship->posX +1 ,spaceship->posY + 1 );
	printf("%c", 219);

	//front tip of the spaceship
	gotoxy(spaceship->posX +2 ,spaceship->posY);
	printf("%c", 219);

}


//update spaceship position
void updateSpaceship(spaceship_t* spaceship, uint8_t joystickState){
	//if no input, spaceship position stays the same
	spaceship->posX = spaceship->posX;
	spaceship->posY = spaceship->posY;

	//If space ship is alive, movement/steering is allowed
	if (spaceship->life > 0 ) {
		if (joystickState == 2 ){ //pin down 's'
			spaceship->posY += 1;
		}else if (joystickState == 1 ) { //pin up 'w'
			spaceship->posY -= 1;
		}else if (joystickState == 4 ){ //pin left 'a'
			spaceship->posX -= 1;
		}else if (joystickState == 8 ){	//pin right 'd'
			spaceship->posX += 1;
		}
	}
}

//delete the prev spaceship
void removeSpaceship(spaceship_t* spaceship){

	//back of the spaceship (left side)
	gotoxy(spaceship->posX,spaceship->posY);
	printf("%c", 32);
	gotoxy(spaceship->posX ,spaceship->posY + 1);
	printf("%c", 32);
	gotoxy(spaceship->posX ,spaceship->posY + 2);
	printf("%c", 32);
	gotoxy(spaceship->posX ,spaceship->posY - 1);
	printf("%c", 32);
	gotoxy(spaceship->posX ,spaceship->posY - 2 );
	printf("%c", 32);

	//middle section of the spaceship
	gotoxy(spaceship->posX +1 ,spaceship->posY - 1 );
	printf("%c", 32);
	gotoxy(spaceship->posX +1 ,spaceship->posY  );
	printf("%c", 32);
	gotoxy(spaceship->posX +1 ,spaceship->posY + 1 );
	printf("%c", 32);

	//front tip of the spaceship
	gotoxy(spaceship->posX +2 ,spaceship->posY);
	printf("%c", 32);
}
