CFLAGS=-Wall -g -lm
LFLAGS = -lallegro -lallegro_image

all: main.o fisica.o objetos.o vetor.o janela.o
	gcc main.o fisica.o objetos.o vetor.o janela.o -o game $(LFLAGS) ${CFLAGS}
clean:
	rm *.o game
run:
	./game 0.017 <1.in
