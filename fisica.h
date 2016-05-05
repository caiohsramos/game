/* Caio Ramos - NUSP 9292991 - IME USP 2016
 *
 * Spacewar
 */
#ifndef _FISICA_H_
#define _FISICA_H_
#include "objetos.h"
#include "constantes.h"
#include "vetor.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Funcao que calcula a força que a nave 'n', sofre do planeta 'p', e é
 * 	retornada no parametro 'f';
 *
 * name: void forcaPlaneta(double *f, NAVE *n, PLANETA *p)
 * @param: f - vetor de retorno da forca, n - ponteiro para a nave,
 * 	p - ponteiro para o planeta;
 * @return: nenhum
 *
 */
void forcaPlaneta(double *f, NAVE *n, PLANETA *p);

/* Funcao que calcula a força que a nave 'n1', sofre da nave 'n2', e é
 * 	retornada no parametro 'f';
 *
 * name: void forcaNave(double *f, NAVE *n1, NAVE *n2)
 * @param: f - vetor de retorno da forca, n1 - ponteiro para a nave 1,
 * 	n2 - ponteiro para a nave 2;
 * @return: nenhum
 *
 */
void forcaNave(double *f, NAVE *n1, NAVE *n2);

/* Funcao que altera a posicao da nave passada como parametro de acordo
 * 	com a forca, tambem passada como parametro;
 *
 * name: void moveNave(double *f, NAVE *n)
 * @param: f - vetor forca, n - ponteiro para a nave;
 * @return: nenhum
 *
 */
void moveNave(double *f, NAVE *n);

/* Funcao que calcula a força que o projetil 'proj', sofre do planeta 'p', e é
 * 	retornada no parametro 'f';
 *
 * name: void forcaPlanetaProj(double *f, PROJETIL *proj, PLANETA *p)
 * @param: f - vetor de retorno da forca, proj - ponteiro para o projetil,
 * 	p - ponteiro para o planeta;
 * @return: nenhum
 *
 */
void forcaPlanetaProj(double *f, PROJETIL *proj, PLANETA *p);

/* Funcao que calcula a força que o projetil 'proj', sofre da nave 'n', e é
 * 	retornada no parametro 'f';
 *
 * name: void forcaNaveProj(double *f, PROJETIL *proj, NAVE *n)
 * @param: f - vetor de retorno da forca, proj - ponteiro para o projetil,
 * 	n - ponteiro para a nave;
 * @return: nenhum
 *
 */
void forcaNaveProj(double *f, PROJETIL *proj, NAVE *n);

/* Funcao que altera a posicao do projetil passado como parametro de acordo
 * 	com a forca, tambem passada como parametro;
 *
 * name: void moveProj(double *f, PROJETIL *proj)
 * @param: f - vetor forca, proj - ponteiro para o projetil;
 * @return: nenhum
 *
 */
void moveProj(double *f, PROJETIL *proj);

/* Funcao que faz uma simulacao do que ocorre no universo 'u', passado
 * 	como parametro;
 *
 * name: void simular(UNIVERSO *u)
 * @param: u - ponteiro para UNIVERSO, que contem todas as informacoes
 * 	para a simulacao.
 * @return: nenhum
 *
 */
void simular(UNIVERSO *u);

#endif
