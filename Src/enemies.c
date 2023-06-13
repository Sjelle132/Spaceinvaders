/*
 * enemies.c
 *
 *  Created on: 11. jun. 2023
 *      Author: oscar
 */

#include "enemies.h"
#include "pins.h"
#include "uart.h"
#include <math.h>
#include "vector.h"
#include "timers.h"


//initialize 3 enemies

void initEnemies(enemies_t enemies[]) {
	for (int i = 0; i < 3; i++){
		enemies[i].posX = 150;
		enemies[i].posY = 10+i*4;//10*i+rand()%40;
		enemies[i].velX = 0;
		enemies[i].velY = 0;
		enemies[i].life = 2;
	}

}


void initEliteEnemy(eliteEnemy_t* EliteEnemy) {
	EliteEnemy->posX = 0;
	EliteEnemy->posY = 0;
	EliteEnemy->velX = 0;
	EliteEnemy->velY = 0;
	EliteEnemy->life = 6;
}


//create or draw enemies as array
void createEnemies(enemies_t enemies[], int8_t f) {

	if (!(returnMilisec()%20)){
	for (int i = 0; i < 3; i++){
		if (enemies[i].life > 0){
			gotoxy(enemies[i].posX,enemies[i].posY);
			printf("%c", 219);
		}
	}

	}
	f=returnHNDR();
}

//update enemies position
void updateEnemies(enemies_t enemies[],int8_t f){

	if (!(returnMilisec()%20)){
		for (int i = 0; i < 3; i++) {
			enemies[i].posX -= 1;

			enemies[i].posX = enemies[i].posX + enemies[i].velX;
			enemies[i].posY = enemies[i].posY + enemies[i].velY;

		}
	}
	//f=returnHNDR();

}

//delete the prev enemies
void removeenemies(enemies_t* enemies){

	//uint8_t joystickState = keyboardController();


	gotoxy(enemies->posX,enemies->posY);
	printf("%c", 32);
	gotoxy(enemies->posX ,enemies->posY + 1);
	printf("%c", 32);
	gotoxy(enemies->posX ,enemies->posY + 2);
	printf("%c", 32);
	gotoxy(enemies->posX ,enemies->posY - 1);
	printf("%c", 32);
	gotoxy(enemies->posX ,enemies->posY - 2 );
	printf("%c", 32);

	gotoxy(enemies->posX +1 ,enemies->posY - 1 );
	printf("%c", 32);
	gotoxy(enemies->posX +1 ,enemies->posY  );
	printf("%c", 32);
	gotoxy(enemies->posX +1 ,enemies->posY + 1 );
	printf("%c", 32);

	gotoxy(enemies->posX +2 ,enemies->posY);
	printf("%c", 32);


	//gotoxy(enemies->posX,enemies->posY);
	//printf("%c", 32);
}





/*

switch(joystickState){
	case 2:
		enemies->posY += 1;
		enemies->velY = 1;
		enemies->velX = 0;
		//rotateVector((&enemies->posX,&enemies->posY), 5);
		break;
		//pin up
	}else if (joystickState == 1){
		enemies->posY -= 1;
		enemies->velY = -1;
		enemies->velX = 0;
		//rotateVector((&enemies->posX,&enemies->posY), -5);

		//pin left
	}else if (joystickState == 4){
		enemies->posX -= 1;
		enemies->velY = 0;
		enemies->velX = -1;

		//pin right
	}else if (joystickState == 8){
		enemies->posX += 1;
		enemies->velY = 0;
		enemies->velX = 1;

		//pin center
	}else if (joystickState == 16){

		//else pos = pos, vel = vel
	}else {
		enemies->posX = enemies->posX;
		enemies->posY = enemies->posY;
		enemies->velX = 0;
		enemies->velY = 0;


	}


}*/

