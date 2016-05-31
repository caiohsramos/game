/* Caio Ramos - NUSP 9292991 - IME USP 2016
 * 
 * Spacewar
 */
#include "fisica.h"


void forcaPlaneta(double *f, NAVE *n, PLANETA *p) {
	double dist;
	dist = magnitude(n->pos);
	double force = (CTE_G * n->massa * p->massa) / (dist * dist);
	direcao(n->pos, f);
	produto_esc(f, -force, f);
}
 
void forcaNave(double *f, NAVE *n1, NAVE *n2) {
	double delta[2];
	subt_vet(delta, n2->pos, n1->pos);
	double dist = magnitude(delta);
	double force = (CTE_G * n1->massa * n2->massa) / (dist * dist);
	direcao(delta, f);
	produto_esc(f, force, f);
}

void moveNave(double *f, NAVE *n) {
	double aux[2];
	produto_esc(aux, 1.0/n->massa, f);
	produto_esc(aux, T, aux);
	soma_vet(n->vel, n->vel, aux);
	
	
	produto_esc(aux, T, n->vel);
	soma_vet(n->pos, n->pos, aux);
}


void forcaPlanetaProj(double *f, PROJETIL *proj, PLANETA *p) {
	double dist;
	dist = magnitude(proj->pos);
	double force = (CTE_G * proj->massa * p->massa) / (dist * dist);
	direcao(proj->pos, f);
	produto_esc(f, -force, f);
}
 
void forcaNaveProj(double *f, PROJETIL *proj, NAVE *n) {
	double delta[2];
	subt_vet(delta, n->pos, proj->pos);
	double dist = magnitude(delta);
	double force = (CTE_G * proj->massa * n->massa) / (dist * dist);
	direcao(delta, f);
	produto_esc(f, force, f);
}

void moveProj(double *f, PROJETIL *proj) {
	double aux[2];
	produto_esc(aux, 1.0/proj->massa, f);
	produto_esc(aux, T, aux);
	soma_vet(proj->vel, proj->vel, aux);
	
	
	produto_esc(aux, T, proj->vel);
	soma_vet(proj->pos, proj->pos, aux);
}


void simular(UNIVERSO *u) {
	double f[2];
	double f_total[2];
	int i;
	
	al_start_timer(u->timer);
	while(u->p->t_sim > 0.0) {
		
		//calcula nova posicao n1.
			//forcas: planeta, n2.
		forcaNave(f_total, u->n1, u->n2);
		forcaPlaneta(f, u->n1, u->p);
		soma_vet(f_total, f, f_total);
		moveNave(f_total, u->n1);
		
		
		//calcula nova posicao n2.
			//forcas: planeta, n1.
		forcaNave(f_total, u->n2, u->n1);
		forcaPlaneta(f, u->n2, u->p);
		soma_vet(f_total, f, f_total);
		moveNave(f_total, u->n2);
		
		
		//calcula nova posicao de cada projetil
			//forcas: planeta, n1, n2.
		if(u->t_proj > 0) {
			for(i = 0; i < u->n_proj; i++) {
				forcaNaveProj(f_total, &(u->proj[i]), u->n1);
				forcaNaveProj(f, &(u->proj[i]), u->n2);
				soma_vet(f_total, f, f_total);
				forcaPlanetaProj(f, &(u->proj[i]), u->p);
				soma_vet(f_total, f, f_total);
				moveProj(f_total, &(u->proj[i]));
			}
		}

		//tentar colocar as condicoes da event_queue aqui

		ALLEGRO_EVENT ev;
		bool redraw = true;
		al_wait_for_event(u->event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_TIMER) {
			/*if(key[KEY_UP] && bouncer_y >= 4.0) {
				bouncer_y -= 4.0;
			}

			if(key[KEY_DOWN] && bouncer_y <= SCREEN_H - BOUNCER_SIZE - 4.0) {
				bouncer_y += 4.0;
			}

			if(key[KEY_LEFT] && bouncer_x >= 4.0) {
				bouncer_x -= 4.0;
			}

			if(key[KEY_RIGHT] && bouncer_x <= SCREEN_W - BOUNCER_SIZE - 4.0) {
				bouncer_x += 4.0;
			}
			*/

			redraw = true;
		}
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		/*
		else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch(ev.keyboard.keycode) {
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

				case ALLEGRO_KEY_ESCAPE:
					doexit = true;
					break;
			}
		}
		*/
		if(redraw && al_is_event_queue_empty(u->event_queue)) {
			redraw = false;
			atualizarJanela(u);
		}
	
		
		verificarLimites(u);
		u->t_proj -= T;
		u->p->t_sim -= T;
	}
}
