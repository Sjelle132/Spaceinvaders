/*
 * boss.c
 *
 *  Created on: 18. jun. 2023
 *      Author: oscar
 */

#include "boss.h"

#define EnemyCount 5
#define BossBulletCount 3

void initBoss(boss_t* boss){
	boss->posX = 150;
	boss->posY = 25;
	boss->life = 10;
}


void createBoss(boss_t* boss, enemies_t enemies[], int8_t f) {

		if (boss->life > 0)  {
			gotoxy(boss->posX,boss->posY);
			fgcolor(1);
			printf("%c", 219);

			/*gotoxy(boss->posX+1,boss->posY);
			printf("%c", 219);


			gotoxy(boss->posX+1,boss->posY-1);
			printf("%c", 219);

			gotoxy(boss->posX,boss->posY-1);
			printf("%c", 219);

			gotoxy(boss->posX-1,boss->posY-1);
			printf("%c", 219);

			gotoxy(boss->posX-1,boss->posY);
			printf("%c", 219);

			gotoxy(boss->posX-1,boss->posY+1);
			printf("%c", 219);

			gotoxy(boss->posX,boss->posY+1);
			printf("%c", 219);

			gotoxy(boss->posX+1,boss->posY+1);
			printf("%c", 219);

*/





	}
}



void updateBoss(boss_t* boss) {


		if (boss->posX >= 152 || boss->posX <= 3) {

			removeBoss(boss);
			boss->life = 0;

		} else if (boss->life > 0)  {
			boss->posX -= 1;


		}



}


void removeBoss(boss_t* boss, enemies_t enemies[], int8_t f) {

	for (int i = 0; i < 5; i++){}
		if (boss->life > 0) {
			gotoxy(boss->posX,boss->posY);
			printf("%c", 32);

		/*	gotoxy(boss->posX+1,boss->posY);
			printf("%c", 32);


			gotoxy(boss->posX+1,boss->posY-1);
			printf("%c", 32);

			gotoxy(boss->posX,boss->posY-1);
			printf("%c", 32);

			gotoxy(boss->posX-1,boss->posY-1);
			printf("%c", 32);

			gotoxy(boss->posX-1,boss->posY);
			printf("%c", 32);

			gotoxy(boss->posX-1,boss->posY+1);
			printf("%c", 32);

			gotoxy(boss->posX,boss->posY+1);
			printf("%c", 32);

			gotoxy(boss->posX+1,boss->posY+1);
			printf("%c", 32);

*/



		}


}

void initBossBullet(bossBullet_t bossBullet[], boss_t* boss) {

	for (int i = 0; i < BossBulletCount; i++){
			if (boss->life > 0) {
				bossBullet[i].posX = boss->posX;
				bossBullet[i].posY = boss->posY;
				bossBullet[i].true = 1;
			}
		}


}

void bossShoot(bossBullet_t bossBullet[], boss_t* boss){


	for (int i = 0; i<BossBulletCount;i++){
		if (bossBullet[i].true){

			gotoxy(bossBullet[i].posX,bossBullet[i].posY);
			printf("%c", 111);
		} else if (!bossBullet[i].true && boss->life > 0) {
			bossBullet[i].posX = boss->posX;
			bossBullet[i].posY = boss->posY;
			bossBullet[i].true = 1;

		}



	}
}

void updateBossShoot(bossBullet_t bossBullet[], boss_t* boss){

	for (int i = 0; i < BossBulletCount; i++) {
		if ((bossBullet[0].posY >= 45 || bossBullet[0].posX <= 3 || bossBullet[0].posY <= 3 )){
			//removeBossShoot(bossBullet);
			bossBullet[0].true = 0;
		}else if ((bossBullet[0].posY >= 3 || bossBullet[0].posX <= 45 || bossBullet[0].posY >= 3 )) {
			bossBullet[0].posX -= 1;

		}
/*
		if ((bossBullet[1].posY >= 45 || bossBullet[1].posX <= 3 || bossBullet[1].posY <= 3 )){
					//removeBossShoot(bossBullet);
					bossBullet[1].true = 0;
				}else {
					bossBullet[1].posX -= 1;
					bossBullet[1].posY += 1;

				}
		if ((bossBullet[2].posY <= 45 || bossBullet[2].posX <= 3 || bossBullet[2].posY <= 3 )){
					//removeBossShoot(bossBullet);
					bossBullet[2].true = 0;
				}else {
					bossBullet[2].posX -= 1;
					bossBullet[2].posY -= 1;


				}


	}*/
}
}

void removeBossShoot(bossBullet_t bossBullet[]){


	for (int i = 0; i < BossBulletCount; i++) {
		if (bossBullet[i].true){
			gotoxy(bossBullet[i].posX,bossBullet[i].posY);
			printf("%c", 32);

		} else if (!bossBullet[i].true){
			gotoxy(bossBullet[i].posX-1,bossBullet[i].posY);
			printf("%c", 32);


		}


	}
}













