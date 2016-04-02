all:
	gcc -c -g main.c fisica.c objetos.c vetor.c
	gcc main.o fisica.o objetos.o vetor.o -g -lm -o game
clean:
	rm *.o game
run:
	./game
