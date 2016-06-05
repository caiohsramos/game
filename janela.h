/* Caio Ramos - NUSP 9292991 - IME USP 2016
 *
 * Spacewar
 */
#ifndef _JANELA_H_
#define _JANELA_H_
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "objetos.h"
#include "fisica.h"
#include "vetor.h"
#include "constantes.h"

/* Funcao que inicializa uma janela para o jogo
 *
 * name: void criarJanela(UNIVERSO *u);
 * @param: u - ponteiro para UNIVERSO, que contem todas as informacoes
 * 	para a simulacao.
 * @return: nenhum
 *
 */
void criarJanela(UNIVERSO *u);

/* Funcao que libera toda a memoria alocada para a janela e seus componentes
 *
 * name: void liberaJanela(UNIVERSO *u);
 * @param: u - ponteiro para UNIVERSO, que contem todas as informacoes
 * 	para a simulacao.
 * @return: nenhum
 *
 */
void liberaJanela(UNIVERSO *u);

/* Funcao que carrega as imagens do jogo para a memoria
 *
 * name: void carregarImagens(UNIVERSO *u);
 * @param: u - ponteiro para UNIVERSO, que contem todas as informacoes
 * 	para a simulacao.
 * @return: nenhum
 *
 */
void carregarImagens(UNIVERSO *u);

/* Funcao que atualiza os desenhos dos objetos de acordo com as posicoes
 * calculadas
 *
 * name: void atualizarJanela(UNIVERSO *u);
 * @param: u - ponteiro para UNIVERSO, que contem todas as informacoes
 * 	para a simulacao.
 * @return: nenhum
 *
 */
void atualizarJanela(UNIVERSO *u);

/* Funcao que escolhe o melhor desenho de nave para um certo de angulo.
 *
 * name: int escolherNave(double theta);
 * @param: theta - angulo da nave (graus)
 * @return: posicao do vetor a ser usada no desenho
 *
 */
int escolherNave(double theta);

/* Funcao que verifica se as posicoes calculadas estao fora do limite da
 * tela (800x600)
 *
 * name: void verificarLimites(UNIVERSO *u);
 * @param: u - ponteiro para UNIVERSO, que contem todas as informacoes
 * 	para a simulacao.
 * @return: nenhum
 *
 */
void verificarLimites(UNIVERSO *u);

/* Funcao que faz o desenho e simulalçao do jogo 
 *
 * name: void jogar(UNIVERSO *u);
 * @param: u - ponteiro para UNIVERSO, que contem todas as informacoes
 * 	para a simulacao.
 * @return: nenhum
 *
 */
void jogar(UNIVERSO *u);

#endif
