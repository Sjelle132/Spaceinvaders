/*
 * window.c
 *
 *  Created on: 8 Jun 2023
 *      Author: liou-
 */
#include "window.h"

void initWindow(){
	clrscr();
	hideCursor();
	bgcolor(0);
	fgcolor(15);
	gotoxy(0,0);
}

void windowName(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, char s[], int style){

	int i;
	gotoxy(0,0);
	if(style == 1){

		gotoxy(y1,x1);

		printf("%c", 218);
		for (i = 0; i < x2 - x1; i++){
			printf("%c", 196);
		}

		printf("%c", 191);
		printf("%c[1B", ESC);
		printf("%c[1D", ESC);

		for (i = 1 ; i < (y2 - y1); i++){
			printf("%c", 179);
			printf("%c[1B", ESC);
			printf("%c[1D", ESC);
		}

		gotoxy(y1, x1);
		printf("%c[1B", ESC);

		for (i = 1 ; i < (y2 - y1) ; i++){
			printf("%c", 179);
			printf("%c[1B", ESC);
			printf("%c[1D", ESC);
		}

		printf("%c", 192);

		for (i = 0; i < x2 - x1; i ++){
			printf("%c", 196);
		}

		printf("%c", 217);

		gotoxy(y1, x1 + 1);

		printf("%c", 180);
		fgcolor(15);
		bgcolor(0);
		printf(s);
		printf(" ");
		printf("%c", 195);

	} else if (style == 2){
		gotoxy(y1,x1);

		printf("%c", 201);
		for (i = 0; i < x2 - x1; i++){
			printf("%c", 205);
		}

		printf("%c", 187);
		printf("%c[1B", ESC);
		printf("%c[1D", ESC);

		for (i = 1 ; i < (y2 - y1); i++){
			printf("%c", 186);
			printf("%c[1B", ESC);
			printf("%c[1D", ESC);
		}

		gotoxy(y1, x1);
		printf("%c[1B", ESC);

		for (i = 1 ; i < (y2 - y1) ; i++){
			printf("%c", 186);
			printf("%c[1B", ESC);
			printf("%c[1D", ESC);
		}

		printf("%c", 200);

		for (i = 0; i < x2 - x1; i ++){
			printf("%c", 205);
		}

		printf("%c", 188);

		gotoxy((x1 + x2) / 2 - strlen(s) / 2, 0);
		printf(s);


	}
}

void windowFrame(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, int style){

	int i;

	if(style == 1){

		gotoxy(y1,x1);
		printf("%c", 218);

		for (i = 0; i < x2 - x1; i++){
			printf("%c", 196);
		}

		printf("%c", 191);
		printf("%c[1B", ESC);
		printf("%c[1D", ESC);

		for (i = 1 ; i < (y2 - y1); i++){
			printf("%c", 179);
			printf("%c[1B", ESC);
			printf("%c[1D", ESC);
		}

		gotoxy(y1, x1);
		printf("%c[1B", ESC);

		for (i = 1 ; i < (y2 - y1) ; i++){
			printf("%c", 179);
			printf("%c[1B", ESC);
			printf("%c[1D", ESC);
		}

		printf("%c", 192);

		for (i = 0; i < x2 - x1; i ++){
			printf("%c", 196);
		}

		printf("%c", 217);

	} else if (style == 2){
		gotoxy(y1,x1);

		printf("%c", 201);

		for (i = 0; i < x2 - x1; i++){
			printf("%c", 205);
		}

		printf("%c", 187);
		printf("%c[1B", ESC);
		printf("%c[1D", ESC);

		for (i = 1 ; i < (y2 - y1); i++){
			printf("%c", 186);
			printf("%c[1B", ESC);
			printf("%c[1D", ESC);
		}

		gotoxy(y1, x1);
		printf("%c[1B", ESC);

		for (i = 1 ; i < (y2 - y1) ; i++){
			printf("%c", 186);
			printf("%c[1B", ESC);
			printf("%c[1D", ESC);
		}

		printf("%c", 200);

		for (i = 0; i < x2 - x1; i ++){
			printf("%c", 205);
		}

		printf("%c", 188);
	}
}

void windowMainMenu(){
	//	windowFrame(5, 15, 125, 50, 1);
	clrscr();
	windowName(0,0,30,20,"Main Menu", 2);

	nameOnly(5, 9, "1. Start Game");
	nameOnly(5, 12, "2. Help");
}

void windowHelp(){
	clrscr();
	windowName(0,0,30,20,"Help", 2);

	nameOnly(5, 9, "You don't need help");
	nameOnly(5, 18, "1. Go back");
}

void windowGame(){
	clrscr();
	windowName(0, 0, 150, 300, "Space Invaders", 2);
}

void windowSelDif(){
	clrscr();
	windowName(0,0,30,20,"Select Difficulty", 2);

	nameOnly(5, 9, "1. Easy");
	nameOnly(5, 12, "2. Medium");
	nameOnly(5, 15, "3. Hard");
	nameOnly(5, 18, "4. Go back");
}

void windowStart(){
	windowName(0,0,30,20, "Start Screen", 2);

	nameOnly(5, 9, "Press 'p' to start");
}

void windowGameOver(){
	clrscr();
	windowName(0,0, 30, 20, "Game Over", 2);

	nameOnly(5,9, "1. Try again");
	nameOnly(5, 12, "2. Exit Game");
}

void nameOnly(uint8_t x, uint8_t y, char string[]){
	gotoxy(x,y);
	printf(string);
}
