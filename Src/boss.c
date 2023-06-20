/*
 * boss.c
 *
 *  Created on: 18. jun. 2023
 *      Author: oscar
 */

#include "boss.h"


#define EnemyCount 5


void initBoss(boss_t boss[]){
	for (int i = 0; i < 1; i++) {
		boss[i].posX = 150;
		boss[i].posY = 25;
		boss[i].life = 10;
	}
}


//display boss
void createBoss(boss_t boss[]) {
	for (int i = 0; i < 1; i++) {
		if (boss[i].life > 0)  {
			gotoxy(boss[i].posX,boss[i].posY);
			fgcolor(1);
			printf("%c", 219);
		}
	}
}


//update positioning of boss
void updateBoss(boss_t boss[]) {
	for (int i = 0; i < 1; i++) {
		if (boss[i].posX >= 152 || boss[i].posX <= 3) {
			removeBoss(boss);
			boss[i].life = 0;
		} else if (boss[i].life > 0 )  {
			boss[i].posX -= 1;
			boss[i].posX = boss[i].posX;
			boss[i].posY = boss[i].posY;
		}
	}
}


void removeBoss(boss_t boss[]) {

	for (int i = 0; i < 1; i++){
		if (boss[i].life > 0) {
			gotoxy(boss[i].posX+1,boss[i].posY);
			printf("%c", 32);
		}
	}
}



void initBossBullet(bossBullet_t bossBullet[], boss_t* boss) {

	for (int i = 0; i < 1; i++){
		if (boss[i].life > 0) {
			bossBullet[i].posX = boss[i].posX;
			bossBullet[i].posY = boss[i].posY;
			bossBullet[i].true = 1;
		}
	}
}

void bossShoot(bossBullet_t bossBullet[], boss_t* boss){
	for (int i = 0; i<1;i++){
		if (bossBullet[i].true){

			gotoxy(bossBullet[i].posX-1,bossBullet[i].posY);
			printf("%c", 111);
		} else if (!bossBullet[i].true && boss[i].life > 0) {
			bossBullet[i].posX = boss[i].posX;
			bossBullet[i].posY = boss[i].posY;
			bossBullet[i].true = 1;
		}
	}
}

void updateBossShoot(bossBullet_t bossBullet[], boss_t* boss){
	for (int i = 0; i < 1; i++) {
		if ((bossBullet[i].posY >= 45 || bossBullet[i].posX <= 3 || bossBullet[i].posY <= 3 )){
			removeBossShoot(bossBullet);
			bossBullet[i].true = 0;
		}else if ((bossBullet[i].posY >= 3 || bossBullet[i].posX <= 45 || bossBullet[i].posY >= 3 )) {
			bossBullet[i].posX -= 1;
		}
	}
}

void removeBossShoot(bossBullet_t bossBullet[]){


	for (int i = 0; i < 1; i++) {
		if (bossBullet[i].true){
			gotoxy(bossBullet[i].posX,bossBullet[i].posY);
			printf("%c", 32);

		} else if (!bossBullet[i].true){
			gotoxy(bossBullet[i].posX-1,bossBullet[i].posY);
			printf("%c", 32);
		}
	}
}

//checks to see if bossBullets hit spaceship
void interactionsBossBulletHitPlayer(bossBullet_t bossBullet[], spaceship_t* spaceship){
	for (int i = 0; i < 1; i++) {
		if (
				//front right of the spaceship for the entire object defined
				(bossBullet[i].posX == spaceship->posX && bossBullet[i].posY == spaceship->posY+2) ||
				(bossBullet[i].posX == spaceship->posX && bossBullet[i].posY == spaceship->posY-2) ||
				(bossBullet[i].posX == spaceship->posX+1 && bossBullet[i].posY == spaceship->posY-1) ||
				(bossBullet[i].posX == spaceship->posX+1 && bossBullet[i].posY == spaceship->posY+1) ||
				(bossBullet[i].posX == spaceship->posX+2 && bossBullet[i].posY == spaceship->posY)
		) {

			//if enemyBullet hits -> spaceship life goes -1
			spaceship->life = 0;
			gotoxy(20,10);
			printf("%d", spaceship->life);
			break;

		}
	}
}
