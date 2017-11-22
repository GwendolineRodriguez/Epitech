##
## Makefile for Makefile in /home/gwendoline/rendu/Prgelm/colles/master_mind/gwen
##
## Made by rodrig_1
## Login   <gwendoline@epitech.net>
##
## Started on  Thu May 21 14:37:39 2015 
## Last update Thu May 21 14:40:18 2015 
##

SRC	=	my_putnbr.c \
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_mastermind

all:		$(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re:		fclean all
