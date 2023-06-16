/*
 * powerup.c
 *
 *  Created on: 16. jan. 2023
 *      Author: louiss
 */

#include "powerup.h"

void initialize_powerup(fix_t x, fix_t y, powerup_t* powerup) {
	powerup->x = x;
	powerup->y = y;
	powerup->active = 1;
}
void draw_powerup(powerup_t powerup, uint8_t* buffer) {
	if (powerup.active) {
		int32_t mat[8][8] = { {1,1,1,1,1,1,1,1}, {1,0,0,0,0,0,0,1}, {1,0,1,1,1,1,0,1}, {1,0,1,0,1,0,0,1}, {1,0,1,0,1,0,0,1}, {1,0,1,1,1,0,0,1}, {1,0,0,0,0,0,0,1}, {1,1,1,1,1,1,1,1} };
		lcd_write_custom(8, 8, mat, TO_INT(powerup.x), TO_INT(powerup.y), buffer);
	}
}


void create_powerup(fix_t x, fix_t y, game_state_t state) {
	int randomnumber = rand() % 20;
	powerup_t* new_powerup = &state.powerups[*state.num_powerups % NPOWERUPS];
	*state.num_powerups += 1;
	if (10 <= randomnumber  ) {
		initialize_powerup(x, y, new_powerup);
	}


}


void draw_all_powerups(powerup_t* powerups, uint8_t* buffer) {
	for (uint8_t i = 0; i < NPOWERUPS; i++) {
		draw_powerup(powerups[i], buffer);
	}
}
void remove_powerup(powerup_t* powerup) {
	powerup->active = 0;
}
