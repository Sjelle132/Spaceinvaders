

#ifndef ASTEROIDS_H_
#define ASTEROIDS_H_

#include "stm32f30x_conf.h"
#include "bullet.h"

typedef struct {

    int32_t posX, posY;
    int8_t life;

} asteroids_t;

void initAsteroids(asteroids_t asteroid[]);
void drawAsteroid(asteroids_t asteroid[]);
void removeAsteroid(asteroids_t asteroid[]);

void applyGravity(asteroids_t asteroid[], bullet_t* bullet);
void collisionDetectionA(asteroids_t asteroid[], bullet_t* bullet);


#endif /* ASTEROIDS_H_ */
