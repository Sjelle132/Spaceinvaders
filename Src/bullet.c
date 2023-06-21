/*
 * bullet.c
 *
 *  Created on: 11. jun. 2023
 *      Author: oscar
 */

#include "bullet.h"

void initBullet(bullet_t* bullet,spaceship_t* spaceship){
	bullet->posX = spaceship->posX + 2;
	bullet->posY = spaceship->posY;
	bullet->true = 1;
}

void spawnBullet(bullet_t* bullet){
	bullet->posX = 1000;
	bullet->posY = 1000;
	bullet->true = 1;
}

void createBullet(bullet_t* bullet ){
	if (bullet->true) {
		gotoxy(bullet->posX, bullet->posY);
		printf("%c", 111);
	}
}

void updateBullet(bullet_t* bullet) {
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
	gotoxy(bullet->posX, bullet->posY);
	printf("%c", 32);
}

int score = 0;

// interactions
void interactionsPlayerBulletHitEnemy(enemies_t enemies[], bullet_t* bullet ){
	//If spaceship shoots enemy, life decrements
	for (int i = 0; i < 5; i++) { //5 skal ændres til enemy count, men det kan Liou måske gøre?
		if ((bullet->posX == enemies[i].posX && bullet->posY == enemies[i].posY && enemies[i].life > 0) || (bullet->posX == enemies[i].posX-1 && bullet->posY == enemies[i].posY && enemies[i].life > 0)) {
			enemies[i].life--;
			score++;
		}
	}
}

//If spaceship shoots boss, life decrements
void interactionsPlayerBulletHitBoss(boss_t boss[], bullet_t* bullet ){
	for (int i = 0; i < 1; i++) { //5 skal ændres til enemy count, men det kan Liou måske gøre?
		if (bullet->posX == boss[i].posX && bullet->posY == boss[i].posY && boss[i].life > 0) {
			boss[i].life-- ;
			score++;
		}
	}
}

int8_t numAsteroids = 5;

//Calculate the distance between bullet and asteroid
int32_t calculateDistance(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
	int32_t dx = x2 - x1 < 0 ? x1 - x2 : x2 - x1;
	int32_t dy = y2 - y1 < 0 ? y1 - y2 : y2 - y1;
	int32_t sum = dx + dy;
	return sum;  //manhatten distance (faster than using euclidian(sqrt))
}












