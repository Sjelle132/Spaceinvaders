#define ESC 0x1B
#include "ansi.h"
#include "stdio.h"
#include "stdint.h"
#include "lut.h"
#include "math.h"
#define M_PI 3.14159265358979323846


void fgcolor(uint8_t foreground) {
/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%dm", ESC, type, foreground+30);
}

void bgcolor(uint8_t background) {
/* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
   Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
                The designers of HyperTerminal, however, preferred black text on white background, which is why
                the colors are initially like that, but when the background color is first changed there is no
 	              way comming back.
   Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.

    Value      Color
    ------------------
      0        Black
      1        Red
      2        Green
      3        Brown
      4        Blue
      5        Purple
      6        Cyan
      7        Gray
*/
  printf("%c[%dm", ESC, background+40);
}

void color(uint8_t foreground, uint8_t background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%d;%dm", ESC, type, foreground+30, background+40);
}

void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
  printf("%c[m", ESC);
}

void clrscr(){
	printf("%c[2J", ESC);
}

void clreol(){
	printf("%c[K", ESC);
}

void hideCursor(){
	printf("%c[?25l", ESC);
}

void clrpkt(){
	printf("%c[1D", ESC);
	printf("%c", 32);
}

void gotoxy(uint8_t r, uint8_t c){
	printf("\033[%d;%dH", c, r);
}

void underline(uint8_t on){
	if (on){
	print("%c[4m", ESC);
	} else
		print("%c[24m", ESC);
}

void blink(uint8_t on){
	if (on){
		print("%c[5m", ESC);
		} else
			print("%c[25m", ESC);
}

void inverse(uint8_t on){
	if (on){
		print("%c[7m", ESC);
		} else
			print("%c[27m", ESC);
}

void window(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, char s[], int style){

	int i;
	if(style == 1){

		gotoxy(x1,y1);

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


void window2(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, int style){

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


