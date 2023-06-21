/*
 * enemies.h
 *
 *  Created on: 13. jun. 2023
 *      Author: oscar
 */

#ifndef ENEMIES_H_
#define ENEMIES_H_

#include "stm32f30x_conf.h"
#include "spaceship.h"
#include "lcd.h"
#include "pins.h"
#include "uart.h"
#include <math.h>
#include "vector.h"
#include "timers.h"


typedef struct {
	int16_t posX;
	int16_t posY;
	int16_t velX;
	int16_t velY;
	uint8_t life;
} enemies_t;

typedef struct {
	int16_t posX;
	int16_t posY;
	int8_t true;
} enemyBullet_t;


void initEnemies(enemies_t enemies[]);
void createEnemies(enemies_t enemies[]);
void updateEnemies(enemies_t enemies[], spaceship_t* spaceship);
void removeEnemies(enemies_t enemies[]);

void initEnemyBullet(enemies_t enemies[],enemyBullet_t enemyBullet[]) ;
void enemyShoot(enemyBullet_t enemyBullet[],enemies_t enemies[]);
void updateEnemyShoot(enemyBullet_t enemyBullet[], enemies_t[]);
void removeEnemyShoot(enemyBullet_t enemyBullet[]);

void interactionsEnemyBulletHitPlayer(enemyBullet_t enemyBullet[], spaceship_t* spaceship);
uint16_t isAllEnemyDead(enemies_t enemies[] ,spaceship_t* spaceship);


#endif /* ENEMIES_H_ */
