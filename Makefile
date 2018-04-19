##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Made by developers
##

SRC	=	src/arguments.c	\
		src/elements.c		\
		src/elements_utils.c	\
		src/my_put_nbr.c	\
		src/tree.c		\
		src/utils2.c		\
		src/utils.c

CFLAGS	+=	-Wextra -Wall

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
