#ifndef ASTEROIDSH
#define ASTEROIDSH
#include "stm32f30x_conf.h"

typedef struct{
    int32_t posX, posY;
    int8_t radius;
    int8_t life;
} asteroid_t;


void initAsteroids(asteroid_t* asteroid);
void drawAsteroid(asteroid_t* g);

#endif /* ASTEROIDSH */

