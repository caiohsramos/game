CFLAGS=-Wall -g -lm
LFLAGS = -lallegro -lallegro_image

all: main.o fisica.o objetos.o vetor.o janela.o
	gcc main.o fisica.o objetos.o vetor.o janela.o -o game $(LFLAGS) ${CFLAGS}
clean:
	rm *.o game
run1:
	./game 0.017 <1.in
run2:
	./game 0.017 <2.in
