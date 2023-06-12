
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
#include "spaceship.h"
#include "uart.h"
#include "bullet.h"


int main(void)
{
	uart_init(115200);

	clrscr();

	//kode til at lave window
	clrscr();
	bgcolor(0);
	fgcolor(15);
	gotoxy(0,0);
	window2(0, 0, 150, 300, 2);
	hideCursor();
	initPins();
	configTimer();




	//initialize the ball start point and velocity
	spaceship_t spaceship;
	initSpaceship(&spaceship);
	spaceship.posX = 5;
	spaceship.posY = 5;
	spaceship.velX = 0;
	spaceship.velY = 0;
	spaceship.life = 3;
	bullet_t bullet[10];
	//initBullet(&bullet,&spaceship);
	for(  int8_t i=0; i<10; i++)
		spawnBullet(&bullet[i]);
	int32_t flagbullet = 0;
	int16_t flagspaceship = 0;
	int8_t i = 0;
	int32_t spawntime=0;
	while(1){
		uint8_t directionState = keyboardController();
		createSpaceship(&spaceship); //draw spaceship
		if(!(returnMilisec() == flagspaceship)){
			removeSpaceship(&spaceship); //remove the old spaceship
			updateSpaceship(&spaceship); //update position of the spaceship
		}
		flagspaceship=returnMilisec();

		if(100 == directionState && !(spawntime ==returnSec())){
			removeBullet(&bullet[i]);
			initBullet(&bullet[i],&spaceship);
			if(i<10)
				i++;
			if(i>=10)
				i=0;
			spawntime=returnSec();
		}

		for (int j = 0; j < 10; j++)
			createBullet(&bullet[j]);

		if (!(returnSec()%4 == flagbullet)){
			bullet->true = 1;
			for (int j = 0; j < 10; j++){
				removeBullet(&bullet[j]);
				updateBullet(&bullet[j]);
			}

		}
		flagbullet=returnSec();


	}
	/*
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
	*/

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
