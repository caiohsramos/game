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
	
	//FAZER AS INICIALIZACOES DO TECLADO.......
	al_install_keyboard();
	u->timer = al_create_timer(1.0 / FPS);
	u->event_queue = al_create_event_queue();
	al_register_event_source(u->event_queue, al_get_display_event_source(u->tela));
	al_register_event_source(u->event_queue, al_get_timer_event_source(u->timer));
	al_register_event_source(u->event_queue, al_get_keyboard_event_source());


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
	al_destroy_timer(u->timer);
	al_destroy_event_queue(u->event_queue);
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

void jogar(UNIVERSO *u) {
	while(u->p->t_sim > 0.0) {
		
		//analise dos eventos do teclado, mouse e timer
		ALLEGRO_EVENT ev;
		al_start_timer(u->timer);
		bool redraw = false;
		bool key[8] = { false, false, false, false, false, false, 
			false, false};	
		al_wait_for_event(u->event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_TIMER) {
		
			if(key[KEY_W]) {
				printf("Aumento na nave 1\n");
				u->n1->vel[0] *= 2;
				u->n1->vel[1] *= 2;
			}

			if(key[KEY_A]) {
				
			}

			if(key[KEY_S]) {
				
			}
			if(key[KEY_D]) {
				
			}

			if(key[KEY_UP]) {

				printf("Aumento na nave 2\n");
				u->n2->vel[0] *= 2;
				u->n2->vel[1] *= 2;
			}
			if(key[KEY_DOWN]) {
				
			}

			if(key[KEY_LEFT]) {
				
			}

			if(key[KEY_RIGHT]) {
				
			}
			

			redraw = true;
		}
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
	
		else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch(ev.keyboard.keycode) {
				case ALLEGRO_KEY_W:
					key[KEY_W] = true;
					break;

				case ALLEGRO_KEY_A:
					key[KEY_A] = true;
					break;

				case ALLEGRO_KEY_S: 
					key[KEY_S] = true;
					break;

				case ALLEGRO_KEY_D:
					key[KEY_D] = true;
					break;
				case ALLEGRO_KEY_UP:
					key[KEY_UP] = true;
					break;

				case ALLEGRO_KEY_DOWN:
					key[KEY_DOWN] = true;
					break;

				case ALLEGRO_KEY_LEFT: 
					key[KEY_LEFT] = true;
					break;

				case ALLEGRO_KEY_RIGHT:
					key[KEY_RIGHT] = true;
					break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch(ev.keyboard.keycode) {
				case ALLEGRO_KEY_UP:
					key[KEY_UP] = false;
					break;

				case ALLEGRO_KEY_DOWN:
					key[KEY_DOWN] = false;
					break;

				case ALLEGRO_KEY_LEFT: 
					key[KEY_LEFT] = false;
					break;

				case ALLEGRO_KEY_RIGHT:
					key[KEY_RIGHT] = false;
					break;

				case ALLEGRO_KEY_W:
					key[KEY_W] = false;
					break;

				case ALLEGRO_KEY_A:
					key[KEY_A] = false;
					break;

				case ALLEGRO_KEY_S: 
					key[KEY_S] = false;
					break;

				case ALLEGRO_KEY_D:
					key[KEY_D] = false;
					break;

				//case ALLEGRO_KEY_ESCAPE:
				//	doexit = true;
				//	break;
			}
		}
		
		if(redraw && al_is_event_queue_empty(u->event_queue)) {
			redraw = false;
			simular(u);
			verificarLimites(u);
			atualizarJanela(u);
		}
	
		
		u->t_proj -= T;
		u->p->t_sim -= T;
	}
	
}
