#ifndef _JANELA_H_
#define _JANELA_H_
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "objetos.h"

void criarJanela(UNIVERSO *u);

//void drawImage(SDL_Surface *image, int x, int y, SDL_Surface *tela);

void liberaJanela(UNIVERSO *u);

void carregarImagens(UNIVERSO *u);

//SDL_Surface *loadImage(char *name);

#endif
