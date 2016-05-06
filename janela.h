#ifndef _JANELA_H_
#define _JANELA_H_
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "objetos.h"

void criarJanela(UNIVERSO *u);


void liberaJanela(UNIVERSO *u);

void carregarImagens(UNIVERSO *u);

void atualizarJanela(UNIVERSO *u);

#endif
