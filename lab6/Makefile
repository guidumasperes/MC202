all: lab6

lab6: Heap.o lab6.c
	gcc -O3 -ansi -pedantic -Wall Heap.o lab6.c -o lab6
	
Heap.o: Heap.h Heap.c
	gcc -O3 -ansi -pedantic -Wall -c Heap.c -o Heap.o
