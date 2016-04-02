#ifndef _OBJETOS_H_
#define _OBJETOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NAVE_ {
    char nome[30];
    double massa;
    double pos[2];
    double vel[2];
} NAVE;

typedef struct PLANETA_ {
    double raio;
    double massa;
    double t_sim;
} PLANETA;

typedef struct PROJETIL_ {
	double massa;
    double pos[2];
    double vel[2];
} PROJETIL;

typedef struct UNIVERSO_ {
    NAVE *n1;
    NAVE *n2;
    PLANETA *p;
    PROJETIL *proj;
    int n_proj;
    double t_proj;
} UNIVERSO;


UNIVERSO *lerUniverso();
NAVE *lerNave();
PLANETA *lerPlaneta();
PROJETIL *lerProj(int n_proj);
void imprimirUniverso(UNIVERSO *u);
void liberaUniverso(UNIVERSO *u);


#endif
