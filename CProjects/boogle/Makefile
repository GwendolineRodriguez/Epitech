##
## Makefile for Makefile in /home/gwendoline/rendu/Prgelm/colles/boogle/gwen
##
## Made by 
## Login   <gwendoline@epitech.net>
##
## Started on  Fri Jun  5 16:19:17 2015 
## Last update Fri Jun  5 18:30:21 2015 
##

SRC	=	my_putchar.c \
		my_putstr.c \
		my_strlen.c \
		parsing.c \
		check_errors.c \
		my_strcmp.c \
		my_boogle.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_boogle

all:		$(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re:		fclean all

