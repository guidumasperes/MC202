all: lab2

lab2: Lista.o lab2.c
	gcc -O3 -ansi -pedantic -Wall -lm Lista.o lab2.c -o lab2
	
Lista.o: Lista.h Lista.c
	gcc -O3 -ansi -pedantic -Wall -lm -c Lista.c -o Lista.o
