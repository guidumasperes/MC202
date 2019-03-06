all: lab7

lab7: Tree.o lab7.c
	gcc -O3 -ansi -pedantic -Wall Tree.o lab7.c -o lab7

Tree.o: Tree.h Tree.c
	gcc -O3 -ansi -pedantic -Wall -c Tree.c -o Tree.o
