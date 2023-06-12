
#include "stm32f30x_conf.h" // STM32 config
#include "stdio.h"
#include "stdint.h"
#include "30010_io.h" // Input/output library for this course
#include "ansi.h"
#include "lut.h"
#include "pins.h"
#include "vector.h"
#include "balls.h"
#include "window.h"
#include "lcd.h"
#include "charset.h"
#include "timers.h"


int main(void)
{
	uart_init(115200);

	//Exercise 6 - display on LCD screen
	lcd_t llcd;
	initlcd(&llcd);
	lcd_write_text("Health: ***", 0);
	lcd_write_text("Time: ", 1);
	lcd_write_text("Score: ", 2);

	//Exercice 6.2
	initPins();
	configTimer();
	while (1) {
		prntClk();
		lcd_update();
	}


	//Exercise 5 - timer
/*	clrscr();
	gotoxy(0,0);
	initPins();
	configTimer();
	while (1) {
		prntClk();
		lcd_update();
	}
*/

		//Current project. Starting window
		//initWindow(0,0,90,90);
		/*
		 *
		 * clrscr();
		 * clrscr();color(15,0);
		 */


/*
	//Opgave 3

	window2(0, 0, 50, 50, 2);

	//Initalize the ball start point and velocity
	ball_t balls;
	initBalls(&balls);
	displayHit(&balls); //Update hit counter and redraw small-window
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 2500; j++){
			if( j == 2499){
				showBalls(&balls);
				removeBall(&balls); 			//Remove the old ball
				updatePos(&balls); 	//Update position of the ball

			}
		}
	}
*/

	//Opgave 2.2 - 2,3
/*
	gotoxy(15,5);
	vector_t vec;
	initVector(&vec);
		vec.x = -4 << 14;
		vec.y = -4 << 14;
		int32_t deg = 1280;
	printVector(vec);
	rotateVector(&vec,deg);
	gotoxy(16,5);
	printVector(vec);

*/

	//printFix(expand(calcSin(126.482736)));


	// Opgave 1
	//	windows title behøver 15
	//	window(25,0,41,20, "Windows 322", 1);
	//	window(1, 0, 20, 20, "Window 3", 2);

	//Opgave 2.1
	/*
	printFix(expand(calcSin((0))));
	printf("\n");
	printFix(expand(calcSin(64)));
	printf("\n");
	printFix(expand(calcSin(-111)));
	printf("\n");
	printFix(expand(calcSin(923)));
	printf("\n");
	printFix(expand(calcCos(0)));
	printf("\n");
	printFix(expand(calcCos(64)));
	printf("\n");
	printFix(expand(calcCos(-111)));
	printf("\n");
	printFix(expand(calcCos(923)));
	printf("\n");*/

	while (1){}
}
