/* Caio Ramos - NUSP 9292991 - IME USP 2016
 *
 * Spacewar
 */
#include "janela.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

void criarJanela(UNIVERSO *u) {
	al_init();
	al_init_image_addon();
	
	u->tela = al_create_display(800, 600);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	
	carregarImagens(u);
	

	al_draw_bitmap(u->p->planeta, 350, 250, 0);
    
    al_flip_display();
}

void carregarImagens(UNIVERSO *u) {
	
	int i;
	char filename[30];
	u->p->planeta = al_load_bitmap("./img/planeta.png");
	//arrumar o jeito que o Bitmap projetil esta organizado
	//u->proj[0].projetil = loadImage("./img/projetil.png");
	
	for(i = 0; i < 16; i++) {
		sprintf(filename, "./img/nave1-%d.png", i);
		u->n1->nave[i] = al_load_bitmap(filename);
		sprintf(filename, "./img/nave2-%d.png", i);
		u->n2->nave[i] = al_load_bitmap(filename);
	}
	
}

int escolherNave(double theta) {
	int k = round(theta/22.5);
	if (k<0) k = 16+k;
	
	return (k+12)%16;
}

void atualizarJanela(UNIVERSO *u) {
	int x, y;
	double theta;
	al_clear_to_color(al_map_rgb(0, 0, 0));
	
	x = (u->n1->pos[0]+380);
	y = (u->n1->pos[1]+280);
	theta = sentido(u->n1->vel);
	
	al_draw_bitmap(u->n1->nave[escolherNave(theta)], x, y, 0);
	
	x = (u->n2->pos[0]+380);
	y = (u->n2->pos[1]+280);
	theta = sentido(u->n2->vel);
	
	al_draw_bitmap(u->n2->nave[escolherNave(theta)], x, y, 0);
	
	al_draw_bitmap(u->p->planeta, 350, 250, 0);	
	
	al_flip_display();
}


void liberaJanela(UNIVERSO *u) {
	al_destroy_display(u->tela);
	al_destroy_bitmap(u->p->planeta);
	int i;
	for(i = 0; i < 16; i++) {
		al_destroy_bitmap(u->n1->nave[i]);
		al_destroy_bitmap(u->n2->nave[i]);
	}
		
}


void verificarLimites(UNIVERSO *u) {
	//nave1
	if(u->n1->pos[0] > 400 || u->n1->pos[0] < -400) u->n1->pos[0] = -(u->n1->pos[0]);
	if(u->n1->pos[1] > 300 || u->n1->pos[1] < -300) u->n1->pos[1] = -(u->n1->pos[1]);
	//nave2
	if(u->n2->pos[0] > 400|| u->n2->pos[0] < -400) u->n2->pos[0] = -(u->n2->pos[0]);
	if(u->n2->pos[1] > 300|| u->n2->pos[1] < -300) u->n2->pos[1] = -(u->n2->pos[1]);	
}
