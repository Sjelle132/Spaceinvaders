/*
 * game.c
 *
 *  Created on: 12. jan. 2023
 *      Author: louiss
 */

#include "game.h"


void clear_game_state(game_state_t state) {

	*state.screen = GAME_SCREEN;
	*state.score = 0;
	*state.time = 0;
	*state.num_enemy = 0;
	*state.num_explosions = 0;
	*state.num_bullet = 0;
	*state.num_asteroid = 0;
	*state.num_powerups = 0;

	initialize_spaceship(state.player);

	for (int32_t a = 0; a < NPOWERUPS; a++) {
		state.powerups[a].active = 0;
	}


	for (int32_t b = 0; b < NBULLETS; b++) {
		state.bullets[b].active = 0;
	}


	for (int32_t c = 0; c < NASTEROIDS; c++) {
		state.asteroids[c].active = 0;
	}


	for (int32_t d = 0; d < NENEMIES; d++) {
		state.enemies[d].active = 0;
	}


	for (int32_t e = 0; e < NEXPLOSIONS; e++) {
		state.explosions[e].active = 0;
	}

}

void handle_user_input(game_state_t state) {

	update_spaceship(*state.accelerometer_input, state.player);

	// if joystick center is pressed then create bullet
	if (is_input(*state.joystick_input, JOYSTICK_CENTER)) {
		set_led(0b100); // set led to red
		spaceship_shoot(*state.player, state);
	}
	else {
		set_led(0b000); // turn off led
	}

	// BOSS KEY
	// check if joystick center and left is pressed
	if (is_input(*state.joystick_input, JOYSTICK_CENTER) && is_input(*state.joystick_input, JOYSTICK_LEFT)) {
		set_screen(state.screen, BOSS_SCREEN);
	}
}


// a function that checks if enough time has passed for a interval
// returns 1 when *interval* has passed in *time*
uint8_t check_interval(uint8_t interval, uint32_t time) {
	if (time % TO_COUNT_TIME(interval) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

// a function that handles create event based on a interval and a time
void handle_create_events(game_state_t state) {

	uint8_t ten_seconds = 10;
	uint8_t seven_seconds = 7;

	// spawn a every every ten seconds
	if (check_interval(ten_seconds, *state.time)) {
		fix_t x = TO_FIX((rand() % 20) + 1);
		fix_t y = TO_FIX(100);
		create_enemy(x, y, state);
	}

	// spawn a asteroid every five seconds
	if (check_interval(seven_seconds, *state.time)) {
		fix_t x = TO_FIX((rand() % 20) + 1);
		fix_t y = TO_FIX(100);
		create_asteroid(x, y, state);
	}
}

void handle_bullet_enemy_interaction(game_state_t state) {
	// loop over every bullet
	for (uint8_t i = 0; i < NBULLETS; i++) {

		// if bullet is not active, skip
		if (!state.bullets[i].active) {
			continue;
		}


		// loop over every enemy
		for (uint8_t j = 0; j < NENEMIES; j++) {

			// if enemy is not active, skip
			if (!state.enemies[j].active) {
				continue;
			}

			// calc distance between enemy and bullet
			int16_t dist_enemy_x = abs(state.bullets[i].x - (state.enemies[j].x + TO_FIX(2)));
			int16_t dist_enemy_y = abs(state.bullets[i].y - state.enemies[j].y);

			// check if bullet hits enemy
			if ((dist_enemy_x < TO_FIX(5)) && (dist_enemy_y < TO_FIX(2))) {
				remove_bullet(&state.bullets[i]);
				create_explotion(state.bullets[i].x, state.bullets[i].y, state);
				state.enemies[j].life -= 1;

				// check if enemy is dead
				if (state.enemies[j].life == 0) {
					remove_enemy(&state.enemies[j]);
					create_explotion(state.enemies[j].x, state.enemies[j].y, state);
					create_explotion(state.enemies[j].x + TO_FIX(6), state.enemies[j].y, state);
					create_powerup(state.enemies[j].x, state.enemies[j].y, state);
					add_score(5, state);
				}
			}
		}
	}
}

void handle_bullet_player_interaction(game_state_t state) {
	// loop over every bullet
	for (uint8_t i = 0; i < NBULLETS; i++) {

		// if bullet is not active, skip
		if (!state.bullets[i].active) {
			continue;
		}

		// PLAYER
		// calcs the distance from player to bullet
		fix_t dist_player_x = abs(state.bullets[i].x - (state.player->x + TO_FIX(3)));
		fix_t dist_player_y = abs(state.bullets[i].y - (state.player->y + TO_FIX(5)));

		// check if player is hit
		if (TO_INT(dist_player_x) < 3 && TO_INT(dist_player_y) < 5) {
			create_explotion(state.bullets[i].x, state.bullets[i].y, state);
			remove_bullet(&state.bullets[i]);
			state.player->life -= 1;
		}


	}
}

void handle_player_powerup_interaction(game_state_t state) {

	// loop over every powerup
	for (uint8_t i = 0; i < NPOWERUPS; i++) {

		// if powerup is not active, skip
		if (!state.powerups[i].active) {
			continue;
		}

		fix_t dist_x = abs((state.player->x + TO_FIX(3)) - (state.powerups[i].x + TO_FIX(4)));
		fix_t dist_y = abs((state.player->y + TO_FIX(5)) - (state.powerups[i].y + TO_FIX(4)));

		if (TO_INT(dist_x) < 4 && TO_INT(dist_y) < 4) {
			remove_powerup(&state.powerups[i]);
			state.player->state = 1;
			state.player->countdown = TO_COUNT_TIME(10);
		}

	}

}


void handle_bullet_asteroid_interaction(game_state_t state) {
	// loop over every bullet
	for (uint8_t i = 0; i < NBULLETS; i++) {
		// if bullet not active, skip
		if (!state.bullets[i].active) {
			continue;
		}

		for (uint8_t j = 0; j < NASTEROIDS; j++) {

			// if asteroid not active, skip
			if (!state.asteroids[j].active) {
				continue;
			}

			int16_t dist_x = state.bullets[i].x - (state.asteroids[j].x + TO_FIX(3));
			int16_t dist_y = abs(state.bullets[i].y - state.asteroids[j].y);

			// test if gravity applies
			if ((abs(dist_x) < TO_FIX(10)) && (dist_y < TO_FIX(5)) && (dist_x != 0)) {
				// update velocity to create gravity
				state.bullets[i].vx -= FIX_MULT(FIX_DIVD(TO_FIX(8), dist_x), 0x3);
			}

			if ((abs(dist_x) < TO_FIX(3)) && (dist_y < TO_FIX(5))) {
				// bullet hit
				remove_bullet(&state.bullets[i]);
				create_explotion(state.bullets[i].x, state.bullets[i].y, state);
				state.asteroids[j].life -= 1;

				if (state.asteroids[j].life == 0) {
					remove_asteoroid(&state.asteroids[j]);
					create_explotion(state.asteroids[j].x, state.asteroids[j].y, state);
					create_explotion(state.asteroids[j].x + TO_FIX(6), state.asteroids[j].y, state);
					add_score(10, state);
				}
			}
		}
	}
}

void handle_player_asteroid_interaction(game_state_t state) {
	for (uint8_t i = 0; i < NASTEROIDS; i++) {

		// if not active, skip
		if (!state.asteroids[i].active) {
			continue;
		}

		fix_t dist_x = abs((state.player->x + TO_FIX(3)) - (state.asteroids[i].x + TO_FIX(4)));
		fix_t dist_y = abs((state.player->y + TO_FIX(5)) - (state.asteroids[i].y + TO_FIX(4)));

		if (TO_INT(dist_x) < 4 && TO_INT(dist_y) < 4) {
			create_explotion(state.player->x, state.player->y, state);
			remove_asteoroid(&state.asteroids[i]);
			state.player->life = 0;
		}



	}
}
