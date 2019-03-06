all: lab8

lab8: Arvore.o Superarvore.o lab8.c
	gcc -g -O0 -ansi -pedantic -Wall Arvore.o Superarvore.o lab8.c -o lab8
		
Superarvore.o: Arvore.o Superarvore.h Superarvore.c
	gcc -g -O0 -ansi -pedantic -Wall -c Arvore.o Superarvore.c -o Superarvore.o
	
Arvore.o: Arvore.h Arvore.c
	gcc -g -O0 -ansi -pedantic -Wall -c Arvore.c -o Arvore.o
