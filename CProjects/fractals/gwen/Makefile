##
## Makefile for Makefile in /home/rodrig_1/fractals/gwen
##
## Made by gwendoline rodriguez
## Login   <rodrig_1@epitech.net>
##
## Started on  Tue Apr 28 11:33:39 2015 gwendoline rodriguez
## Last update Tue Apr 28 10:19:56 2015 Loik Fauré-Berlinguette
##

SRC	=	main.c \
		my_putchar.c \
		parsing.c \
		my_putnbr.c \
		tools.c

OBJ	=	$(SRC:.c=.o)

NAME	=	fractals

all:		$(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re:		fclean all
