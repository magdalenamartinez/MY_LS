##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## funcion which
##

NAME	=	my_ls

LIB	=	-L lib/my/ -lmy

INCLUDE	=	-I ./include/

SRC	= 	src/main.c	\
		src/my_ls.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): 	$(OBJ)
		make -C ./lib/my
		gcc -g $(OBJ) -o $(NAME) $(INCLUDE) $(LIB)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f libmy.a
	rm -f lib/my/libmy.a
	rm -f ./lib/my/*.o
	rm -f ./src/*.o

re: fclean all

library: fclean
	make -C lib/my/ re

exec: re
	./$(NAME)
