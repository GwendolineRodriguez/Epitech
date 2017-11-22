##
## Makefile for Makefile in /home/gwendoline/rendu/Piscine_Synthese
##
## Made by 
## Login   <gwendoline@epitech.net>
##
## Started on  Mon Jun 15 11:31:08 2015 
## Last update Thu Jun 18 12:38:20 2015 
##

SRC	=	./lib/base.c \
		./lib/strbase.c \
		./firstparser/parser.c \
		./firstparser/check_data.c \
		./firstparser/display.c \
		./firstparser/init_param.c \
		./firstparser/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	SBMLparser

all:		$(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re:		fclean all
