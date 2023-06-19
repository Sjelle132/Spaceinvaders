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
#include "asteroids.h"

typedef struct {
	int16_t posX;
	int16_t posY;
	int16_t velX;
	int16_t velY;
	int8_t true;
} bullet_t;

void initBullet(bullet_t* bullet, spaceship_t* spaceship);
uint32_t calculateDistance(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
void createBullet(bullet_t* bullet);
void updateBullet(bullet_t* bullet);
//void updateBullet(bullet_t* bullet,asteroid_t* asteroid, int numAsteroid);
void removeBullet(bullet_t* bullet);
void spawnBullet(bullet_t* bullet);
void collisionDetectionA(asteroid_t asteroid[], bullet_t* bullet);
void applyGravity(asteroid_t asteroid[],bullet_t* bullet, int8_t numAsteroids);



#endif /* BULLET_H_ */
