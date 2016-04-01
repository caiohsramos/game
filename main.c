#include "fisica.h"
#include "objetos.h"


int main(int argc, char *argv[]) {
	UNIVERSO *u = lerUniverso();
	
	imprimirUniverso(u);
	simular(u);
	liberaUniverso(u);
	return 0;
}
