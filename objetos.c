#include "objetos.h"
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
	scanf("%lf", &(n->posx));
	scanf("%lf", &(n->posy));
	scanf("%lf", &(n->velx));
	scanf("%lf", &(n->vely));
	
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
		scanf("%lf", &(proj[i].posx));
		scanf("%lf", &(proj[i].posy));
		scanf("%lf", &(proj[i].velx));
		scanf("%lf", &(proj[i].vely));
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
	printf("\tposx: %.2lf, posy: %.2lf\n", u->n1->posx, u->n1->posy);
	printf("\tvelx: %.2lf, vely: %.2lf\n", u->n1->velx, u->n1->vely);
	
	printf("Nave 2:\n");
	printf("\tNome: %s\n", u->n2->nome);
	printf("\tMassa: %.2lf\n", u->n2->massa);
	printf("\tposx: %.2lf, posy: %.2lf\n", u->n2->posx, u->n2->posy);
	printf("\tvelx: %.2lf, vely: %.2lf\n", u->n2->velx, u->n2->vely);
	
	printf("Numero de projeteis e duracao:\n\t%d projeteis, %.2lf\n", u->n_proj, u->t_proj);
	
	int i;
	for(i = 0; i < u->n_proj; i++) {
		printf("Projetil %d:\n", i+1);
		printf("\tMassa: %.2lf\n", u->n1->massa);
		printf("\tposx: %.2lf, posy: %.2lf\n", u->proj[i].posx, u->proj[i].posy);
		printf("\tvelx: %.2lf, vely: %.2lf\n", u->proj[i].velx, u->proj[i].vely);
	}
	
}

void liberaUniverso(UNIVERSO *u) {
	free(u->p);
	free(u->n1);
	free(u->n2);
	free(u->proj);
	free(u);
}
