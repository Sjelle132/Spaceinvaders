#ifndef ASTEROIDSH
#define ASTEROIDSH
#include "stm32f30x_conf.h"

typedef struct{
    int32_t posX, posY;
    int8_t radius;
    int8_t life;
    int16_t velY;
    int16_t velX;
} asteroid_t;


void initAsteroid(asteroid_t asteroid[]);
void drawAsteroid(asteroid_t asteroid[]);
void updateAsteroid(asteroid_t asteroid[]);
void removeAsteroid(asteroid_t asteroid[]);
#endif /* ASTEROIDSH */

