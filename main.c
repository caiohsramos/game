/* Caio Ramos - NUSP 9292991 - IME USP 2016
 *
 * Spacewar
 */
#include "fisica.h"
#include "objetos.h"
#include <stdio.h>
#include "janela.h"
#include "constantes.h"

int main(int argc, char *argv[]) {
	if(argc != 2) exit(0);
	else T = atof(argv[1]);
	UNIVERSO *u = lerUniverso();
	
	imprimirUniverso(u);
	printf("----------------------------------------------------------\n");

	criarJanela(u);
	al_rest(1.0);
	jogar(u);
	liberaUniverso(u);
	return 0;
}
