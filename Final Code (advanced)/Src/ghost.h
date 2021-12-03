#ifndef GHOST_H
#define GHOST_H
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

typedef struct Pacman Pacman;
typedef struct Map Map;

typedef enum {
	BLOCKED,						 // stay inside the ghost room
	GO_OUT,							 // going out the ghost room
	FREEDOM,					     // free at the map
	GO_IN,							 // going back to the ghost room 
	FLEE							 // pacman powered up
} GhostStatus;

typedef enum {
	Blinky,
	Pinky,
	Inky,
	Clyde
} GhostType;


typedef struct Ghost{
	bitmapdata imgdata;
	object objData;
	script_func_ptr move_script;
	int speed;
	int64_t previous_timer_val;
	GhostType typeFlag;
	GhostStatus status;
	ALLEGRO_BITMAP* move_sprite;
	ALLEGRO_BITMAP* flee_sprite;
	ALLEGRO_BITMAP* dead_sprite;
} Ghost;

Ghost* ghost_create(int flag);
void ghost_destory(Ghost* ghost);
void ghost_draw(Ghost* ghost);
void ghost_NextMove(Ghost* ghost, Directions next);
void printGhostStatus(GhostStatus);
bool ghost_movable(Ghost* ghost, Map* M, Directions targetDirec, bool room);
/* check if the direction is ok to move_script in; if room = true, then room will be treat as not able to move_script in */


void ghost_toggle_FLEE(Ghost* ghosts, bool setFLEE);
void ghost_collided(Ghost* ghost);
void ghost_move_script_GO_IN(Ghost* ghost, Map* M);
void ghost_move_script_GO_OUT(Ghost* ghost, Map* M);
void ghost_move_script_FLEE(Ghost* ghost, Map* M, const Pacman * const pacman);

void ghost_red_move_script(Ghost* ghost, Map* M, Pacman* pacman);
#endif
