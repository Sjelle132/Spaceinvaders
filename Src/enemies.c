/*
 * enemies.c
 *
 *  Created on: 11. jun. 2023
 *      Author: oscar
 */

#include "enemies.h"
#include "pins.h"
#include "uart.h"
#include <math.h>
#include "vector.h"
#include "timers.h"

#define EnemyCount 5

void initEnemies(enemies_t enemies[]) {
	for (int i = 0; i < EnemyCount; i++){
		enemies[i].posX = 150;
		enemies[i].posY = 7+i*8;//10*i+rand()%40;
		enemies[i].velX = 0;
		enemies[i].velY = 0;
		enemies[i].life = 2;
	}
}

//create or draw enemies as array
void createEnemies(enemies_t enemies[]) {


	for (int i = 0; i < EnemyCount; i++){
		if (enemies[i].life > 0){
			gotoxy(enemies[i].posX,enemies[i].posY);

			fgcolor(2);
			printf("%c", 219);
		}
	}
}

//update enemies position
void updateEnemies(enemies_t enemies[]){
	for (int i = 0; i < EnemyCount; i++) {
		if (enemies[i].posX >= 152 || enemies[i].posX <= 3) {
			removeEnemies(enemies);
			enemies[i].life = 0;
		} else if (enemies[i].life > 0)  {
			enemies[i].posX -= 1;
			enemies[i].posX = enemies[i].posX + enemies[i].velX;
			enemies[i].posY = enemies[i].posY + enemies[i].velY;
		}
	}
}

//adds all enemy lives, and when lives == 0, assumes state should go to next lvl.
uint16_t isAllEnemyDead(enemies_t enemies[] , spaceship_t* spaceship){
	uint16_t sumEnemyLives = 0;

	for (int i = 0; i < EnemyCount; i++) {
		sumEnemyLives += enemies[i].life;
	}
/*
	for (int i = 0; i < EnemyCount; i++) {
		if (sumEnemyLives == 0 && !(enemies[i].posX == 3) && spaceship->life > 0) {
			gotoxy(10,8);
			printf("Good job, next lvl!");
		} else if (sumEnemyLives == 0 && (enemies[i].posX == 3) && spaceship->life > 0) {
			gotoxy(10,8);
			printf("Game over, you died because of enemy reach left side");
		}
	}*/
	return sumEnemyLives;
}

void removeEnemies(enemies_t enemies[]){
	for (int i = 0; i < EnemyCount; i++){
		if (enemies[i].life > 0){
			gotoxy(enemies[i].posX+1,enemies[i].posY);
			printf("%c", 32);
		}
	}
}

//init bullets from enemies

void initEnemyBullet(enemies_t enemies[],enemyBullet_t enemyBullet[]) {
	for (int i = 0; i < EnemyCount; i++){
		if (enemies[i].life > 0) {
			enemyBullet[i].posX = enemies[i].posX;
			enemyBullet[i].posY = enemies[i].posY;
			enemyBullet[i].true = 1;
		}
	}
}

//enemy shoots bullets, only one spread of bullet allowed
void enemyShoot(enemyBullet_t enemyBullet[], enemies_t enemies[]){
	for (int i = 0; i<EnemyCount;i++){
		if (enemyBullet[i].true){
			gotoxy(enemyBullet[i].posX-1,enemyBullet[i].posY);
			printf("%c", 111);
		} else if (!enemyBullet[i].true && enemies[i].life > 0) {
			enemyBullet[i].posX = enemies[i].posX;
			enemyBullet[i].posY = enemies[i].posY;
			enemyBullet[i].true = 1;
		}
	}
}

void updateEnemyShoot(enemyBullet_t enemyBullet[],enemies_t enemies[]){
	for (int i = 0; i < EnemyCount; i++) {
		if ((enemyBullet[i].posX >= 152 || enemyBullet[i].posX <= 3)){
			removeEnemyShoot(enemyBullet);
			enemyBullet[i].true = 0;
		}else if ((enemyBullet[i].posX >= 3 || enemyBullet[i].posX <= 152)) {
			enemyBullet[i].posX -= 1;
		}
	}
}

void removeEnemyShoot(enemyBullet_t enemyBullet[]){
	for (int i = 0; i < EnemyCount; i++) {
		if (enemyBullet[i].true){
			gotoxy(enemyBullet[i].posX,enemyBullet[i].posY);
			printf("%c", 32);
		} else if (!enemyBullet[i].true){
			gotoxy(enemyBullet[i].posX-1,enemyBullet[i].posY);
			printf("%c", 32);
		}
	}
}

void interactionsEnemyBulletHitPlayer(enemyBullet_t enemyBullet[], spaceship_t* spaceship){
	for (int i = 0; i < EnemyCount; i++) {
		if (
				//front right of the spaceship for the entire object defined
				(enemyBullet[i].posX == spaceship->posX && enemyBullet[i].posY == spaceship->posY+2) ||
				(enemyBullet[i].posX == spaceship->posX && enemyBullet[i].posY == spaceship->posY-2) ||
				(enemyBullet[i].posX == spaceship->posX+1 && enemyBullet[i].posY == spaceship->posY-1) ||
				(enemyBullet[i].posX == spaceship->posX+1 && enemyBullet[i].posY == spaceship->posY+1) ||
				(enemyBullet[i].posX == spaceship->posX+2 && enemyBullet[i].posY == spaceship->posY)
		) {
			for(int j = 0; j < 5; j++){
				//character_data[[32;126]
				buffer[j+ (35) + (spaceship->life*5)] = character_data[32-32][j];
			}
			lcd_push_buffer(buffer);

			//if enemyBullet hits -> spaceship life goes -1
			spaceship->life--;
			gotoxy(20,10);
			printf("%d", spaceship->life);
			break;
		}
	}
}









/*

switch(joystickState){
	case 2:
		enemies->posY += 1;
		enemies->velY = 1;
		enemies->velX = 0;
		//rotateVector((&enemies->posX,&enemies->posY), 5);
		break;
		//pin up
	}else if (joystickState == 1){
		enemies->posY -= 1;
		enemies->velY = -1;
		enemies->velX = 0;
		//rotateVector((&enemies->posX,&enemies->posY), -5);

		//pin left
	}else if (joystickState == 4){
		enemies->posX -= 1;
		enemies->velY = 0;
		enemies->velX = -1;

		//pin right
	}else if (joystickState == 8){
		enemies->posX += 1;
		enemies->velY = 0;
		enemies->velX = 1;

		//pin center
	}else if (joystickState == 16){

		//else pos = pos, vel = vel
	}else {
		enemies->posX = enemies->posX;
		enemies->posY = enemies->posY;
		enemies->velX = 0;
		enemies->velY = 0;


	}


}*/
