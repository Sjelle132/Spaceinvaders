/*
 * window.c
 *
 *  Created on: 8 Jun 2023
 *      Author: liou-
 */

#include "ansi.h"
#include "window.h"

void initWindow(uint8_t x1, uint8_t y1 ,uint8_t x2, uint8_t y2){
	clrscr();
	color(15,0);
	gotoxy(0,0);

	int i;
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

		gotoxy(y1, x1 + 1);

		printf("%c", 185);
		fgcolor(15);
		bgcolor(0);
		printf(s);
		printf(" ");
		printf("%c", 204);
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



