/*
 * bullet.c
 *
 *  Created on: 11. jun. 2023
 *      Author: oscar
 */

#include "bullet.h"

void initBullet(bullet_t* bullet,spaceship_t* spaceship){
	bullet->posX = spaceship->posX +2;
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
	if (bullet->true && (bullet->posX >= 150 || bullet->posX <= 2)){
		bullet->posX += 0;
		bullet->velX = 0;
		removeBullet(bullet);
		bullet->true = 0;
	} else if(bullet->true && (bullet->posX >= 2 || bullet->posX <= 150)) {
		bullet->posX += 1;
	}
}

void removeBullet(bullet_t* bullet) {
	gotoxy(bullet->posX,bullet->posY);
	printf("%c", 32);
}

static int score = 0;

// interactions
void interactionsPlayerBulletHitEnemy(enemies_t enemies[], bullet_t* bullet ){

	for (int i = 0; i < 5; i++) { //5 skal ændres til enemy count, men det kan Liou måske gøre?
		if (bullet->posX == enemies[i].posX && bullet->posY == enemies[i].posY && enemies[i].life > 0 || (bullet->posX == enemies[i].posX-1 && bullet->posY == enemies[i].posY && enemies[i].life > 0)) {
			enemies[i].life--;
			score++;
		}
	}

	int scoreOneOffset = 7;
	int scoreTenOffset = 6;
	int scoreOne = score % 10;
	int scoreTen = score / 10;

	for(int j = 0; j < 5; j++){
		buffer[j+(scoreOneOffset * 5)+(128 * 2)] = character_data[scoreOne + 16][j];
	}
	lcd_push_buffer(buffer);

	for(int j = 0; j < 5; j++){
		buffer[j+(scoreTenOffset * 5)+(128 * 2)] = character_data[scoreTen + 16][j];
	}
	lcd_push_buffer(buffer);
}

void interactionsPlayerBulletHitBoss(boss_t boss[], bullet_t* bullet ){
	for (int i = 0; i < 1; i++) { //5 skal ændres til enemy count, men det kan Liou måske gøre?
		if (bullet->posX == boss[i].posX && bullet->posY == boss[i].posY && boss[i].life > 0) {
			boss[i].life-- ;
			score++;
		}

	}
}

int8_t numAsteroids = 5;

int32_t calculateDistance(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
	int32_t dx = x2 - x1 < 0 ? x1 - x2 : x2 - x1;
	int32_t dy = y2 - y1 < 0 ? y1 - y2 : y2 - y1;
	int32_t sum = dx + dy;
	return sum;  //manhatten distance (faster than using euclidian(sqrt))
}

/*
#include "bullet.h"
#include "spaceship.h"
#include "uart.h"
#include "asteroids.h"
#include "lut.h"

void initBullet(bullet_t* bullet,spaceship_t* spaceship){
	bullet->posX = spaceship->posX +2;
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
	if (bullet->true && (bullet->posX >= 150 || bullet->posX <= 2)){
		bullet->posX += 0;
		bullet->velX = 0;
		removeBullet(bullet);
		bullet->true = 0;
	} else if(bullet->true && (bullet->posX >= 2 || bullet->posX <= 150)) {
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




//jeg har skrevet herfra mht. gravity

uint8_t gravity = 3;
uint8_t damping = 40;

int32_t calculateDistance(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
    int32_t dx = x2 - x1;
    int32_t dy = y2 - y1;
    return dx + dy;  //manhatten distance (hurtigere end at bruge euclidian(sqrt))
}

int8_t isAffectedByGravity = 0;


void updateBullet(bullet_t* bullet, asteroid_t* asteroid, int numAsteroids) {
    if (bullet->true && (bullet->posX >= 150 || bullet->posX <= 2)) {
        bullet->posX += 0;
        bullet->velX = 0;
        removeBullet(bullet);
        bullet->true = 0;
    } else if (bullet->true && (bullet->posX >= 2 || bullet->posX <= 150)) {
        bullet->posX += 1;
        bullet->velX = 1;

        bullet->posX += bullet->velX;
        bullet->posY += bullet->velY;

        // Apply gravity to the vertical velocity
        for (int i = 0; i < numAsteroids; i++) {
            int32_t distance = calculateDistance(bullet->posX, bullet->posY, asteroid[i].posX, asteroid[i].posY);
            if (distance <= asteroid[i].posY + asteroid[i].radius && bullet->posY < asteroid[i].posY && bullet->posX > asteroid[i].posX) {   //asteroid[i].radius) {
                //int32_t diffX = asteroid[i].posX - bullet->posX;
                int32_t diffY = asteroid[i].posY - bullet->posY;
                int32_t distanceSquared = distance * distance;
               // int32_t gravityForceX = (diffX * gravity) / distanceSquared;
                int32_t gravityForceY = (diffY * gravity) / distanceSquared;

             //   bullet->velX += gravityForceX;
                  bullet->velY += gravityForceY;

                // Apply damping to gradually reduce the velocity
              //  bullet->velX = (bullet->velX * damping) / 100;
                bullet->velY = (bullet->velY * damping) / 100;

               // break; // Exit the loop if at least one asteroid is nearby
            } else if(distance <= asteroid[i].posY + asteroid[i].radius  && bullet->posY > asteroid[i].posY && bullet->posX > asteroid[i].posX) {   //asteroid[i].radius) {
                int32_t diffX = asteroid[i].posX - bullet->posX ;
                int32_t diffY = (asteroid[i].posY - bullet->posX);
                int32_t distanceSquared = distance * distance;
                int32_t gravityForceX = (diffX * gravity) / distanceSquared;
                int32_t gravityForceY = ((diffY * gravity) / distanceSquared );

                bullet->velX += gravityForceX;
                bullet->velY += gravityForceY;

                // Apply damping to gradually reduce the velocity
                bullet->velX = (bullet->velX * damping) / 100;
                bullet->velY = (bullet->velY * damping) / 100;

               // break; // Exit the loop if at least one asteroid is nearby
            }

        }
    }
}


 */











