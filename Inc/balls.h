/*
 * balls.h
 *
 *  Created on: 6 Jun 2023
 *      Author: liou-
 */

#ifndef BALLS_H_
#define BALLS_H_
#include "stdio.h"
#include "stdint.h"
#include "stm32f30x_conf.h"

typedef struct{
	int32_t posX, posY, velX, velY , hit;
} ball_t;

void initBalls(ball_t* b);
void updatePos(ball_t* ball);
void showBalls(ball_t* b);
void displayHit(ball_t* b);
void removeBall(ball_t* b);

#endif /* BALLS_H_ */
