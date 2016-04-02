#ifndef _VETOR_H_
#define _VETOR_H_

//'a' = 'b' + 'c'
void soma_vet(double *a, double *b, double *c);

//'a' = 'b' - 'c'
void subt_vet(double *a, double *b, double *c);

//'a' = 'b'(escalar) * 'c'(vetor)
void produto_esc(double *a, double b, double *c);

//'a' = 'b'(escalar) + 'c'(vetor)
void soma_esc(double *a, double b, double *c);

//magnitude do vetor 'a'
double magnitude(double *a);

//produto vetorial de 'a' com 'b'
double dot(double *a, double *b);

//distancia de 'a' ate 'b'
double distancia(double *a, double *b);

//direcao de 'a' retornada no 'b'
void direcao(double *a, double *b);


#endif
