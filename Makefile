CC = gcc
CFLAGS = -v -Wall -Werror -Wextra -pedantic -std=gnu89
SRC = *.c
NAME = hsh

all: $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

oclean:
	rm $(OBJ)

 
