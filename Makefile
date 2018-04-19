##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Made by developers
##

SRC	=	$(wildcard src/*.c)

CFLAGS	+=	-Wextra -Wall -g3 #-Werror

CFLAGS	+=	-I./include/

OBJ	=	$(SRC:.c=.o)

NAME	=	tree

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
