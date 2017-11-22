##
## Makefile for Makefile in /home/rodrig_1/rendu/101pong
##
## Made by gwendoline rodriguez
## Login   <rodrig_1@epitech.net>
##
## Started on  Mon Nov 10 17:24:21 2014 gwendoline rodriguez
## Last update Tue Nov 11 14:46:53 2014 gwendoline rodriguez
##

NAME    =       101pong

SRC     =       101pong.c \
                my_putchar.c \
		my_putstr.c \
		my_getnbr.c \
		my_put_nbr.c

OBJ     =       $(SRC:.c=.o)

all:            $(NAME)

$(NAME):        $(OBJ)
	cc $(OBJ) -o $(NAME) -lm
clean:
	rm -rf $(OBJ)

fclean:         clean
	rm -rf $(NAME)

re:             fclean all

.PHONY:         all clean fclean re
