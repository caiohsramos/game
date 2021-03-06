/* Caio Ramos - NUSP 9292991 - IME USP 2016
 *
 * Spacewar
 */
#ifndef _OBJETOS_H_
#define _OBJETOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

//Struct para guardar todas as informacoes de uma Nave
typedef struct NAVE_ {
    char nome[30];
    double massa;
    double pos[2]; //vetor posicao
    double vel[2]; //vetor velocidade
    ALLEGRO_BITMAP *nave[16];
} NAVE;

//Struct para guardar todas as informacoes de um Planeta
typedef struct PLANETA_ {
    double raio;
    double massa;
    double t_sim; //tempo de simulacao
    ALLEGRO_BITMAP *planeta;
} PLANETA;

//Struct para guardar todas as informacoes de um Projetil
typedef struct PROJETIL_ {
	bool ativo;
	double massa;
    double pos[2]; //vetor posicao
    double vel[2]; //vetor velocidade
	double t;
} PROJETIL;

//Struct para guardar todas as informacoes do Universo
typedef struct UNIVERSO_ {
    NAVE *n1; //Nave 1
    NAVE *n2; //Nave 2
    PLANETA *p; //Planeta
    PROJETIL *proj; //Ponteiro para o vetor de Projeteis
	ALLEGRO_BITMAP *projetil; //ponteiro para a imagem do projetil
    int n_proj; //numero de projeteis
    double t_proj; //tempo de duracao de cada projetil
	
	//variaveis para ambiente grafico
    ALLEGRO_DISPLAY *tela;
	ALLEGRO_BITMAP *fundo;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_TIMER *timer;
} UNIVERSO;

/*	Aloca e le da entrada padrao um universo e seus componentes.
 *
 * name: UNIVERSO *lerUniverso()
 * @param: nenhum
 * @return: ponteiro para uma struct UNIVERSO_;
 *
 */
UNIVERSO *lerUniverso();

/*	Aloca e le da entrada padrao uma nave.
 *
 * name: NAVE *lerNave()
 * @param: nenhum
 * @return: ponteiro para uma struct NAVE_;
 *
 */
NAVE *lerNave();

/*	Aloca e le da entrada padrao um planeta.
 *
 * name: PLANETA *lerPlaneta()
 * @param: nenhum
 * @return: ponteiro para uma struct PLANETA_;
 *
 */
PLANETA *lerPlaneta();

/*	Aloca e le da entrada padrao um projetil.
 *
 * name: PROJETIL *lerProj(int n_proj)
 * @param: nenhum
 * @return: ponteiro para uma struct PROJETIL_;
 *
 */
PROJETIL *lerProj(int n_proj, double t_proj);

/*	Funcao que faz a impressao na saida padrao do universo e seus componentes.
 *
 * name: void imprimirUniverso(UNIVERSO *u)
 * @param: u - ponteiro para um universo;
 * @return: nenhum
 *
 */
void imprimirUniverso(UNIVERSO *u);

/*	Funcao que libera a memoria alocada para um universo e seus componentes.
 *
 * name: void liberaUniverso(UNIVERSO *u)
 * @param: u - ponteiro para um universo;
 * @return: nenhum
 *
 */
void liberaUniverso(UNIVERSO *u);

/*	Funcao que verifica colisoes entre os objeto do jogo 
 *
 * name: void liberaUniverso(UNIVERSO *u)
 * @param: u - ponteiro para um universo;
 * @return: nenhum
 *
 */
int verificaColisoes(UNIVERSO *u);

/*	Funcao que dispara um projetil a partir da nave 1 
 *
 * name: void liberaUniverso(UNIVERSO *u)
 * @param: u - ponteiro para um universo;
 * @return: nenhum
 *
 */
void disparaProj1(UNIVERSO *u);

/*	Funcao que dispara um projetil a partir da nave 2
 *
 * name: void liberaUniverso(UNIVERSO *u)
 * @param: u - ponteiro para um universo;
 * @return: nenhum
 *
 */
void disparaProj2(UNIVERSO *u);

#endif
