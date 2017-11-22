##
## Makefile for Makefile in /home/gwendoline/rendu/Piscine_Synthese
##
## Made by Gwendoline Rdoriguez
## Login   <gwendoline@epitech.net>
##
## Started on  Mon Jun 15 11:31:08 2015 
## Last update Sat Jun 20 21:15:27 2015 
##

FLAGS	+=	-Wextra -Wall -Werror
CFLAGS  +=	-ansi -pedantic
CFLAGS  +=	-I.

SRC	=	./lib/base.c \
		./lib/strbase.c \
		./get_list/init_param.c \
		./get_list/test_args.c \
		./get_list/list.c \
		./get_list/get_list.c \
		./get_list/search_res.c \
		./lib/my_strtowordtab.c \
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	projTester

all:		$(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re:		fclean all
