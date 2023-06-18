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

//initialize 3 enemies

void initEnemies(enemies_t enemies[]) {
	for (int i = 0; i < EnemyCount; i++){
		enemies[i].posX = 150;
		enemies[i].posY = 7+i*8;//10*i+rand()%40;
		enemies[i].velX = 0;
		enemies[i].velY = 0;
		enemies[i].life = 2;
	}

}


void initEliteEnemy(eliteEnemy_t* EliteEnemy) {
	EliteEnemy->posX = 0;
	EliteEnemy->posY = 0;
	EliteEnemy->velX = 0;
	EliteEnemy->velY = 0;
	EliteEnemy->life = 6;
}


//create or draw enemies as array
void createEnemies(enemies_t enemies[]) {


	for (int i = 0; i < EnemyCount; i++){
		if (enemies[i].life > 0){
			gotoxy(enemies[i].posX,enemies[i].posY);
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
		}else if ((enemyBullet[i].posX >= 3 || enemyBullet[i].posX <= 152) /*&& enemies[i].life > 0*/) {
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

