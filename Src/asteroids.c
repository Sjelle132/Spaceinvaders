#include "asteroids.h"

#define AsteroidCount 5


void initAsteroid(asteroid_t asteroid[]) {
	for (int i = 0; i < AsteroidCount; i++){
			asteroid[i].posX = 75+i*4;
			asteroid[i].posY = 5+i*8;//10*i+rand()%40;
			asteroid[i].life = 5;
		}

}

//create Asteroid
void drawAsteroid(asteroid_t asteroid[]){
	for (int i = 0; i < AsteroidCount; i++) {
    if (asteroid[i].life > 0){
        gotoxy(asteroid[i].posX,asteroid[i].posY);
        printf("%c",219);
        gotoxy(asteroid[i].posX,asteroid[i].posY+1);
        printf("%c",223);
        gotoxy(asteroid[i].posX+1,asteroid[i].posY);
        printf("%c",220);
        gotoxy(asteroid[i].posX-1,asteroid[i].posY);
        printf("%c",220);
    }
	}
}

void updateAsteroid(asteroid_t asteroid[]) {

	for (int i = 0; i < AsteroidCount; i++) {
			if ((asteroid[i].posY <= 40 && asteroid[i].posY >= 3) && (asteroid[i].life > 0)) {

					asteroid[i].posY += 1;

			} else {

				asteroid[i].posX = 75+i*4;
				asteroid[i].posY = 5;
			}
	}

}

void removeAsteroid(asteroid_t asteroid[]) {

	for (int i = 0; i < AsteroidCount; i++){
			if (asteroid[i].life > 0){
				 gotoxy(asteroid[i].posX,asteroid[i].posY);
				        printf("%c",32);
				        gotoxy(asteroid[i].posX,asteroid[i].posY+1);
				        printf("%c",32);
				        gotoxy(asteroid[i].posX+1,asteroid[i].posY);
				        printf("%c",32);
				        gotoxy(asteroid[i].posX-1,asteroid[i].posY);
				        printf("%c",32);


			}
		}

}

