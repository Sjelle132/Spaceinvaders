#include "asteroids.h"

void initAsteroids(asteroid_t asteroid[]) {
	for (int i = 0; i < 5; i++) {
		//asteroid[i].posX = 50+i*22;
		//asteroid[i].posY = 5+i*6;
		asteroid[0].posX = 60;
		asteroid[0].posY=5;
		asteroid[1].posX = 130;
		asteroid[1].posY=15;
		asteroid[2].posX = 100;
		asteroid[2].posY=25;
		asteroid[3].posX = 130;
		asteroid[3].posY=35;
		asteroid[4].posX = 100;
		asteroid[4].posY=40;
		asteroid[i].life = 3;
	}
}


void drawAsteroid(asteroid_t asteroid[]){
	for (int i = 0; i < 5; i++){
	if (asteroid[i].life>0){
		gotoxy(asteroid[i].posX,asteroid[i].posY);
		printf("%c, %d",219, asteroid[i].posX);
		gotoxy(asteroid[i].posX,asteroid[i].posY+1);
		printf("%c",223);
		gotoxy(asteroid[i].posX+1,asteroid[i].posY);
		printf("%c",220);
		gotoxy(asteroid[i].posX-1,asteroid[i].posY);
		printf("%c",220);
		}
	}
}

void removeAsteroid(asteroid_t asteroid[]) {
	for (int i = 0; i < 5; i++){
		if (asteroid[i].life == 0){
			gotoxy(asteroid[i].posX,asteroid[i].posY);
			printf("%c, %d",32, asteroid[i].posX);
			gotoxy(asteroid[i].posX,asteroid[i].posY+1);
			printf("%c",32);
			gotoxy(asteroid[i].posX+1,asteroid[i].posY);
			printf("%c",32);
			gotoxy(asteroid[i].posX-1,asteroid[i].posY);
			printf("%c",32);
		}
	}
}
