#include "asteroids.h"

void initAsteroids(asteroid_t* asteroid) {
	asteroid->posX = 0;
	asteroid->posY = 0;
	asteroid->radius = 50;
	asteroid->life = 3;
}

//create Asteroid
void drawAsteroid(asteroid_t* asteroid){
	if (asteroid-> life > 0){
		gotoxy(asteroid->posX,asteroid->posY);
		printf("%c",219);
		gotoxy(asteroid->posX,asteroid->posY+1);
		printf("%c",223);
		gotoxy(asteroid->posX+1,asteroid->posY);
		printf("%c",220);
		gotoxy(asteroid->posX-1,asteroid->posY);
		printf("%c",220);
	}
}



