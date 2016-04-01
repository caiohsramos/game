#ifndef OBJETOS_H_
#define OBJETOS_H_

typedef struct NAVE_ {
    char nome[30];
    double massa;
    double posx;
    double posy;
    double velx;
    double vely;
} NAVE;

typedef struct PLANETA_ {
    double raio;
    double massa;
    double t_sim;
} PLANETA;

typedef struct PROJETIL_ {
	double massa;
    double posx;
    double posy;
    double velx;
    double vely;
} PROJETIL;

typedef struct UNIVERSO_ {
    NAVE *n1;
    NAVE *n2;
    PLANETA *p;
    PROJETIL *proj;
    double t_sim;
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
