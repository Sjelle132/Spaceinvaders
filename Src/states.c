/*
 * screens.c
 *
 *  Created on: 13 Jun 2023
 *      Author: liou-
 */

#include "states.h"

int8_t stateStartGame = 0;
int8_t stateReader = 1;

uint8_t processInput(uint8_t state, uint8_t input,spaceship_t* spaceship) {
	uint8_t newState = state;

	switch (state) {
	case StartMenu:
		if (input == 'p') {
			newState = MainMenu;
		}
		break;

	case MainMenu:
		if (input == '1') {
			newState = SelDif;
		} else if (input == '2') {
			newState = Help;
		} else if (input == '3') {
			newState = MainMenu;
		}
		break;

	case SelDif:
		if (input == '1') {
			newState = GameEasy;
		} else if (input == '2'){
			newState = GameMedium;
		} else if (input == '3'){
			newState = GameHard;
		} else if (input == '4') {
			newState = MainMenu;
		}
		break;

	case Help:
		if (input == '1') {
			newState = MainMenu;
		}
		break;

	case GameEasy:
		if (input == 'b') {
			newState = MainMenu;
		}
		break;

	case GameMedium:
		if (input == 'b') {
			newState = MainMenu;
		}
		break;

	case GameHard:
		if (input == 'b') {
			newState = MainMenu;
		}
		break;

	case GameOver:
		if (input == '1'){
			newState = MainMenu;
		}
		break;
	}

	return newState;
}

uint8_t stateUpdate(uint8_t state) {
	switch (state) {
	case StartMenu:
		stateStartMenu();
		break;
	case MainMenu:
		stateMainMenu();
		break;
	case SelDif:
		stateSelDif();
		break;
	case Help:
		stateHelp();
		break;
	case GameEasy:
		stateGameEasy();
		break;
	case GameMedium:
		stateGameMedium();
		break;
	case GameHard:
		stateGameHard();

	case GameOver:
		stateGameOver();
		break;
	}
}

int16_t playerBulletSpeed, enemyBulletSpeed, bossBulletSpeed, enemyMovementSpeed, bossMovementSpeed = 0;

void stateStartMenu() {
	windowStart();
}

void stateMainMenu() {
	stateStartGame = 0;
	stateReader = 1;
	windowMainMenu();
}

void stateSelDif() {
	windowSelDif();
}

void stateHelp() {
	windowHelp();
}

void stateGameEasy() {
	windowGame();
	stateStartGame = 1;
	stateReader = 0;
	playerBulletSpeed = 100;
	enemyBulletSpeed = 100;
	enemyMovementSpeed = 200;
	bossBulletSpeed = 20;
	bossMovementSpeed = 150;
}

void stateGameMedium(){
	windowGame();
	stateStartGame = 1;
	stateReader = 0;
	playerBulletSpeed = 100;
}

void stateGameHard(){
	windowGame();
	stateStartGame = 1;
	stateReader = 0;
	playerBulletSpeed = 100;
}

void stateGameOver(){
	stateStartGame = 0;
	stateReader = 1;
	windowGameOver();
}
