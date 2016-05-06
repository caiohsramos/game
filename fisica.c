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
	while(u->p->t_sim > 0.0) {
		
		//calcula nova posicao n1.
			//forcas: planeta, n2.
		forcaNave(f_total, u->n1, u->n2);
		forcaPlaneta(f, u->n1, u->p);
		soma_vet(f_total, f, f_total);
		moveNave(f_total, u->n1);
		
		//printf("N1:\n");
		//printf("%.15lf %.15lf\n", u->n1->pos[0], u->n1->pos[1]);
		
		//calcula nova posicao n2.
			//forcas: planeta, n1.
		forcaNave(f_total, u->n2, u->n1);
		forcaPlaneta(f, u->n2, u->p);
		soma_vet(f_total, f, f_total);
		moveNave(f_total, u->n2);
		
		//printf("N2:\n");
		//printf("%.15lf %.15lf\n", u->n2->pos[0], u->n2->pos[1]);
		
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
				//printf("PROJETIL%d:\n", i+1);
				//printf("%.15lf %.15lf\n", u->proj[i].pos[0], u->proj[i].pos[1]);
			}
		}
		atualizarJanela(u);
		u->t_proj -= T;
		u->p->t_sim -= T;
	}
}
