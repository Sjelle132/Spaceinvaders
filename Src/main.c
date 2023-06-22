#include "30010_io.h"
#include "ansi.h"
#include "asteroids.h"
#include "boss.h"
#include "bullet.h"
#include "balls.h"
#include "charset.h"
#include "enemies.h"
#include "lcd.h"
#include "lut.h"
#include "states.h"
#include "stm32f30x_conf.h"
#include "stdio.h"
#include "stdint.h"
#include "spaceship.h"
#include "timers.h"
#include "uart.h"
#include "vector.h"
#include "window.h"
#include "pins.h"
#include "powerup.h"

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

	//initialize lcd
	initlcd();
	lcdWriteText("Health:", 0);
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

	//init powerups
	powerup_t powerup;
	initPowerup(&powerup);

	//initialize flags for bullet and spaceship
	int8_t flagspaceship = 0;
	int8_t i = 0;
	int16_t spawntime = 0;
	int8_t bossCreated = 0;



	//main loop
	while(1){
		//Reads gameState in order to change LED color between red and green.
		setLedForGame(stateStartGame);

		if(!stateStartGame){
			//reading states
			uint8_t inputKB = uart_get_char();
			uint8_t newState = processInput(currentState, inputKB, spaceship.life);

			if (newState != currentState){
				stateUpdate(newState);
				currentState = newState;
			}

			if(spaceship.life == 0){
				spaceship.life = 3;
				initSpaceship(&spaceship);
				initEnemies(enemies);
				initEnemyBullet(enemies,enemyBullet);
				initAsteroids(asteroid);
				initPowerup(&powerup);
				score = 0;
				configTimer();
				resetTimers();
				for (int j = 0; j < 10; j++){
					removeBullet(&bullet[j]);
					spawnBullet(&bullet[j]);
				}
			}
		}

		else if(stateStartGame){
			//enable clock
			TIM15->CR1 = 1;

			//different displays on LCD
			lcdHealthDisplay(spaceship.life);
			lcdTimeDisplay();
			lcdScoreDisplay();

			//draw and remove objects
			drawAsteroid(asteroid);
			createEnemies(enemies);
			removeEnemies(enemies);
			enemyShoot(enemyBullet, enemies);
			removeEnemyShoot(enemyBullet);

			//display powerup
			drawPowerup(&powerup);

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

			//Detects if powerup is picked up
			collisionDetection(&powerup, &spaceship);

			//If powerup is picked up, functions lasts for 10 sec.
			if (powerup.flag == 1){
				if (elapsed_time_powerup >= 10000 ){
					elapsed_time_powerup = 0;
					powerup.flag = 0;
				}
			}

			//creates 10 bullets
			for (int j = 0; j < 10; j++){
				createBullet(&bullet[j]);
			}

			//for each b click, move bullet to spaceship xy coordinates
			if(64 == directionState && !(spawntime == returnHNDR())){
				removeBullet(&bullet[i]);
				initBullet(&bullet[i], &spaceship);
				if(i < 10)
					i++;
				if(i >= 10)
					i = 0;
				spawntime=returnHNDR();
			}

			//bullet animation and interaction
			if (elapsed_time_playerBullet >= playerBulletSpeed ){
				elapsed_time_playerBullet = 0;
				bullet->true = 1;
				for (int j = 0; j < 10; j++){
					removeBullet(&bullet[j]);
					updateBullet(&bullet[j]);
					applyGravity(asteroid, &bullet[j]);
					interactionsPlayerBulletHitEnemy(enemies, &bullet[j]);
					interactionsPlayerBulletHitBoss(boss, &bullet[j] );
				}
			}

			//Updating enemies
			if (elapsed_time_enemyMovement  >= enemyMovementSpeed ) {
				elapsed_time_enemyMovement  = 0;
				updateEnemies(enemies, &spaceship,powerup.flag);
			}

			//Update enemies bullet & interaction
			if (elapsed_time_enemyBullet >= enemyBulletSpeed ) {
				elapsed_time_enemyBullet = 0;
				updateEnemyShoot(enemyBullet,enemies);
				interactionsEnemyBulletHitPlayer(enemyBullet, &spaceship);
			}

			//sum of all HP from enemies
			uint16_t EnemyLivesCount = isAllEnemyDead(enemies, &spaceship);
			if(EnemyLivesCount <= 0 && !bossCreated){
				initBoss(boss);
				bossCreated = 1;
			}

			//boss key
			if(bossCreated){
				if (elapsed_time_bossMovement >= bossMovementSpeed) {
					elapsed_time_bossMovement = 0;
					updateBoss(boss);
				}

				if (elapsed_time_bossBullet >= bossBulletSpeed) {
					elapsed_time_bossBullet = 0;
					updateBossShoot(bossBullet, boss);
					interactionsBossBulletHitPlayer(bossBullet, &spaceship);
				}

				createBoss(boss);
				removeBoss(boss);
				bossShoot(bossBullet,boss);
				removeBossShoot(bossBullet);
			}

			//level up
			if(bossCreated && boss->life <= 0){
				initEnemies(enemies);
				initBoss(boss);
				initPowerup(&powerup);
				bossCreated = 0;
				enemyBulletSpeed -= 10;
				enemyMovementSpeed -= 10;
				bossMovementSpeed -= 10;
			}

			//gameover
			if (spaceship.life <= 0){
				lcdInstaDeath();
				stateGameOver(&spaceship);
			}
		}
	}
	while (1){}
}
