all: lab1

lab1: Vetor.o lab1.c
	gcc -O3 -ansi -pedantic -Wall Vetor.o -lm lab1.c -o lab1
	
Vetor.o: Vetor.h Vetor.c
	gcc -c Vetor.c -o Vetor.o

