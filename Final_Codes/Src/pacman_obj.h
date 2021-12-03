#ifndef PACMAN_OBJ_H
#define PACMAN_OBJ_H

#include "utility.h"
#include "game.h"

// <Forward Declaration>
// forward declarations can be useful when you need to have looping struct declarations,
// but you want to (should) prevent mutually include dependency.
// Only applicable when you only need the declaration but no need the definition in you sturct,
// which means that you only used the struct as pointer(no access to struct data), param, return type in this file.
// If you have to access the data in struct ex. `A->data`, 
// you should include the corresponding header file for its definition.
// Advance reading : https://stackoverflow.com/questions/18658438/what-is-forward-declaration-and-the-difference-between-typedef-struct-x-and

typedef struct Ghost Ghost;
typedef struct Map Map;

typedef struct Pacman{

	bitmapdata imgdata;
	object objData;
	func_ptr move;
	int speed;
	bool powerUp;
	ALLEGRO_TIMER* death_anim_counter;
	ALLEGRO_BITMAP* move_sprite;
	ALLEGRO_BITMAP* die_sprite;
} Pacman;

Pacman* pacman_create();
void pacman_destory(Pacman* pman);

void pacman_draw(Pacman* pacman);
void pacman_move(Pacman* pacman, Map* M);
void pacman_eatItem(Pacman* pacman, const char Item);

void pacman_NextMove(Pacman* pacman, Directions next);
void pacman_die();

#endif // !PACMAN_OBJ_H
