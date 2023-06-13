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
	spaceship->posX = 5;
	spaceship->posY = 20;
	spaceship->velX = 0;
	spaceship->velY = 0;
	spaceship->life = 3;
}

//create spaceship
void createSpaceship(spaceship_t* spaceship) {

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

		gotoxy(spaceship->posX +1 ,spaceship->posY - 1 );
		printf("%c", 219);
		gotoxy(spaceship->posX +1 ,spaceship->posY  );
		printf("%c", 219);
		gotoxy(spaceship->posX +1 ,spaceship->posY + 1 );
		printf("%c", 219);

		gotoxy(spaceship->posX +2 ,spaceship->posY);
		printf("%c", 219);



		//printf("%c", 219);


}

//update spaceship position
void updateSpaceship(spaceship_t* spaceship, uint8_t joystickState){
	spaceship->posX = spaceship->posX + spaceship->velX;
	spaceship->posY = spaceship->posY + spaceship->velY;

	//pin down
	if (spaceship->life > 0 ) {
		if (joystickState == 2 ){

			spaceship->posY += 1;
			spaceship->velY = 1;
			spaceship->velX = 0;

		}else if (joystickState == 1 ) {
			//pin up
			spaceship->posY -= 1;
			spaceship->velY = -1;
			spaceship->velX = 0;

		}else if (joystickState == 4 ){
			//pin left

			spaceship->posX -= 1;
			spaceship->velY = 0;
			spaceship->velX = -1;
		}else if (joystickState == 8 ){
			//pin right

			spaceship->posX += 1;
			spaceship->velY = 0;
			spaceship->velX = 1;
		}
	}
}

//delete the prev spaceship
void removeSpaceship(spaceship_t* spaceship){

	//uint8_t joystickState = keyboardController();


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

			gotoxy(spaceship->posX +1 ,spaceship->posY - 1 );
			printf("%c", 32);
			gotoxy(spaceship->posX +1 ,spaceship->posY  );
			printf("%c", 32);
			gotoxy(spaceship->posX +1 ,spaceship->posY + 1 );
			printf("%c", 32);

			gotoxy(spaceship->posX +2 ,spaceship->posY);
			printf("%c", 32);


	//gotoxy(spaceship->posX,spaceship->posY);
	//printf("%c", 32);
}





/*

switch(joystickState){
	case 2:
		spaceship->posY += 1;
		spaceship->velY = 1;
		spaceship->velX = 0;
		//rotateVector((&spaceship->posX,&spaceship->posY), 5);
		break;
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


}*/

