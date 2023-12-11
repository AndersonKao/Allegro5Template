#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include "ghost.h"
#include "map.h"
#include "pacman_obj.h"

/* global variables*/
// [ NOTE ]
// if you change the map .txt to your own design.
// You have to modify cage_grid_{x,y} to corressponding value also.
// Or you can do some change while loading map (reading .txt file)
// Make the start position metadata stored with map.txt.
const int cage_grid_x=22, cage_grid_y=11;

/* shared variables. */
extern uint32_t GAME_TICK;
extern uint32_t GAME_TICK_CD;
extern const int block_width,  block_height;
/* Internal variables */
static const int fix_draw_pixel_offset_x = -3;
static const int fix_draw_pixel_offset_y = -3;
static const int draw_region = 30;
// [ NOTE - speed again ]
// Again, you see this notaficationd. If you still want to implement something 
// fancy with speed, objData->moveCD and GAME_TICK, you can first start on 
// working on animation of ghosts and pacman. // Once you finished the animation 
// part, you will have more understanding on whole mechanism.
static const int basic_speed = 2;

Ghost* ghost_create(int flag) {

	// NOTODO
	Ghost* ghost = (Ghost*)malloc(sizeof(Ghost));
	if (!ghost)
		return NULL;

	ghost->go_in_time = GAME_TICK; 
	ghost->typeFlag = flag;
	ghost->objData.Size.x = block_width;
	ghost->objData.Size.y = block_height;

	ghost->objData.nextTryMove = NONE;
	ghost->speed = basic_speed;
	ghost->status = BLOCKED;

	ghost->flee_sprite = load_bitmap("Assets/ghost_flee.png");
	ghost->dead_sprite = load_bitmap("Assets/ghost_dead.png");

	// TODO-GC-ghost: Create other type ghost, load corresponding sprites.
	// TODO-IF: You may design your own special tracking rules.
	switch (ghost->typeFlag) {
	case Blinky:
		ghost->objData.Coord.x = cage_grid_x;
		ghost->objData.Coord.y = cage_grid_y;
		ghost->move_sprite = load_bitmap("Assets/ghost_move_red.png");
		ghost->move_script = &ghost_move_script_random;
		break;
	case Pinky:
		// *load move script of shortest_path
		ghost->objData.Coord.x = cage_grid_x;
		ghost->objData.Coord.y = cage_grid_y;
		ghost->move_sprite = load_bitmap("Assets/ghost_move_pink.png");
		ghost->move_script = &ghost_move_script_shortest_path;
	default:
		ghost->objData.Coord.x = cage_grid_x;
		ghost->objData.Coord.y = cage_grid_y;
		ghost->move_sprite = load_bitmap("Assets/ghost_move_red.png");
		ghost->move_script = &ghost_move_script_random;
		break;
	}
	return ghost;
}
void ghost_destory(Ghost* ghost) {
	// TODO-GC-memory: free ghost resource

	/*
		al_destory_bitmap(...);
		...
		free(ghost);
	*/
}
void ghost_draw(Ghost* ghost) {
	RecArea drawArea = getDrawArea((object*)ghost, GAME_TICK_CD);

	//Draw default image
	al_draw_scaled_bitmap(ghost->move_sprite, 0, 0,
		16, 16,
		drawArea.x + fix_draw_pixel_offset_x, drawArea.y + fix_draw_pixel_offset_y,
		draw_region, draw_region, 0
	);

	// Draw ghost according to its status and use ghost->objData.moveCD value to determine which frame of the animation to draw.
	// hint: please refer comments in pacman_draw 
	// Since ghost has more status, we suggest you finish pacman_draw first. The logic is very similar.

	int bitmap_x_offset = 0;
	if (ghost->status == FLEE) {
		// TODO-PB-animation: ghost FLEE animation, draw blue flee sprites,
		//						 while time is running out, alternatively draw blue and white flee sprites.
		// *draw ghost->flee_sprite
		/* hint: try to add some function in scene_game.h and scene_game.c that
			gets the value of `power_up_timer` and `power_up_duration`.
		*/ 
		/*
			if (it has run out of 70% of the time of power mode  )
			{
				// alternately draw blue and white sprites
				if (ghost->objData.moveCD >> 4)& 1) {
					bitmap_x_offset = ...;
				}
				al_draw_scaled_bitmap(...)
			}
			else 
			{
				// draw only blue sprite
				al_draw_scaled_bitmap(...)
			}
		*/
	}
	else if (ghost->status == GO_IN) {
		// TODO-PB-animation: ghost going animation
		// *draw ghost->dead_sprite
		/*
		switch (ghost->objData.facing)
		{
		case LEFT:
			...
		*/
	}
	else {
		// TODO-GC-animation: ghost animation
		// *draw ghost->move_sprite
		/*
		switch (ghost->objData.facing)
		{
		case LEFT:
			...
		}
		*/
	}

}
void ghost_NextMove(Ghost* ghost, Directions next) {
	ghost->objData.nextTryMove = next;
}
void printGhostStatus(GhostStatus S) {

	switch(S){
	
	case BLOCKED: // stay inside the ghost room
		game_log("BLOCKED");
		break;
	case GO_OUT: // going out the ghost room
		game_log("GO_OUT");
		break;
	case FREEDOM: // free at the map
		game_log("FREEDOM");
		break;
	case GO_IN:
		game_log("GO_IN");
		break;
	case FLEE:
		game_log("FLEE");
		break;
	default:
		game_log("status error");
		break;
	}
}
bool ghost_movable(const Ghost* ghost, const Map* M, Directions targetDirec, bool room) {
	// TODO-HACKATHON 2-3: Determine if the current direction is movable.
	// Basically, this is a ghost version of `pacman_movable`.
	// So if you have finished (and you should), you can just "copy and paste"
	// and do some small alternation.

	/*
	... ghost->objData.Coord.x, ... ghost->objData.Coord.y;

	switch (targetDirec) 
	{
	case UP:
		...
	case DOWN:
		...
	case LEFT:
		...
	case RIGHT:
		...
	default:
		// for none UP, DOWN, LEFT, RIGHT direction u should return false.
		return false;
	}

	if (is_wall_block(M, ..., ...) || (room && is_room_block(M, ..., ...)))
		return false;
	*/

	return true;

}

void ghost_toggle_FLEE(Ghost* ghost, bool setFLEE) {
	// TODO-PB: change ghosts state when power bean is eaten by pacman.
	// When pacman eats the power bean, only ghosts who are in state FREEDOM will change to state FLEE.
	// For those who are not (BLOCK, GO_IN, etc.), they won't change state.
	// Spec above is based on the classic PACMAN game.
	// setFLEE = true => set to FLEE, setFLEE = false => reset to FREEDOM
	/*
	if(setFLEE){
		// set FREEDOM ghost's status to FLEE and make them slow 
		if(... == FREEDOM){
			...
			ghost->speed = 1;
		}
	}else{
		// set FLEE ghost's status to FREESOME and them down
		if(... == FLEE){
			...
			ghost->speed = 2;
		}
	}
	*/
}

void ghost_collided(Ghost* ghost) {
	if (ghost->status == FLEE) {
		ghost->status = GO_IN;
		ghost->speed = 4; // Go back to cage faster
	}
}

