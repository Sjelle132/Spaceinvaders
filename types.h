/*
 * types.h
 *
 *  Created on: 10. jan. 2023
 *      Author: louiss
 */

#ifndef TYPES_H_
#define TYPES_H_

#include <stdio.h>

typedef uint8_t joystick_input_t;

typedef struct {
	int32_t x, y;
} vector_t;


typedef int16_t fix_t; // fixed point format: 11.5
typedef int32_t fix_2_14_t; // fixed point format: 2.14
typedef int32_t fix_16_16_t; // fixed point format: 2.14


typedef struct {
	fix_t x;
	fix_t y;
	uint8_t state;
	uint8_t active;
} explotion_t;

typedef struct {
	fix_t x;
	fix_t y;
	uint8_t active;
} powerup_t;

typedef struct {
	fix_t x;
	fix_t y;
	fix_t vx;
	fix_t vy;
	uint8_t active;
} bullet_t;

typedef struct {
	fix_t x;
	fix_t y;
	fix_t vx;
	fix_t vy;
	uint8_t life;
	uint8_t active;
} asteroid_t;

typedef struct {
	fix_t x;
	fix_t y;
	fix_t vx;
	fix_t vy;
	int8_t life;
	uint8_t weapon;
	uint8_t state;
	uint8_t countdown;
} spaceship_t;

typedef struct {
	fix_t x;
	fix_t y;
	fix_t vx;
	fix_t vy;
	uint8_t life;
	uint8_t active;
	uint8_t countdown_shoot;
} enemy_t;

typedef struct {

	powerup_t* powerups;
	uint8_t* num_powerups;

	explotion_t* explosions;
	uint8_t* num_explosions;

	bullet_t* bullets;
	uint8_t* num_bullet;

	enemy_t* enemies;
	uint8_t* num_enemy;

	asteroid_t* asteroids;
	uint8_t* num_asteroid;

	spaceship_t* player;

	uint8_t* screen;

	uint8_t* buffer;

	uint32_t* time;

	joystick_input_t* joystick_input;
	joystick_input_t* accelerometer_input;

	uint32_t* score;


} game_state_t;


#endif /* TYPES_H_ */
