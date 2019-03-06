all: lab4

lab4: Pilha.o lab4.c
	gcc -g -O0 -ansi -pedantic -Wall -lm Pilha.o lab4.c -o lab4
	
Pilha.o: Pilha.h Pilha.c
	gcc -g -O0 -ansi -pedantic -Wall -lm -c Pilha.c -o Pilha.o
