#include "bullet.h"
#include "spaceship.h"
#include "uart.h"
#include "asteroids.h"

void initBullet(bullet_t* bullet,spaceship_t* spaceship){
	bullet->posX = spaceship->posX +2;
	bullet->posY = spaceship->posY;
	bullet->velX = 0;
	bullet->velY = 0;
	bullet->true = 1;
}


void spawnBullet(bullet_t* bullet){
	bullet->posX = 1000;
	bullet->posY = 1000;
	bullet->velX = 0;
	bullet->velY = 0;
	bullet->true = 1;
}


void createBullet(bullet_t* bullet ){
	if (bullet->true) {
		gotoxy(bullet->posX,bullet->posY);
		//bullet->posX = spaceship->posX;
		//bullet->posY = spaceship->posY;
		printf("%c", 111);

	}
}


void updateBullet(bullet_t* bullet) {
	//directionState = keyboardController();
	if (bullet->true && (bullet->posX >= 150 || bullet->posX <= 2)){
		bullet->posX += 0;
		bullet->velX = 0;
		removeBullet(bullet);
		bullet->true = 0;
	} else if(bullet->true && (bullet->posX >= 2 || bullet->posX <= 150)) {
				bullet->posX += 1;
	}
}


void removeBullet(bullet_t* bullet) {
	gotoxy(bullet->posX,bullet->posY);
	printf("%c", 32);
}


//jeg har skrevet herfra mht. gravity

void collisionDetectionA(asteroid_t asteroid[], bullet_t* bullet) {
	for (int i = 0; i < 5; i++){
	if ((bullet->posX >= asteroid[i].posX +1  && bullet->posX <= asteroid[i].posX + 1) &&
			(bullet->posY >= asteroid[i].posY - 1 && bullet->posY <= asteroid[i].posY + 1)) {
		asteroid[i].life -= 1;
	}
	}
}

uint32_t calculateDistance(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
    uint32_t dx =x2 - x1 < 0 ? x1-x2 : x2-x1;
    uint32_t dy =y2 - y1 < 0 ? y1-y2 : y2-y1;
    uint32_t sum = dx + dy;
    return sum;  //manhatten distance (faster than using euclidian(sqrt))
}


void applyGravity(asteroid_t *asteroid, bullet_t* bullet, int8_t numAsteroids) {
	if (bullet->true) {
		for (int i = 0; i < numAsteroids; i++) {
			// Calculate Manhattan distance between asteroid and bullet
			uint32_t distance = calculateDistance(bullet->posX, bullet->posY, asteroid[i].posX, asteroid[i].posY);

			// Calculate the pulling factor based on distance
			int32_t pullingFactor = 0;
			if (distance < 15){
				//printf("%d",distance);
				pullingFactor = (1/distance) + 1;
			}

			// Calculate the direction vector
			int32_t directionX = (asteroid[i].posX > bullet->posX) ? 1 : -1;
			int32_t directionY = (asteroid[i].posY > bullet->posY) ? 1 : -1;

			// Update the bullet's position based on the pulling factor and direction
			bullet->posX += pullingFactor * directionX +1;
			bullet->posY += pullingFactor * directionY ;
		}
	}
}
