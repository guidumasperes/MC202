all: lab3

lab3: lista.o lab3.c
	gcc -O3 -ansi -pedantic -Wall lista.o -lm lab3.c -o lab3
	
lista.o: lista.h lista.c
	gcc -O3 -ansi -pedantic -Wall -c lista.c -o lista.o
