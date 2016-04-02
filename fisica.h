#ifndef _FISICA_H_
#define _FISICA_H_
#include "objetos.h"
#include "constantes.h"
#include "vetor.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


//força que a nave n sofre do planeta p
void forcaPlaneta(double *f, NAVE *n, PLANETA *p);
 
//força que a n1 sofre da n2
void forcaNave(double *f, NAVE *n1, NAVE *n2);

void moveNave(double *f, NAVE *n);

void forcaPlanetaProj(double *f, PROJETIL *proj, PLANETA *p);
 
void forcaNaveProj(double *f, PROJETIL *proj, NAVE *n);

void moveProj(double *f, PROJETIL *proj);

void simular(UNIVERSO *u);

#endif
