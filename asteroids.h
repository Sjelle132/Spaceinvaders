

#ifndef ASTEROIDS_H_
#define ASTEROIDS_H_
#include "stm32f30x_conf.h"

typedef struct{
	int32_t posX, posY;
	int8_t radius;
	int8_t life;
} asteroid_t;


void initAsteroids(asteroid_t* asteroid);
void showAsteroid(asteroid_t* g);

#endif /* ASTEROIDS_H_ */
