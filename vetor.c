/* Caio Ramos - NUSP 9292991 - IME USP 2016
 * 
 * Spacewar
 */
#include "vetor.h"
#include <math.h>

//'a' = 'b' + 'c'
void soma_vet(double *a, double *b, double *c) {
	a[0] = b[0] + c[0];
	a[1] = b[1] + c[1];
}

//'a' = 'b' - 'c'
void subt_vet(double *a, double *b, double *c) {
	a[0] = b[0] - c[0];
	a[1] = b[1] - c[1];
}

//'a' = 'b'(escalar) * 'c'(vetor)
void produto_esc(double *a, double b, double *c) {
	a[0] = b * c[0];
	a[1] = b * c[1];
}

//'a' = 'b'(escalar) + 'c'(vetor)
void soma_esc(double *a, double b, double *c) {
	a[0] = b + c[0];
	a[1] = b + c[1];
}

//magnitude do vetor 'a'
double magnitude(double *a) {
	return sqrt(dot(a, a));
}

//produto vetorial de 'a' com 'b'
double dot(double *a, double *b) {
	double sum = 0.0;
	sum += a[0]*b[0];
	sum += a[1]*b[1];
	return sum;
}

//distancia de 'a' ate 'b'
double distancia(double *a, double *b) {
	double c[2];
	subt_vet(c, a, b);
	return magnitude(c);
}

//direcao de 'a' retornada no 'b'
void direcao(double *a, double *b) {
	produto_esc(b, 1.0/magnitude(a), a);
}

//sentido de 'a' em relacao ao eixo X (graus)
double sentido(double *a) {
	return atan2(a[0], a[1])*180.0/M_PI;
}
	
void rotaciona_menos10(double *a) {
	double x, y;
	x = a[0];
	y = a[1];
	a[0] = 0.99619469809*x + 0.08715574274*y;
	a[1] = 0.99619469809*y - 0.08715574274*x;
}

void rotaciona_10(double *a) {
	double x, y;
	x = a[0];
	y = a[1];
	a[0] = 0.99619469809*x - 0.08715574274*y;
	a[1] = 0.99619469809*y + 0.08715574274*x;
}
