##
## Makefile for Makefile in /home/gwendoline/rendu/Prgelm/colles/pretty_calendar/gwen
##
## Made by 
## Login   <gwendoline@epitech.net>
##
## Started on  Tue Jun  9 21:11:38 2015 
## Last update Wed Jun 10 00:32:12 2015 
##

SRC	=	get_alpha_nbr.c \
		get_alpha_month.c \
		tools.c \
		list.c \
		parsing.c \
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	prettycalendar

all:		$(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re:		fclean all
