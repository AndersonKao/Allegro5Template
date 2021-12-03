// [utility.h]
// you should put functions shared across files in this header.
// utility functions such as image processing, collision detection
// should be put here.

#ifndef SCENE_UTILITY_H
#define SCENE_UTILITY_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>

/* Utility functions */

// Load audio and check if failed.
// Supports .wav, .flac, .ogg, .it, .mod, .s3m, .xm.
ALLEGRO_SAMPLE* load_audio(const char* filename);
// Play audio once.
ALLEGRO_SAMPLE_ID play_audio(ALLEGRO_SAMPLE* sample, float volume);
// Play audio loop.
ALLEGRO_SAMPLE_ID play_bgm(ALLEGRO_SAMPLE* sample, float volume);
// Stop audio.
void stop_bgm(ALLEGRO_SAMPLE_ID sample);
// Load font and check if failed.
// Supports .ttf.
ALLEGRO_FONT* load_font(const char* filename, int size);
// Load bitmap and check if failed.
// Supports .bmp, .pcx, .tga, .jpg, .png.
ALLEGRO_BITMAP* load_bitmap(const char* filename);
// Load resized bitmap and check if failed.
ALLEGRO_BITMAP* load_bitmap_resized(const char* filename, int w, int h);
typedef struct RecArea{
	float x, y, w, h;
} RecArea;
typedef struct Pair_IntInt {
	int x;
	int y;
} Pair_IntInt;
typedef enum Directions{
	NONE = 0,
	UP = 1,
	LEFT = 2,
	RIGHT = 3,
	DOWN = 4,
	UP_DOWN = 5,
	LEFT_RIGHT = 6,
	UP_LEFT = 7,
	DOWN_LEFT = 8,
	DOWN_RIGHT = 9,
	UP_RIGHT = 10
} Directions;
typedef struct object {
	Pair_IntInt Coord; // 
	Pair_IntInt Size; // x for width, y for height
	Directions facing;
	Directions preMove;
	Directions nextTryMove;
	uint32_t moveCD;				// movement CountDown
} object;

typedef struct bitmapdata{
	int bitmap_x;
	int bitmap_y;
	int bitmap_w;
	int bitmap_h;
} bitmapdata;

//extern const int GridSize;

void setRecArea(RecArea* RA, float x, float y, float w, float h);
RecArea getDrawArea(object obj, uint32_t TICK);
bool RecAreaOverlap(const RecArea RA,const RecArea RB);
void printRecAreaInfo(const RecArea* RA);
void printDirection(const Directions a);
bool movetime(int speed);
uint32_t generateRandomNumber(uint32_t a, uint32_t b);
double generateRandomFloat(void);
bool bernoulliTrail(double p); // Given a Possibility and decided if occur.
// [HACKATHON 3-4]
// TODO: Declare a function.
// Determines whether the point (px, py) is in rect (x, y, w, h).
// Uncomment the code below.
// bool pnt_in_rect(int px, int py, RecArea field);
// TODO: More functions that can be reused across different scenes.

// TODO: More functions that can be reused across different scenes.
#endif
