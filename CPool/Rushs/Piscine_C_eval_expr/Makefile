##
## Makefile for Makefile in /home/RODRIG_1/rendu/Piscine_C_eval_expr
## 
## Made by rodriguez gwendoline
## Login   <RODRIG_1@epitech.net>
## 
## Started on  Fri Oct 24 09:39:39 2014 rodriguez gwendoline
## Last update Wed Oct 29 11:46:52 2014 rodriguez gwendoline
##

NAME    =       eval_expr

SRC     =	eval_expr.c \
		operator.c

OBJ	=	$(SRC:.c=.o)

all:    	$(NAME)

$(NAME):	$(OBJ)
	cc $(OBJ) -o $(NAME) -lmy -L ./lib/my/

clean:
	rm -rf $(OBJ)

fclean:         clean
	rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
