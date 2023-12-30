.PHONY: clean

CC=gcc
SRC=Src
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	CCFLAGS=$$(pkg-config allegro-5 allegro_font-5 allegro_ttf-5 allegro_audio-5 allegro_image-5 allegro_primitives-5 allegro_acodec-5 --libs --cflags)
	INCLUDE=/usr/include/allegro5
endif
ifeq ($(UNAME_S), Darwin)
	CCFLAGS=$$(pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_ttf-5 allegro_audio-5 allegro_image-5 allegro_primitives-5 allegro_acodec-5 --libs --cflags)
	INCLUDE=/opt/homebrew/Cellar/allegro/5.2.9.0/include
endif
#REVISE INCLUDE path if you have installed different version or install path.

DBG = -g -fsanitize=address
WARNINGS = -Wall -Wextra # add `$(WARNINGS)`  compile flag in line 26 and 29 if you want additional compile check warnings
objects= main.o game.o ghost.o ghost_move_script.o map.o pacman_obj.o scene_game.o scene_menu.o scene_menu_object.o scene_settings.o shared.o utility.o

all: pacman 

pacman: $(objects)
	$(CC) -lm $(CCFLAGS) $(DBG) -o pacman $^

%.o: $(SRC)/%.c $(SRC)/%.h
	$(CC) -I$(INCLUDE) $(DBG) -c $< -o $@

%.o: $(SRC)/%.c
	$(CC) -I$(INCLUDE) $(DBG) -c $< -o $@

clean:
	rm pacman *.o
