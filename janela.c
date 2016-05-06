#include "janela.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

void criarJanela(UNIVERSO *u) {
	al_init();
	al_init_image_addon();
	
	u->tela = al_create_display(800, 600);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	
	carregarImagens(u);
	
	/*
	al_draw_bitmap(u->p->planeta, 350, 250, 0);
	al_draw_bitmap(u->n1->nave[0], 50, 300, 0);
	al_draw_bitmap(u->n2->nave[8], 700, 300, 0);
    */
    al_flip_display();
}

void carregarImagens(UNIVERSO *u) {
	
	int i;
	char filename[30];
	u->p->planeta = al_load_bitmap("./img/planeta.png");
	//arrumar o jeito que a Surface projetil esta organizada
	//u->proj[0].projetil = loadImage("./img/projetil.png");
	
	for(i = 0; i < 16; i++) {
		sprintf(filename, "./img/nave1-%d.png", i);
		u->n1->nave[i] = al_load_bitmap(filename);
		sprintf(filename, "./img/nave2-%d.png", i);
		u->n2->nave[i] = al_load_bitmap(filename);
	}
	//CARREGAR AS IMAGENS DO FUNDO
	
}

void atualizarJanela(UNIVERSO *u) {
	//mexer nessa funcao...
	int x, y;
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(u->p->planeta, 350, 250, 0);
	
	//AQUI
	x = u->n1->pos[0]/10000.0;
	y = u->n1->pos[1]/10000.0;
	al_draw_bitmap(u->n1->nave[0], x, y, 0);
	
	//AQUI
	x = u->n2->pos[0]/10000.0;
	y = u->n2->pos[1]/10000.0;
	al_draw_bitmap(u->n2->nave[0], x, x, 0);
	
	al_flip_display();
	al_rest(0.3);
}


void liberaJanela(UNIVERSO *u) {
	al_destroy_display(u->tela);
	al_destroy_bitmap(u->p->planeta);
	int i;
	//SDL_FreeSurface(u->proj[0].projetil);
	for(i = 0; i < 16; i++) {
		al_destroy_bitmap(u->n1->nave[i]);
		al_destroy_bitmap(u->n2->nave[i]);
	}
		
}


