/*
 * Balls.h
 *
 *  Created on: Jun 6, 2023
 *      Author: oscar
 */

#ifndef BALLS_H_
#define BALLS_H_
#include "stm32f30x_conf.h"

typedef struct{
	int32_t posX, posY, velY,velX, hit;
} ball_t;

void initBalls(ball_t* b);
void updatePos(ball_t* ball);
void showBalls(ball_t* g);
void removeBall(ball_t* ball);
void displayHit(ball_t* g);

#endif /* BALLS_H_ */
