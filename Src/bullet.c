/*
 * bullet.c
 *
 *  Created on: 11. jun. 2023
 *      Author: oscar
 */

#include "bullet.h"
#include "spaceship.h"
#include "uart.h"

void initBullet(bullet_t* bullet,spaceship_t* spaceship){
	bullet->posX = spaceship->posX;
	bullet->posY = spaceship->posY;
	bullet->velX = 0;
	bullet->velY = 0;
	bullet->true = 1;
}

void spawnBullet(bullet_t* bullet){
	bullet->posX = 1000;
	bullet->posY = 1000;
	bullet->velX = 0;
	bullet->velY = 0;
	bullet->true = 1;
}

void createBullet(bullet_t* bullet ){
	if (bullet->true) {
		gotoxy(bullet->posX,bullet->posY);
		//bullet->posX = spaceship->posX;
		//bullet->posY = spaceship->posY;
		printf("%c", 111);

	}

}

void updateBullet(bullet_t* bullet) {

	//directionState = keyboardController();

	//bullet only shooting right
	if (bullet->true) {

					bullet->posX += 1;
					bullet->velX = 1;

					bullet->posX = bullet->posX + bullet->velX;
					bullet->posY = bullet->posY + bullet->velY;


	}
}


void removeBullet(bullet_t* bullet) {
	gotoxy(bullet->posX,bullet->posY);
	printf("%c", 32);
}

