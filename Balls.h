
#ifndef BALLS_H_
#define BALLS_H_
#include "stm32f30x_conf.h"
#include "asteroids.h"
#include "math.h"
#define FIX14_SHIFT 14
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )
#define FIX14_DIV(a, b) ( ((a) << FIX14_SHIFT) / b )

typedef struct{
	int32_t posX, posY, velY,velX;
	 int hit;
	 int isAffectedByGravity;
} ball_t;

void initBalls(ball_t* b);
void updatePos(ball_t* ball, asteroid_t* asteroid, int numAsteroids);
void showBalls(ball_t* g);
void removeBall(ball_t* ball);
void displayHit(ball_t* g);
int32_t calculateDistance(int32_t x1, int32_t y1, int32_t x2, int32_t y2);

#endif /* BALLS_H_ */
