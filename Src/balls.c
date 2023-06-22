/*
 * balls.c
 *
 *  Created on: 6 Jun 2023
 *      Author: liou-
 */
#include "balls.h"
#include "stdio.h"
#include "stdint.h"
#include "stm32f30x_conf.h"


void initBalls(ball_t* balls){
	balls->posX = 3;
	balls->posY = 3;
	balls->velX = 1;
	balls->velY = 1;
	balls->hit = 0;
}

void updatePos(ball_t* ball){
	if(ball->posY > 10 || ball->posY <= 2){
		ball->velY *= -1;
		ball->hit += 1;
	}
	if(ball->posX >= 15 || ball->posX <= 2){
		ball->hit += 1;
	}

	ball->posX = ball->posX + ball->velX;
	ball->posY = ball->posY + ball->velY;
}

void showBalls(ball_t* b){
	gotoxy(b->posX, b->posY);
	printf("%c", 111);
}

void displayHit(ball_t* b){
	window2(20,10,27,12,1);
	gotoxy(11,21);
	printf("%d Hits\n", b->hit);
}

void removeBall(ball_t* b){
	gotoxy(b->posX, b->posY);
	printf("%c", 32);
}
