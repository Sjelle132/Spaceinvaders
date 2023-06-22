#include "asteroids.h"

void initAsteroids(asteroids_t asteroid[]) {
	for (int i = 0; i < numAsteroids; i++) {
		asteroid[i].life = 3;
	}
	asteroid[0].posX = 60;
	asteroid[0].posY = 5;
	asteroid[1].posX = 130;
	asteroid[1].posY = 15;
	asteroid[2].posX = 100;
	asteroid[2].posY = 25;
	asteroid[3].posX = 130;
	asteroid[3].posY = 35;
	asteroid[4].posX = 100;
	asteroid[4].posY = 40;
}

void drawAsteroid(asteroids_t asteroid[]){
	for (int i = 0; i < numAsteroids; i++){
		if (asteroid[i].life>0){
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

void applyGravity(asteroids_t asteroid[], bullet_t* bullet) {
	//if (bullet->true) {
	for (int i = 0; i < numAsteroids; i++) {
		// Calculate Manhattan distance between asteroid and bullet
		int16_t distance = calculateDistance(bullet->posX, bullet->posY, asteroid[i].posX, asteroid[i].posY);

		// Calculate the pulling factor based on distance
		int16_t pullingFactor = 0;

		if (distance < 10){
			pullingFactor = 1;
		}

		// Calculate the direction vector
		if ((asteroid[i].posY == bullet->posY) ||
				(asteroid[i].posY == bullet->posY-1)
				|| (asteroid[i].posY == bullet->posY+1)){

		} else {
			// Calculate the direction vector
			int32_t directionX = (asteroid[i].posX > bullet->posX) ? 1 : -1;
			int32_t directionY = (asteroid[i].posY > bullet->posY) ? 1 : -1;

			// Update the bullet's position based on the pulling factor and direction
			bullet->posX += (pullingFactor * directionX + 1) / 16;
			bullet->posY += pullingFactor * directionY ;
		}
	}
}
