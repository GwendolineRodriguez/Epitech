##
## Makefile for Makefile in /home/rodrig_1/rendu/Prgelm/colles/carre
##
## Made by gwendoline rodriguez
## Login   <rodrig_1@epitech.net>
##
## Started on  Tue May  5 09:39:42 2015 gwendoline rodriguez
## Last update Tue May  5 12:22:52 2015 gwendoline rodriguez
##

SRC	=	get_square.c \
		my_putchar.c \
		my_putstr.c \
		my_error.c \
		main.c \
		my_putnbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	carre

all:		$(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re:		fclean all
