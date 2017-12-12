##
## Makefile for Makefile in /home/maure_d/rendu/Piscine_C_colles-Semaine_03
## 
## Made by Damien MAURE
## Login   <maure_d@epitech.net>
## 
## Started on  Sat Oct 25 18:20:17 2014 Damien MAURE
## Last update Sat Oct 25 20:56:01 2014 Damien MAURE
##

NAME	=	colle3

SRC	=	colle3.c \
		main.c \
		my_strlen_colle.c \
		count_height.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	cc $(OBJ) -o $(NAME) -lmy -L ./lib/my

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re:		fclean all
