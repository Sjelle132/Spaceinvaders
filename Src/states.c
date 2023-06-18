/*
 * screens.c
 *
 *  Created on: 13 Jun 2023
 *      Author: liou-
 */

#include "states.h"

uint16_t k = 0;
int e = 0;
int m = 0;
int h = 0;

uint8_t processInput(uint8_t state, uint8_t input) {
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

	case GameEasy:
		if (input == 'b') {
			newState = MainMenu;
		}
		break;

	case Help:
		if (input == '1') {
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
		stateGameEasy(enemies_t enemies[]);
		break;
	case GameMedium:
		stateGameMedium();
		break;
	case GameHard:
		stateGameHard();
	}
}

void stateStartMenu() {
	windowStart();
}

void stateMainMenu() {
	e = 0;
	windowMainMenu();
}

void stateSelDif() {
	windowSelDif();
}

void stateHelp() {
	windowHelp();
}


void stateGameEasy(enemies_t enemies[]) {
	windowGame();
	k = 300;
	e = 1;

	if (elapsed_time >= k ) {
		updateEnemies(enemies);
		elapsed_time = 0;
	}
	createEnemies(enemies);
	removeEnemies(enemies);
}

void stateGameMedium(){
	windowGame();
	k = 200;
	e = 1;

	/*
	if (elapsed_time >= 200 ) {
			updateEnemies(enemies);
			elapsed_time = 0;
		}
		createEnemies(enemies);
		removeEnemies(enemies);
	 */
}

void stateGameHard(){
	windowGame();

	k = 100;
	/*
	if (elapsed_time >= 100 ) {
			updateEnemies(enemies);
			elapsed_time = 0;
		}
		createEnemies(enemies);
		removeEnemies(enemies);*/
}


