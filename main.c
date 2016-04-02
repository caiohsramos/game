#include "fisica.h"
#include "objetos.h"
#include <stdio.h>


int main(int argc, char *argv[]) {
	UNIVERSO *u = lerUniverso();

	imprimirUniverso(u);
	printf("----------------------------------------------------------\n");
	simular(u);
	liberaUniverso(u);
	return 0;
}
