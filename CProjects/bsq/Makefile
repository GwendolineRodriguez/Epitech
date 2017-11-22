##
## Makefile for Makefile in /home/RODRIG_1/rendu/Bistromathique
## 
## Made by rodriguez gwendoline
## Login   <RODRIG_1@epitech.net>
## 
## Started on  Tue Oct 28 14:35:58 2014 rodriguez gwendoline
## Last update Thu Jan 15 15:29:38 2015 gwendoline rodriguez
##

CFLAGS	+=	-Wextra -Wall -Werror
CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	-I.

NAME    =       bsq

SRC     =       bsq.c

OBJ     =       $(SRC:.c=.o)

all:            $(NAME)

$(NAME):        $(OBJ)
	cc $(OBJ) -o $(NAME) -L ./lib -lmy
clean:
	rm -rf $(OBJ)

fclean:         clean
	rm -rf $(NAME)

re:             fclean all

.PHONY:         all clean fclean re
