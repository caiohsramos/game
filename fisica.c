#include "fisica.h"
#include <stdlib.h>
#include <math.h>


double aceleracaoPlaneta(PLANETA *p, NAVE *n) {
    double dist_2 = ((n->posx)*(n->posx)) + ((n->posy)*(n->posy));
    double a = -(CTE_G*(p->massa))/dist_2;
    return a;
}

double aceleracaoNave(NAVE *n1, NAVE *n2) {
    double dist_2 = pow(((n1->posx)-(n2->posx)), 2) + pow(((n1->posy)-(n2->posy)), 2);
    double a = -(CTE_G*(n2->massa))/dist_2;
    return a;
}

double v(double v0, double a, double t) {
	return (v0 + a*t);
}

double s(double s0, double v0, double a, double t) {
	return (s0 + v0*t + (a*t*t/2));
}

void simular(UNIVERSO *u) {
	if(u->t_sim <= 0) return;
	//faz a simulacao....
	double ax;
	double ay;
	double a;
	//calcula nova posicao n1.
		//forcas: planeta, n2.
	ax = 0;
	ay = 0;	
	
	a = aceleracaoPlaneta(u->p, u->n1);
	ax += a*cos(atan((u->n1->posy)/(u->n1->posx)));
	ay += a*sin(atan((u->n1->posy)/(u->n1->posx)));
	
	a = aceleracaoNave(u->n1, u->n2);
	ax += a*cos(atan((u->n1->posy)/(u->n1->posx)));
	ay += a*sin(atan((u->n1->posy)/(u->n1->posx)));
	
	
	
	//calcula nova posicao n2.
		//forcas: planeta, n1.
	ax = 0;
	ay = 0;
	
	a = aceleracaoPlaneta(u->p, u->n2);
	ax += a*cos(atan((u->n2->posy)/(u->n2->posx)));
	ay += a*sin(atan((u->n2->posy)/(u->n2->posx)));
	
	a = aceleracaoNave(u->n2, u->n1);
	ax += a*cos(atan((u->n2->posy)/(u->n2->posx)));
	ay += a*sin(atan((u->n2->posy)/(u->n2->posx)));
	
	//calcula nova posicao de cada projetil (for u->proj[i]).
		//forcas: planeta, n1, n2.
	
	simular(u);
}
