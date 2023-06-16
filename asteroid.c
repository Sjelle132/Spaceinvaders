/*
 * asteroid.c
 *
 *  Created on: 12. jan. 2023
 *      Author: Casper
 */

#include "asteroid.h"

void initialize_asteroid(fix_t x, fix_t y, fix_t vx, fix_t vy, asteroid_t* asteroid) {
	asteroid->x = x;
	asteroid->y = y;
	asteroid->vx = vx;
	asteroid->vy = vy;
	asteroid->life = 8;
	asteroid->active = 1;
}

void draw_asteroid(asteroid_t asteroid, uint8_t* buffer) {
	if (asteroid.active) {
		int32_t mat[7][6] = { {0,1,1,1,1,0}, {1,0,1,1,1,1}, {1,1,1,1,0,1}, {1,1,1,1,1,1},{1,1,0,1,1,1},{0,1,1,1,1,0} };
		lcd_write_custom(7, 6, mat, TO_INT(asteroid.x), TO_INT(asteroid.y), buffer);
	}
}

void update_asteroid(asteroid_t* asteroid, game_state_t state) {
	if (asteroid->active) {
		asteroid->x += asteroid->vx;
		asteroid->y += asteroid->vy;

		// check if asteorid are out of picture
		if (asteroid->y < 0) {
			// deactivate if out
			remove_asteoroid(asteroid);
			state.player->life -= 1;
		}
	}
}

void create_asteroid(fix_t x, fix_t y, game_state_t state) {
	asteroid_t* new_asteroid = &state.asteroids[*state.num_asteroid % NASTEROIDS];
	fix_t vy = (-0b10000) - FIX_MULT(TO_FIX(*state.score >> 1), 0b00001);
	fix_t vx = 0;
	*state.num_asteroid += 1;
	initialize_asteroid(x, y, vx, vy, new_asteroid);
}

void draw_all_asteroids(asteroid_t* asteroids, uint8_t* buffer) {
	for (uint8_t i = 0; i < NASTEROIDS; i++) {
		draw_asteroid(asteroids[i], buffer);
	}
}

void remove_asteoroid(asteroid_t* asteroid) {
	asteroid->active = 0;
}

void update_all_asteroids(game_state_t state) {
	for (uint8_t i = 0; i < NASTEROIDS; i++) {
		update_asteroid(&state.asteroids[i], state);
	}
}


