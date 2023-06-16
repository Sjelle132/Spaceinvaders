/*
 * game.h
 *
 *  Created on: 12. jan. 2023
 *      Author: louiss
 */

#ifndef GAME_H_
#define GAME_H_

#include "explosion.h"
#include "types.h"
#include "bullet.h"
#include "spaceship.h"
#include "joystick.h"
#include "enemy.h"
#include "asteroid.h"
#include "powerup.h"
#include "interrupts.h"
#include "score.h"
#include "screens.h"

void clear_game_state(game_state_t state);
void handle_user_input(game_state_t state);
void handle_bullet_enemy_interaction(game_state_t state);
void handle_bullet_asteroid_interaction(game_state_t state);
void handle_player_powerup_interaction(game_state_t state);
void handle_player_asteroid_interaction(game_state_t state);
void handle_bullet_player_interaction(game_state_t state);
void handle_create_events(game_state_t state);
uint8_t check_interval(uint8_t interval, uint32_t time);

#endif /* GAME_H_ */
