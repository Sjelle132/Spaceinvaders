

#ifndef ASTEROIDS_H_
#define ASTEROIDS_H_
#include "stm32f30x_conf.h"

typedef struct {
    int32_t posX, posY;
    int8_t life;
} asteroid_t;


void initAsteroid(asteroid_t asteroid[]);
void drawAsteroid(asteroid_t asteroid[]);
void removeAsteroid(asteroid_t asteroid[]);



#endif /* ASTEROIDS_H_ */
