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

typedef struct {

	int16_t posX;
	int16_t posY;
	int16_t velX;
	int16_t velY;
	int8_t true;

} bullet_t;

void initBullet(bullet_t* bullet, spaceship_t* spaceship);
void createBullet(bullet_t* bullet);
void updateBullet(bullet_t* bullet);
void removeBullet(bullet_t* bullet);
void spawnBullet(bullet_t* bullet);


#endif /* BULLET_H_ */
