#ifndef FISICA_H_
#define FISICA_H_

#define M_TERRA 6.02e24
#define R_TERRA 6.4e6
#define CTE_G 6.67e-11
#define T 1/60

#include "objetos.h"
double aceleracaoPlaneta(PLANETA *p, NAVE *n);
double aceleracaoNave(NAVE *n1, NAVE *n2);
void simular(UNIVERSO *u);
double v(double v0, double a, double t);
double s(double s0, double v0, double a, double t);

#endif
