// [utility.c]
// you should implement the utility functions defined in the header.

#include "utility.h"
#include "game.h"
#include <math.h>
#include <stdlib.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
extern uint32_t GAME_TICK, GAME_TICK_CD;
const int GridSize = 22;
float VOLUME = 1.0;
extern map_offset_x;
extern map_offset_y;
extern block_width, block_height;
ALLEGRO_SAMPLE* load_audio(const char* filename) {
	ALLEGRO_SAMPLE* sample = al_load_sample(filename);
	if (!sample)
		game_abort("failed to load audio: %s", filename);
	else
		game_log("loaded audio: %s", filename);
	return sample;
}

ALLEGRO_SAMPLE_ID play_audio(ALLEGRO_SAMPLE* sample, float volume) {
	ALLEGRO_SAMPLE_ID id;
	if (!al_play_sample(sample, volume, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &id))
		game_abort("failed to play audio (once)");
	return id;
}

ALLEGRO_SAMPLE_ID play_bgm(ALLEGRO_SAMPLE* sample, float volume) {
	ALLEGRO_SAMPLE_ID id;
	if (!al_play_sample(sample, volume, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &id))
		game_abort("failed to play audio (bgm)");

		//game_log("played audio (bgm)");
		return id;
}

void stop_bgm(ALLEGRO_SAMPLE_ID sample) {
	al_stop_sample(&sample);
	//game_log("stop audio (bgm)");
}

ALLEGRO_FONT* load_font(const char* filename, int size) {
	ALLEGRO_FONT* font = al_load_font(filename, size, 0);
	if (!font)
		game_abort("failed to load font: %s with size %d", filename, size);
	else
		game_log("loaded font: %s with size %d", filename, size);
	return font;
}

ALLEGRO_BITMAP* load_bitmap(const char* filename) {
	ALLEGRO_BITMAP* bmp = al_load_bitmap(filename);
	if (!bmp)
		game_abort("failed to load image: %s", filename);
	else
		game_log("loaded image: %s", filename);
	return bmp;
}

ALLEGRO_BITMAP* load_bitmap_resized(const char* filename, int w, int h) {
	ALLEGRO_BITMAP* loaded_bmp = load_bitmap(filename);
	ALLEGRO_BITMAP* resized_bmp = al_create_bitmap(w, h);
	ALLEGRO_BITMAP* prev_target = al_get_target_bitmap();

	if (!resized_bmp)
		game_abort("failed to create bitmap when creating resized image: %s", filename);
	al_set_target_bitmap(resized_bmp);
	al_draw_scaled_bitmap(loaded_bmp, 0, 0,
		al_get_bitmap_width(loaded_bmp),
		al_get_bitmap_height(loaded_bmp),
		0, 0, w, h, 0);
	al_set_target_bitmap(prev_target);
	al_destroy_bitmap(loaded_bmp);

	game_log("resized image: %s", filename);

	return resized_bmp;
}

// [HACKATHON 3-5]
// TODO: Define bool pnt_in_rect(int px, int py, RecArea field)
// Uncomment and fill in the code below.
/*
bool pnt_in_rect(int px, int py, RecArea field) {
	return ???;
}
*/

void setRecArea(RecArea* RA, float x, float y, float w, float h) {
	RA->x = x;
	RA->y = y;
	RA->w = w;
	RA->h = h;
}

bool RecAreaOverlap(const RecArea *const RA, const RecArea *const RB) {
	// Detect if two RecArea is overlapped.
	// reference: https://stackoverflow.com/questions/21476869/constant-pointer-vs-pointer-to-constant
	float RA_x2 = RA->x + RA->w;
	float RA_y2 = RA->y + RA->h;
	float RB_x2 = RB->x + RB->w;
	float RB_y2 = RB->y + RB->h;
	if ((fmin(RA_x2, RB_x2) > fmax(RA->x, RB->x)) && (fmin(RA_y2, RB_y2) > fmax(RA->y, RB->y)))
		return true;
	return false;
}
RecArea getDrawArea(object *obj, uint32_t TOTAL_TICK) {
	// NOTODO: return the drawing RecArea defined by object and GAME_TICK_CD
	// To understand why getDrawArea((object*)ghost, ...) works, please read https://stackoverflow.com/questions/524033/how-can-i-simulate-oo-style-polymorphism-in-c.
	RecArea target;
		
	target.x = map_offset_x + obj->Coord.x * block_width;
	target.y = map_offset_y + obj->Coord.y * block_height;
	target.w = block_width;
	target.h = block_height;

	switch (obj->preMove) {
		case UP:
			target.y += (obj->moveCD) * block_width / TOTAL_TICK;
		break;
		case DOWN:
			target.y -= (obj->moveCD) * block_width / TOTAL_TICK;
		break;
		case LEFT:
			target.x += (obj->moveCD) * block_width / TOTAL_TICK;
		break;
		case RIGHT:
			target.x -= (obj->moveCD) * block_width / TOTAL_TICK;
		break;
		case NONE:
			break;
		default:
			break;
	}

	return target;	
}
void printRecAreaInfo(const RecArea* RA) {
	// NOTODO
	game_log("RecArea info: \nx: %f, y: %f, h: %f\n",
		RA->x, RA->y, RA->w, RA->h);
}
void printDirection(const Directions a) {
	// NOTODO
	switch (a)
	{
	case NONE:
		game_log("NONE");
		break;
	case UP:
		game_log("UP");
		break;
	case DOWN:
		game_log("DOWN");
		break;
	case LEFT:
		game_log("LEFT");
		break;
	case RIGHT:
		game_log("RIGHT");
		break;
	default:
		game_log("direction error");
		break;
	}
}

bool movetime(int speed) {
	//game_log("%d %d %d", GAME_TICK, GAME_TICK_CD, speed);
	// NOTODO
	return (GAME_TICK % (GAME_TICK_CD / speed)) == 0;
}

uint32_t generateRandomNumber(uint32_t a, uint32_t b) {
	// NOTODO
	if (b < a) 
		game_abort("Error in RandomNumber, b is less than a");
//	srand(time(NULL));
	return rand() % (b - a + 1) + a;
}
double generateRandomFloat() {
	// NOTODO
//	srand(time(NULL));
	return (double)rand() / RAND_MAX;
}

bool bernoulliTrail(double p) {
	// NOTODO
	if (p >= 1 || p <= 0) 
		game_abort("Error range of p = %lf in BernoulliTrail func\n But p should be between 0.0 and 1.0", p);
	return generateRandomFloat() < p;
	
}
