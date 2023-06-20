/*
 * screens.c
 *
 *  Created on: 13 Jun 2023
 *      Author: liou-
 */

#include "states.h"

uint32_t k = 0;
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
		if (spaceship->life <= 0) {
			newState = GameOver;
		}
		break;
	case GameMedium:
		if (spaceship->life <= 0) {
			newState = GameOver;
		}
		break;

	case GameHard:
		if (spaceship->life <= 0) {
			newState = GameOver;
		}
		break;

	case GameOver:
		if (input == '1'){
			newState = MainMenu;
		}
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
	k = 300;


}

void stateGameMedium(){
	windowGame();
	stateStartGame = 1;
	stateReader = 0;
	k = 200;

}

void stateGameHard(){
	windowGame();
	stateStartGame = 1;
	stateReader = 0;
	k = 100;

}

void stateGameOver(){
	stateStartGame = 0;
	stateReader = 1;
	windowGameOver();

}
