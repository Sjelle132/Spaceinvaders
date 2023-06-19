/*
 * powerup.c
 *
 *  Created on: 14. jun. 2023
 *      Author: filip
 */

#include "powerup.h"
#include "spaceship.h"
#include "bullet.h"

void initPowerup(powerup_t* powerup) {
	powerup->posX = 50;
	powerup->posY = 30;
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
	if ((spaceship->posX >= powerup->posX - 2 && spaceship->posX <= powerup->posX + 2) &&
			(spaceship->posY >= powerup->posY - 1 && spaceship->posY <= powerup->posY + 1)) {
		removePowerup(powerup);
		powerup->flag = 1;
	}
}

void powerupSpell (powerup_t* powerup, bullet_t bullet[]){
	if (powerup->flag == 1){
		for (int j = 0; j < 20; j++){
			createBullet(&bullet[j]);
		}
		//powerup.life = +1;   //ekstra liv?
	}
}

//lav et flag når collision detection og gå ind i et switch statement der tænder 20 bulletsfremfor 10. automatisk gå tilbage efter x tid






