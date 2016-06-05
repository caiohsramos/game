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
	
	carregarImagens(u);
	
	//FAZ AS INICIALIZACOES DO TECLADO.......
	al_install_keyboard();
	u->timer = al_create_timer(1.0 / FPS);
	u->event_queue = al_create_event_queue();
	al_register_event_source(u->event_queue, al_get_display_event_source(u->tela));
	al_register_event_source(u->event_queue, al_get_timer_event_source(u->timer));
	al_register_event_source(u->event_queue, al_get_keyboard_event_source());


	al_draw_bitmap(u->fundo, 0, 0, 0);
	al_draw_bitmap(u->p->planeta, 350, 250, 0);
    
    al_flip_display();
}

void carregarImagens(UNIVERSO *u) {
	
	int i;
	char filename[30];
	u->fundo = al_load_bitmap("./img/fundo.jpg");
	u->p->planeta = al_load_bitmap("./img/planeta.png");
	u->projetil = al_load_bitmap("./img/projetil.png");
	
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
	al_draw_bitmap(u->fundo, 0, 0, 0);
	
	x = (u->n1->pos[0]+380);
	y = (u->n1->pos[1]+280);
	theta = sentido(u->n1->vel);
	
	al_draw_bitmap(u->n1->nave[escolherNave(theta)], x, y, 0);
	
	x = (u->n2->pos[0]+380);
	y = (u->n2->pos[1]+280);
	theta = sentido(u->n2->vel);
	
	al_draw_bitmap(u->n2->nave[escolherNave(theta)], x, y, 0);

	//Desenhar projeteis
	int i;
	for(i = 0; i < u->n_proj; i++) { 
		if(u->proj[i].ativo) {
			x = (u->proj[i].pos[0]+395);
			y = (u->proj[i].pos[1]+295);
			al_draw_bitmap(u->projetil, x, y, 0);
		}
	}

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
	al_destroy_bitmap(u->projetil);
	al_destroy_bitmap(u->fundo);
		
}


void verificarLimites(UNIVERSO *u) {
	//nave1 - posicao
	if(u->n1->pos[0] > 400 || u->n1->pos[0] < -400) u->n1->pos[0] = -(u->n1->pos[0]);
	if(u->n1->pos[1] > 300 || u->n1->pos[1] < -300) u->n1->pos[1] = -(u->n1->pos[1]);
	//nave1 - velocidade
	if(u->n1->vel[0] > 200)  u->n1->vel[0] = 200;
	if(u->n1->vel[0] < -200) u->n1->vel[0] = -200;
	if(u->n1->vel[1] > 200)  u->n1->vel[1] = 200;
	if(u->n1->vel[1] < -200) u->n1->vel[1] = -200;
	//nave2 - posicao
	if(u->n2->pos[0] > 400|| u->n2->pos[0] < -400) u->n2->pos[0] = -(u->n2->pos[0]);
	if(u->n2->pos[1] > 300|| u->n2->pos[1] < -300) u->n2->pos[1] = -(u->n2->pos[1]);	
	//nave2 - velocidade
	if(u->n2->vel[0] > 200)  u->n2->vel[0] = 200;
	if(u->n2->vel[0] < -200) u->n2->vel[0] = -200;
	if(u->n2->vel[1] > 200)  u->n2->vel[1] = 200;
	if(u->n2->vel[1] < -200) u->n2->vel[1] = -200;
	//verificar limites para os projeteis
	int i;
	for(i = 0; i < u->n_proj; i++) {
		if(!u->proj[i].ativo) continue;
		if(u->proj[i].pos[0] > 400 || u->proj[i].pos[0] < -400) u->proj[i].pos[0] = -(u->proj[i].pos[0]);
		if(u->proj[i].pos[1] > 300 || u->proj[i].pos[1] < -300) u->proj[i].pos[1] = -(u->proj[i].pos[1]);
	}
}

void jogar(UNIVERSO *u) {
	bool key[10] = { false, false, false, false, false, false, 
		false, false, false, false};	
	while(u->p->t_sim > 0.0) {
		
		//analise dos eventos do teclado, mouse e timer
		ALLEGRO_EVENT ev;
		al_start_timer(u->timer);
		bool redraw = false;
		al_wait_for_event(u->event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_TIMER) {
			if(key[KEY_W]) {
				produto_esc(u->n1->vel, 1.05, u->n1->vel);
			}

			if(key[KEY_A]) {
				rotaciona_menos10(u->n1->vel);
			}

			if(key[KEY_S]) {
				produto_esc(u->n1->vel, 0.95, u->n1->vel);
			}
			if(key[KEY_D]) {
				rotaciona_10(u->n1->vel);	
			}

			if(key[KEY_UP]) {
				produto_esc(u->n2->vel, 1.05, u->n2->vel);
			
			}
			if(key[KEY_DOWN]) {
				produto_esc(u->n2->vel, 0.95, u->n2->vel);
			}

			if(key[KEY_LEFT]) {
				rotaciona_menos10(u->n2->vel);
			}

			if(key[KEY_RIGHT]) {
				rotaciona_10(u->n2->vel);	
			}
			
			if(key[KEY_G]) {
				//dispara projetil (nave 1)
				if(!u->proj[0].ativo) {
					disparaProj1(u);
				}
			}
			
			if(key[KEY_L]) {
				//dispara projetil (nave 2)
				if(!u->proj[1].ativo) {
					disparaProj2(u);
				}
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
				case ALLEGRO_KEY_G:
					key[KEY_G] = true;
					break;
				case ALLEGRO_KEY_L:
					key[KEY_L] = true;
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

				case ALLEGRO_KEY_G:
					key[KEY_G] = false;
					break;

				case ALLEGRO_KEY_L:
					key[KEY_L] = false;
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
			if(verificaColisoes(u)) break;
			atualizarJanela(u);
		}
	
		
		//u->t_proj -= T;
		u->p->t_sim -= T;
	}
	
}
