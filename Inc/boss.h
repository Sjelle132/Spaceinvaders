/*
 * boss.h
 *
 *  Created on: 18. jun. 2023
 *      Author: oscar
 */

#ifndef BOSS_H_
#define BOSS_H_

#include "stm32f30x_conf.h"
#include "spaceship.h"
#include "enemies.h"


typedef struct {

	int16_t posX;
	int16_t posY;
	int8_t life;

} boss_t;

typedef struct {

	int16_t posX;
	int16_t posY;
	int8_t true;

} bossBullet_t;

void initBoss(boss_t boss[]);
void createBoss(boss_t boss[], enemies_t enemies[], int8_t f);
void updateBoss(boss_t boss[]);

void updateBossShoot(bossBullet_t bossBullet[], boss_t boss[]);
void bossShoot(bossBullet_t bossBullet[], boss_t boss[]);
void initBossBullet(bossBullet_t bossBullet[], boss_t boss[]);
void removeBossShoot(bossBullet_t bossBullet[]);


#endif /* BOSS_H_ */
