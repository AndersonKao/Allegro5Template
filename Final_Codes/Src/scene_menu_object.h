#ifndef MENU_OBJECT_H
#define MENU_OBJECT_H

#include "utility.h"
#include "shared.h"
#include "game.h"

typedef struct Button {
	RecArea body;
	ALLEGRO_BITMAP* default_img;
	ALLEGRO_BITMAP* hovered_img;
	bool hovered;
}Button;

Button button_create(float, float, float, float, const char*, const char*);
void drawButton(Button button);
bool buttonHover(Button, int, int);

#endif
