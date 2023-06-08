#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "ansi.h"
#include "vector.h"
#include "Balls.h"
#include "pins.h"
#include "timers.h"



int main(void)
{
	// Setup communication with the PC
	uart_init(115200);
	clrscr();
	hideCursor();
	initPins();
	configTimer();
	while(1){
		prntClk();
	}


	/*
	initPins();
	while(1){
		setLed();
	}
*/

/*
	//kode til at lave window
	clrscr();
	bgcolor(0);
	fgcolor(15);
	gotoxy(0,0);
	window2(0, 0, 50, 50, 2);

	//initialize the ball start point and velocity
	ball_t ball;
		initBalls(&ball);
		ball.posX = 2;
		ball.posY = 2;
		ball.velX = 1;
		ball.velY = 1;
		ball.hit = 0;
	while(1){
			showBalls(&ball); //draw a ball
		for(int i = 0; i < 250000; i++){
			if(i==249999){
				removeBall(&ball); //remove the old ball
				updatePos(&ball); //update position of the ball
				displayHit(&ball); //update hit counter and redraw small-window

		}
	}
}
*/

/*
	vector_t vec;
	initVector(&vec);

	vec.x = 1;
	vec.y = 2;
	int deg = 256;

	rotateVector(&vec,deg);
	printf("(%d,%d) \n", vec.x, vec.y);
*/

	//kode til at lave window
	/*
	clrscr();
	bgcolor(0);
	fgcolor(15);
	window(5,5,20,20,196);
	*/


	/*
		printFix(expand(sinCalc(64)));
		printf("\n");
		printFix(expand(sinCalc(-111)));
		printf("\n");
		printFix(expand(cosCalc(-111)));
		printf("\n");
		printFix(expand(cosCalc(923)));
		printf("\n");

	*/
	while (1) {}
}






