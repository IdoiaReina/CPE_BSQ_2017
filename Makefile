##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

SRCDIR	=	src/

SRC	=	find_a_square.c		\
		main.c			\
		malloc_free.c		\
		my_putstr.c		\

OBJ	=	$(addprefix $(SRCDIR), $(SRC:.c=.o))

CFLAGS	=	-I./include

CFLAGS	+=	-Wall -Wextra

NAME	=	bsq

all:		$(NAME) clean

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
