all:
	gcc -c -g main.c fisica.c objetos.c -Wall
	gcc main.o fisica.o objetos.o -Wall -g -lm -o game
clean:
	rm *.o game
run:
	./game
