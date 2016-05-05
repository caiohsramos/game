#include "janela.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

void criarJanela(UNIVERSO *u) {
	/*
	SDL_Init(SDL_INIT_VIDEO);
	u->tela = SDL_SetVideoMode(800, 600, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);
	SDL_WM_SetCaption("GAME", NULL);
	carregarImagens(u);
	drawImage(u->p->planeta, 350, 250, u->tela);
	drawImage(u->n1->nave[0], 50, 300, u->tela);
	drawImage(u->n2->nave[8], 700, 300, u->tela);
	//drawImage(u->proj[0].projetil, 400, 100, u->tela);
	SDL_Flip(u->tela);
	// Sleep briefly 
	
	SDL_Delay(1);
	*/
	
	al_init();
	al_init_image_addon();
	u->tela = al_create_display(800, 600);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	carregarImagens(u);
	al_draw_bitmap(u->p->planeta, 350, 250, 0);
	al_draw_bitmap(u->n1->nave[0], 50, 300, 0);
	al_draw_bitmap(u->n2->nave[8], 700, 300, 0);
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

/*
void drawImage(SDL_Surface *image, int x, int y, SDL_Surface *tela)
{
	*
    SDL_Rect dest;

    * Set the blitting rectangle to the size of the src image *

    dest.x = x;
    dest.y = y;
    dest.w = image->w;
    dest.h = image->h;

    * Blit the entire image onto the screen at coordinates x and y *

    SDL_BlitSurface(image, NULL, tela, &dest);
    *
}
*/

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
