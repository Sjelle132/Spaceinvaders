/*
 * enemies.h
 *
 *  Created on: 13. jun. 2023
 *      Author: oscar
 */

#ifndef ENEMIES_H_
#define ENEMIES_H_

#include "stm32f30x_conf.h"

typedef struct {

	int16_t posX;
	int16_t posY;
	int16_t velX;
	int16_t velY;
	int8_t life;

} enemies_t;

typedef struct {

	int16_t posX;
	int16_t posY;
	int16_t velX;
	int16_t velY;
	int8_t life;

} eliteEnemy_t;

void initEliteEnemy(eliteEnemy_t* EliteEnemy);
void initEnemies(enemies_t enemies[]);
void createEnemies(enemies_t enemies[],int8_t f);
void updateEnemies(enemies_t enemies[],int8_t f);

#endif /* ENEMIES_H_ */
