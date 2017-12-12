##
## Makefile for Makefile in /home/RODRIG_1/rendu/Piscine_C_J11/lib/my
## 
## Made by rodriguez gwendoline
## Login   <RODRIG_1@epitech.net>
## 
## Started on  Mon Oct 20 09:56:56 2014 rodriguez gwendoline
## Last update Tue Oct 28 14:01:58 2014 rodriguez gwendoline
##

NAME    =	do-op

SRC	=	do-op.c \
		operator.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	cc $(OBJ) -o $(NAME) -lmy -L ./../lib
clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
