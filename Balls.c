#include "Balls.h"
#include "asteroids.h"

uint8_t gravity = 6;

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

int32_t calculateDistance(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
    int32_t dx = x2 - x1;
    int32_t dy = y2 - y1;
    return dx + dy;  //manhatten distance (hurtigere end at bruge euclidian(sqrt))
}

int8_t isAffectedByGravity = 0;


void updatePos(ball_t* ball, asteroid_t* asteroid, int numAsteroids) {
    int k = 1;

    ball->posX = ball->posX + ball->velX;
    ball->posY = ball->posY + ball->velY;

    // Check proximity to each asteroid
    for (int i = 0; i < numAsteroids; i++) {
    	int32_t distance = calculateDistance(ball->posX, ball->posY, asteroid[i].posX, asteroid[i].posY);
    	if (distance <= asteroid[i].radius) {
    		isAffectedByGravity = 1; // Set the flag to indicate gravity effect
    		if (isAffectedByGravity) {
    		    			int32_t diffX = asteroid[i].posX - ball->posX;
    		    			int32_t diffY = asteroid[i].posY - ball->posY;
    		    			int32_t distanceSquared = distance * distance;

    		    			//ball->velX += FIX14_DIV(FIX14_MULT(diffX, gravity), distanceSquared);
    		    			//ball->velY += FIX14_DIV(FIX14_MULT(diffY, gravity), distanceSquared);
    					ball -> velX += (diffX*gravity/distanceSquared);
    					ball -> velY += (diffY*gravity/distanceSquared);
    		    			 //ball->velY = ball-> velY + gravity;// Apply gravity to the vertical velocity
    		    		}
    		break; // Exit the loop if at least one asteroid is nearby
    	} else {
    		isAffectedByGravity = 0; // Reset the flag if no asteroid is nearby
    	}
    }
   // (diffX*g*gravityforce/(distance *distance)
   /* if (isAffectedByGravity) {     //lav function der tjekker om den er eller ej i stedet.
    	  ball-> velX = ((ball -> velX) * gravity)/(distance * distance);

         // ball->velY = ball-> velY + gravity;// Apply gravity to the vertical velocity
          //ball->velX = ball-> velX + gravity;
      	//ball->velX =0;
      	//ball->velY =0;
      } */



    if (ball->posY >= 23 || ball->posY <= 2) {
        ball->velY *= -1;
        ball->hit++;
    } else if (ball->posX >= 49 || ball->posX <= 2) {
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



