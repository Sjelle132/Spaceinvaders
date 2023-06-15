/*
 * screens.c
 *
 *  Created on: 13 Jun 2023
 *      Author: liou-
 */

#include "states.h"

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
            if (input == '1' || input == '2' || input == '3') {
                newState = Game;
            } else if (input == '4') {
                newState = MainMenu;
            }
            break;

        case Game:
            if (input == 'b') {
                newState = MainMenu;
            }
            break;

        case Help:
            if (input == '1') {
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
        case Game:
            stateGame();
            break;
    }
}


void stateStartMenu() {
    windowStart();
}

void stateMainMenu() {
    windowMainMenu();
}

void stateSelDif() {
    windowSelDif();
}

void stateHelp() {
    windowHelp();
}

void stateGame() {
    windowGame();
}
