##
## Makefile for my_mixword in /home/duclos_r/Tek-1/Colle/my_mixword
## 
## Made by Rémi Duclos
## Login   <duclos_r@epitech.net>
## 
## Started on  Wed Jun 10 09:16:46 2015 Rémi Duclos
## Last update Wed Jun 10 15:08:11 2015 
##

NAME	= my_mixword

SRC	= my_mixword.c \
	  fill_grid.c \
	  str_to_wordtab.c \
	  tools.c \
	  tools2.c \
	  check_ifword.c \
	  check_revword.c \
	  reader.c \
	  parsing.c

OBJ	= $(SRC:.c=.o)

all:	$(OBJ)
	cc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
