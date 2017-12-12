##
## Makefile for Makefile in /home/RODRIG_1/rendu/Piscine_C_J13/cat
## 
## Made by rodriguez gwendoline
## Login   <RODRIG_1@epitech.net>
## 
## Started on  Wed Oct 22 10:49:55 2014 rodriguez gwendoline
## Last update Wed Oct 22 14:31:23 2014 rodriguez gwendoline
##

CFLAGS += -Wextra -Wall -Werror
CFLAGS += -ansi -pedantic
CFLAGS += -I.

SRC     = cat.c

NAME    = cat

all:    $(NAME)

$(NAME):        $(SRC)
	cc -o $(NAME) $(SRC) -lmy -L ./../lib

clean:
	rm -rf $(NAME)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
