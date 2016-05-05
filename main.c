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
	//SDL_Delay(4000);
	al_rest(5.0);
	//simular(u);
	liberaUniverso(u);
	return 0;
}
