#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "ansi.h"
#include "vector.h"
#include "Balls.h"
#include "pins.h"
#include "timers.h"
#include "uart.h"
#include "spaceship.h"
#include "bullet.h"
#include "enemies.h"
#include "asteroids.h"



int main(void)
{
	// Setup communication with the PC
	uart_init(115200);
	clrscr();

	//init param and create window
	clrscr();
	bgcolor(0);
	fgcolor(15);
	gotoxy(0,0);
	window2(0, 0, 150, 300, 2);
	hideCursor();
	initPins();
	configTimer();


	//init enemies

	enemies_t enemies[3];
	initEnemies(enemies);


	//init asteroids
	/*asteroid_t asteroid;
	initAsteroids(&asteroid);
	int numAsteroids = 1;
*/
	//initialize the spaceship start point and velocity
	spaceship_t spaceship;
	initSpaceship(&spaceship);

	//initialize bullet array
	bullet_t bullet[10];

	//spawns bullet out of map
	for(  int8_t i=0; i<10; i++)
		spawnBullet(&bullet[i]);

	//initialize flags for bullet and spaceship
	int32_t flagbullet = 0;
	int16_t flagspaceship = 0;
	int8_t i = 0;
	int32_t spawntime=0;
	int16_t flagenemies = 0;

	int flagTest = 0;

	//main loop
	while(1){




		//reads keyboard input all the time
		uint8_t directionState = keyboardController();

		//drawAsteroid(&asteroid);

		//spaceship create and position update
		createSpaceship(&spaceship); //draw spaceship
		if(!(returnSec() == flagspaceship)){
			if (directionState == 1 || directionState == 2 || directionState == 4 || directionState == 8){
				removeSpaceship(&spaceship); //remove the old spaceship
				updateSpaceship(&spaceship,directionState); //update position of the spaceship

			}
		}
		flagspaceship=returnMilisec();



		//creates 10 bullets
		for (int j = 0; j < 10; j++)
			createBullet(&bullet[j]);

		//for each b click, move bullet to spaceship xy coordinates
		if(64 == directionState && !(spawntime ==returnHNDR())){
			removeBullet(&bullet[i]);
			initBullet(&bullet[i],&spaceship);
			if(i<10)
				i++;
			if(i>=10)
				i=0;
			spawntime=returnHNDR();
		}


		//bullet run path and speed //also updates pos of bullet
		if (!(returnHNDR() == flagbullet)){
			bullet->true = 1;
			for (int j = 0; j < 10; j++){

				removeBullet(&bullet[j]);
				updateBullet(&bullet[j]);

			}

		}
		flagbullet=returnHNDR();

		//enemies interaction


		createEnemies(enemies,&flagenemies);

			updateEnemies(enemies,&flagenemies,tid.flag);
			removeEnemies(enemies,&flagenemies,tid.flag);





	}









	/*
	uart_clear();
	while(1){

		smthFunny1();

	}
	 */

	/*
	clrscr();
	hideCursor();
	initPins();
	configTimer();
	while(1){
		prntClk();
	}
	 */

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






