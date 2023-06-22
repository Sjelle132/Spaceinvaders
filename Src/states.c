/*
 * screens.c
 *
 *  Created on: 13 Jun 2023
 *      Author: liou-
 */

#include "states.h"

uint8_t processInput(uint8_t state, uint8_t input,int8_t spaceship) {
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
		if (spaceship == 0) {
			newState = GameOver;
		}
		break;

	case GameMedium:
		if (spaceship == 0) {
			newState = GameOver;
		}
		break;

	case GameHard:
		if (spaceship == 0) {
			newState = GameOver;
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
		break;
	case GameOver:
		stateGameOver();
		break;
	}
	return state;
}

int8_t stateStartGame = 0;
int16_t playerBulletSpeed, enemyBulletSpeed,
bossBulletSpeed, enemyMovementSpeed, bossMovementSpeed = 0;

void stateStartMenu() {
	windowStart();
}

void stateMainMenu() {
	stateStartGame = 0;
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
	playerBulletSpeed = 100;
	enemyBulletSpeed = 100;
	enemyMovementSpeed = 200;
	bossBulletSpeed = 20;
	bossMovementSpeed = 150;
}

void stateGameMedium(){
	windowGame();
	stateStartGame = 1;
	playerBulletSpeed = 100;
	enemyBulletSpeed = 100;
	enemyMovementSpeed = 150;
	bossBulletSpeed = 20;
	bossMovementSpeed = 150;
}

void stateGameHard(){
	windowGame();
	stateStartGame = 1;
	playerBulletSpeed = 100;
	enemyBulletSpeed = 100;
	enemyMovementSpeed = 100;
	bossBulletSpeed = 10;
	bossMovementSpeed = 150;
}

void stateGameOver(spaceship_t* spaceship){
	stateStartGame = 0;
	windowGameOver();


}
