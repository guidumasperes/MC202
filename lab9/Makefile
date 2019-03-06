NAME = lab9
CC = gcc
CCFLAGS = -g -O0 -ansi -pedantic -Wall
OBJ = HashAberto.o HashLista.o

all: $(NAME)

$(NAME): $(NAME).c $(OBJ)
	$(CC) -o $(NAME) $(NAME).c $(OBJ) $(CCFLAGS)

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CCFLAGS)
