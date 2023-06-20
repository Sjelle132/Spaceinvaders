
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
#include "asteroids.h"


int main(void)
{
	// Setup communication with the PC
	uart_init(1048576);

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

	// initialize the asteroid
	asteroids_t asteroid[numAsteroids];
	initAsteroids(asteroid);

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

		//Reads gameState in order to change LED color between red and green.
		setLedForGame(stateReader);


		//Function that checks for enemy lives
		int8_t EnemyLivesCount = isAllEnemyDead(enemies, &spaceship);

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


			drawAsteroid(asteroid);
			removeAsteroid(asteroid);


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
					applyGravity(asteroid, &bullet[j]);
					collisionDetectionA(asteroid, &bullet[j]);
					interactionsPlayerBulletHitEnemy(enemies, &bullet[j]);
					interactionsPlayerBulletHitBoss(boss, &bullet[j] );

				}
			}


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

			if (elapsed_time_enemy  >= 200 && EnemyLivesCount == 0) {
				elapsed_time_enemy  = 0;
				updateBoss(boss);
			}

			//createBoss(boss);
			//removeBoss(boss);

			if (elapsed_time_Boss >= 20 && EnemyLivesCount == 0) {
				elapsed_time_Boss = 0;
				updateBossShoot(bossBullet, boss);
				interactionsBossBulletHitPlayer(bossBullet, &spaceship);
			}


			if (spaceship.life == 0){
				stateGameOver();
			}
		}
	}
	while (1){}
}
