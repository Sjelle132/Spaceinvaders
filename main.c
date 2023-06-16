#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "ansi.h"
#include "vector.h"
#include "Balls.h"
#include "pins.h"
#include "timers.h"
#include "asteroids.h"


int main(void)
{
	// Setup communication with the PC
	uart_init(115200);

	//kode til at lave window
	clrscr();
	hideCursor();
	bgcolor(0);
	fgcolor(15);
	gotoxy(0,0);
	window2(0, 0, 50, 50, 2);


	// initialize the asteroid
	asteroid_t asteroid;
	initAsteroids(&asteroid);
	asteroid.posX = 28;
	asteroid.posY = 14;
	int numAsteroids = 1; // update the number of asteroids


	//initialize the ball start point and velocity
	ball_t ball;
	initBalls(&ball);
	ball.posX = 2;
	ball.posY = 2;
	ball.velX = 1;
	ball.velY = 1;
	ball.hit = 0;
	while (1) {
	    showBalls(&ball); // draw a ball
	    //showAsteroid(&asteroid); //draw asteroid
	    drawAsteroid(&asteroid);

	    for (int i = 0; i < 250000; i++) {
	        if (i == 249999) {
	            removeBall(&ball); // remove the old ball
	            updatePos(&ball, &asteroid, numAsteroids); // update position of the ball
	            displayHit(&ball); // update hit counter and redraw small-window
	        }
	    }
	}
}






