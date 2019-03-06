all: lab5

lab5: Deque.o lab5.c
	gcc -O3 -ansi -pedantic -Wall Deque.o lab5.c -o lab5
	
Deque.o: Deque.h Deque.c
	gcc -O3 -ansi -pedantic -Wall -c Deque.c -o Deque.o
