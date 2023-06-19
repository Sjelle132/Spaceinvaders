/*
 * bullet.h
 *
 *  Created on: 11. jun. 2023
 *      Author: oscar
 */

#ifndef BULLET_H_
#define BULLET_H_


#include "stm32f30x_conf.h"
#include "spaceship.h"
#include "enemies.h"
#include "ansi.h"
#include "lcd.h"
#include "boss.h"

typedef struct {

	int16_t posX;
	int16_t posY;
	int16_t velX;
	int16_t velY;
	int8_t true;
	char score;

} bullet_t;
void initBullet(bullet_t* bullet, spaceship_t* spaceship);
void createBullet(bullet_t* bullet);
void updateBullet(bullet_t* bullet);
void removeBullet(bullet_t* bullet);
void spawnBullet(bullet_t* bullet);
//void drawAllBullets(bullet_t* bullet,spaceship_t* spaceship);
//void updateBullet(bullet_t* bullet, asteroid_t* asteroid, int numAsteroids);


void interactionsPlayerBulletHitEnemy(enemies_t enemies[], bullet_t* bullet );
void interactionsPlayerBulletHitBoss(boss_t boss[], bullet_t* bullet );
#endif /* BULLET_H_ */
