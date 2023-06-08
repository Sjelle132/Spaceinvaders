/*
 * Balls.c
 *
 *  Created on: Jun 6, 2023
 *      Author: oscar
 */
#include "Balls.h"

void initBalls(ball_t* b){
	b->posX = 0;
	b->posY = 0;
	b->velX = 0;
	b->velY = 0;
	b->hit = 0;
}

void removeBall(ball_t* ball){
	gotoxy(ball->posX,ball->posY);
	printf("%c", 32);
}

void updatePos(ball_t* ball){
	int k = 1;
	ball->posX = ball->posX + ball->velX; //*ball->posX * k;
	ball->posY = ball->posY + ball->velY; // *ball->posY * k;
		if (ball->posY >= 23 || ball->posY <= 2 ){
			ball->velY *= -1;

			ball->hit++;
		}else if (ball->posX >= 49 || ball->posX <= 2){
			ball->velX *= -1;

			ball->hit++;
		}


}

void showBalls(ball_t* g){
	gotoxy(g->posX,g->posY);
	printf("%c", 111);
}

void displayHit(ball_t* g){
	window2(10, 20, 28, 14, 1);
	gotoxy(22,10);
	printf("%d hits", g->hit);
}


