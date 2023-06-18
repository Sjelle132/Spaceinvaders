/*
 * screens.h
 *
 *  Created on: 13 Jun 2023
 *      Author: liou-
 */

#ifndef STATES_H
#define STATES_H


#include "stm32f30x_conf.h" // STM32 config
#include "stdio.h"
#include "stdint.h"
#include "30010_io.h"
#include "ansi.h"
#include "window.h"
#include "timers.h"
#include "enemies.h"
#include "spaceship.h"
#include "bullet.h"


#define StartMenu 0
#define MainMenu 1
#define SelDif 2
#define Help 3
#define GameEasy 4
#define GameMedium 5
#define GameHard 6

extern uint16_t k;
extern int e,m,h;


void stateStartMenu();
void stateMainMenu();
void stateSelDif();
void stateHelp();
void stateGameEasy(enemies_t enemies[]);
void stateGameMedium();
void stateGameHard();

uint8_t processInput(uint8_t state, uint8_t input);
uint8_t stateUpdate(uint8_t state);

#endif // STATES_H
