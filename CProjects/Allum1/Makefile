##
## Makefile for Allum1 in /home/rodrig_1/rendu/Prgelm/Allum1
##
## Made by gwendoline rodriguez
## Login   <rodrig_1@epitech.net>
##
## Started on  Mon Feb  9 14:24:36 2015 gwendoline rodriguez
## Last update Sat Feb 21 11:26:31 2015 gwendoline rodriguez
##

NAME		=	allum1

SRC		=	allum1.c \
			game.c

OBJ		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
	cc $(OBJ) -o $(NAME) -L ./lib/my -lmy

clean:
	rm -rf $(NAME)

fclean:			clean
	rm -rf $(OBJ)

re:			fclean all
