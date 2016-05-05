/* Caio Ramos - NUSP 9292991 - IME USP 2016
 * 
 * Spacewar
 */
#include "objetos.h"
#include "janela.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

UNIVERSO *lerUniverso() {
	UNIVERSO *u = (UNIVERSO*)malloc(sizeof(UNIVERSO));
	u->p = lerPlaneta();
	u->n1 = lerNave();
	u->n2 = lerNave();
	scanf("%d", &(u->n_proj));
	scanf("%lf", &(u->t_proj));
	u->proj = lerProj(u->n_proj);
	return u;
}

NAVE *lerNave() {
	NAVE *n = (NAVE*)malloc(sizeof(NAVE));
	scanf("%s", n->nome);
	scanf("%lf", &(n->massa));
	scanf("%lf", &(n->pos[0]));
	scanf("%lf", &(n->pos[1]));
	scanf("%lf", &(n->vel[0]));
	scanf("%lf", &(n->vel[1]));
	
	return n;
}

PLANETA *lerPlaneta() {
	PLANETA *p = (PLANETA*)malloc(sizeof(PLANETA));
	scanf("%lf", &(p->raio));
	scanf("%lf", &(p->massa));
	scanf("%lf", &(p->t_sim));
	
	return p;
}

PROJETIL *lerProj(int n_proj) {
	PROJETIL *proj = (PROJETIL*)malloc(n_proj*sizeof(PROJETIL));
	int i;
	for(i = 0; i < n_proj; i++) {
		scanf("%lf", &(proj[i].massa));
		scanf("%lf", &(proj[i].pos[0]));
		scanf("%lf", &(proj[i].pos[1]));
		scanf("%lf", &(proj[i].vel[0]));
		scanf("%lf", &(proj[i].vel[1]));
	}
	return proj;
}

void imprimirUniverso(UNIVERSO *u) {
	printf("Planeta:\n");
	printf("\tRaio: %.2lf\n", u->p->raio);
	printf("\tMassa: %.2lf\n", u->p->massa);
	printf("\tt_sim: %.2lf\n", u->p->t_sim);
	
	printf("Nave 1:\n");
	printf("\tNome: %s\n", u->n1->nome);
	printf("\tMassa: %.2lf\n", u->n1->massa);
	printf("\tposx: %.2lf, posy: %.2lf\n", u->n1->pos[0], u->n1->pos[1]);
	printf("\tvelx: %.2lf, vely: %.2lf\n", u->n1->vel[0], u->n1->vel[1]);
	
	printf("Nave 2:\n");
	printf("\tNome: %s\n", u->n2->nome);
	printf("\tMassa: %.2lf\n", u->n2->massa);
	printf("\tposx: %.2lf, posy: %.2lf\n", u->n2->pos[0], u->n2->pos[1]);
	printf("\tvelx: %.2lf, vely: %.2lf\n", u->n2->vel[0], u->n2->vel[1]);
	
	printf("Numero de projeteis e duracao:\n\t%d projeteis, %.2lf\n", u->n_proj, u->t_proj);
	
	int i;
	for(i = 0; i < u->n_proj; i++) {
		printf("Projetil %d:\n", i+1);
		printf("\tMassa: %.2lf\n", u->n1->massa);
		printf("\tposx: %.2lf, posy: %.2lf\n", u->proj[i].pos[0], u->proj[i].pos[1]);
		printf("\tvelx: %.2lf, vely: %.2lf\n", u->proj[i].vel[0], u->proj[i].vel[1]);
	}
	
}

void liberaUniverso(UNIVERSO *u) {
	liberaJanela(u);
	free(u->p);
	free(u->n1);
	free(u->n2);
	free(u->proj);
	free(u);
}
