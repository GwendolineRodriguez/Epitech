##
## Makefile for Makefile in /home/RODRIG_1/rendu/MUL_2014_fdf
## 
## Made by rodriguez gwendoline
## Login   <RODRIG_1@epitech.net>
## 
## Started on  Wed Oct 29 14:07:24 2014 rodriguez gwendoline
## Last update Sun Nov 30 00:09:01 2014 gwendoline rodriguez
##

NAME    =       102chiffrement

SRC     =       102chiffrement.c \
		my_matrice.c \
		convert_base.c \
		reverskey.c \
		count_word.c \
		uncrypt.c

OBJ     =       $(SRC:.c=.o)

all:            $(NAME)

$(NAME):        $(OBJ)
	cc $(OBJ) -o $(NAME) -L ./lib/my/ -lmy

clean:
	rm -rf $(OBJ)

fclean:         clean
	rm -rf $(NAME)

re:             fclean all

.PHONY:         all clean fclean re
