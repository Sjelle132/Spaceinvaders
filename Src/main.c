
#include <states.h>
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
#include "gameState.h"
#include "enemies.h"
#include "boss.h"


int main(void)
{
	// Setup communication with the PC
	uart_init(115200);

	//initializing parameters and create windows
	initWindow();
	initPins();
	configTimer();
	windowStart();
	uint8_t currentState = StartMenu;
	lcd_t lcd;
	initlcd(&lcd);
	lcdWriteText("Health: ***", 0);
	lcdWriteText("Time:", 1);
	lcdWriteText("Score:", 2);

	//initialize enemies
	enemies_t enemies[5];
	initEnemies(enemies);

	//init enemy bullets
	enemyBullet_t enemyBullet[5];
	initEnemyBullet(enemies,enemyBullet);

	//init boss
	boss_t boss[1];
	initBoss(boss);

	//init boss bulets
	bossBullet_t bossBullet[1];
	initBossBullet(bossBullet, boss);


	//initialize the spaceship start point and velocity
	spaceship_t spaceship;
	initSpaceship(&spaceship);

	//initialize bullet array
	bullet_t bullet[10];

	//spawns bullet out of map
	for(int8_t i=0; i < 10; i++){
		spawnBullet(&bullet[i]);
	}

	//initialize flags for bullet and spaceship
	int16_t flagspaceship = 0;
	int8_t i = 0;
	int32_t spawntime = 0;


	//main loop
	while(1){
		int8_t EnemyLivesCount = isAllEnemyDead(enemies, &spaceship);

		gotoxy(6,6);
		printf("%02d", EnemyLivesCount);

		//reading states
		if(stateReader == 1 && stateStartGame == 0){
			uint8_t inputKB = uart_get_char();
			uint8_t newState = processInput(currentState, inputKB, &spaceship);

			if (newState != currentState){
				stateUpdate(newState);
				currentState = newState;
			}
		}

		else if(stateStartGame == 1 && stateReader == 0 && EnemyLivesCount > 0){
			TIM15->CR1 = 1;
			lcdTimeDisplay();
			//reads keyboard input all the time
			uint8_t directionState = keyboardController();

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
			for (int j = 0; j < 10; j++){
				createBullet(&bullet[j]);
			}

			//for each b click, move bullet to spaceship xy coordinates
			if(64 == directionState && !(spawntime == returnHNDR())){
				removeBullet(&bullet[i]);
				initBullet(&bullet[i], &spaceship);
				if(i<10)
					i++;
				if(i>=10)
					i=0;
				spawntime=returnHNDR();
			}

			if (elapsed_time_PlayerBullet >= 100 ){
				elapsed_time_PlayerBullet = 0;
				bullet->true = 1;
				for (int j = 0; j < 10; j++){
					removeBullet(&bullet[j]);
					updateBullet(&bullet[j]);
					interactionsPlayerBulletHitEnemy(enemies, &bullet[j]);
					interactionsPlayerBulletHitBoss(boss, &bullet[j] );
				}
			}

			/*
			 * Regel:
			 * For det gældende object der trackes og mister liv, skal interactionen ligge i tilhørende elapsed time
			 * Altså når vi tracker om enemies bliver ramt, ligger dens interaction i elapsed_time_enemy
			 * Dermed opdateres tracking af om bullets rammer synkront med opdatering af enemies.
			 *
			 */

			//Updating enemies
			if (elapsed_time_enemy  >= 200 ) {
				elapsed_time_enemy  = 0;
				updateEnemies(enemies);
				updateBoss(boss);
			}
			createEnemies(enemies);
			removeEnemies(enemies);

			if (elapsed_time >= 100 ) {
				elapsed_time = 0;
				updateEnemyShoot(enemyBullet,enemies);
				interactionsEnemyBulletHitPlayer(enemyBullet, &spaceship);
			}

			enemyShoot(enemyBullet,enemies);
			removeEnemyShoot(enemyBullet);


			bossShoot(bossBullet,boss);
			removeBossShoot(bossBullet);

		}


		if (elapsed_time_enemy  >= 200 && EnemyLivesCount == 0) {
			elapsed_time_enemy  = 0;
			updateBoss(boss);
		}

		createBoss(boss);
		removeBoss(boss);

		if (elapsed_time_Boss >= 20 && EnemyLivesCount == 0) {
			elapsed_time_Boss = 0;
			updateBossShoot(bossBullet, boss);
			interactionsBossBulletHitPlayer(bossBullet, &spaceship);
		}


		if (spaceship.life == 0){
			stateGameOver();
		}
	}

	/*

	clrscr();
	gotoxy(0,0);
	windowStart();
	uint8_t currentState = StartMenu;

	while(1){
		uint8_t inputKB = uart_get_char();
		uint8_t newState = processInput(currentState, inputKB);  // Temporary variable to hold the new state

		if (newState != currentState){
			stateUpdate(newState);
			currentState = newState;
		}
	}
	 */
	/*

	uart_init(115200);
	clrscr();
	gotoxy(0,0);
	uint8_t currentState = StartMenu;
	windowStart();

	while(1){
		uint8_t inputKB = uart_get_char();
		uint8_t newState = currentState;  // Temporary variable to hold the new state

		if (currentState == StartMenu) {
			if (inputKB == 'p' ) {
				newState = 1;
			}
		}

		if (currentState == MainMenu) {
			if (inputKB == '1') {
				newState = SelDif;
			} else if (inputKB == '2') {
				newState = Help;
			} else if (inputKB == '3') {
				newState = MainMenu;
			}
		}

		if (currentState == SelDif){
			if (inputKB == '1' || inputKB == '2' || inputKB == '3'){
				newState = Game;
			} else if (inputKB == '4'){
				newState = MainMenu;
			}
		}

		if (currentState == Game){
			if (inputKB == 'b'){
				newState = MainMenu;
			}
		}

		if (currentState == Help){
			if (inputKB == '1'){
				newState = MainMenu;
			}
		} //else if (currentState == Game)

		if (newState != currentState) {
			switch(newState) {
			case 1:
				windowMainMenu();
				break;
			case 2:
				windowSelDif();
				break;
			case 3:
				windowHelp();
				break;
			case 4:
				windowGame();
				break;
			case 5:
				break;
			}

			currentState = newState;
		}
	}

	 */


	/*
	uart_init(115200);
	clrscr();
	gotoxy(0,0);
	uint8_t currentState = 0;
	uint8_t nextState = 0;
	uint8_t state = 0;

	while(1){
		uint8_t inputKB = uart_get_char();
		if(inputKB == 'p' && (currentState == 0 || currentState == 2 || currentState == 3)){
			nextState = 1;
		} else if (inputKB == '1' && currentState == 1){
			nextState = 2;
		} else if (inputKB == '2' && currentState == 1){
			nextState = 3;
		} else if (inputKB == '3' && currentState == 1){
			nextState = 4;
		} else if (inputKB == '4' && currentState == 1){
			nextState = 5;
		} else{

		}

		if (nextState != currentState){
			nextState = nextState;
		}

		switch(nextState){
		case 0:
			windowStart();
			break;
		case 1:
			windowMainMenu();
			break;
		case 2:
			windowSelDif();
			break;
		case 3:
			windowHelp();
			break;
		case 4:
			windowHelp();
			break;
		case 5:
			windowGame();
			break;
		}


		currentState = nextState;
		nextState = 0;
	}
	 */




	/*

	//Exercise 6 - display on LCD screen
	clrscr();
	lcd_t lcd;
	initlcd(&lcd);
	lcdWriteText("Health: ***", 0);
	lcdWriteText("Time:", 1);
	lcdWriteText("Score:", 2);

	//Exercice 6.2
	initPins();
	configTimer();
	while (1) {
		prntClk();
		lcdTimeDisplay();
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
