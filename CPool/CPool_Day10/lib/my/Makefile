##
## Makefile for Makefile in /home/RODRIG_1/rendu/Piscine_C_J11/lib/my
## 
## Made by rodriguez gwendoline
## Login   <RODRIG_1@epitech.net>
## 
## Started on  Mon Oct 20 09:56:56 2014 rodriguez gwendoline
## Last update Tue Oct 21 19:47:10 2014 rodriguez gwendoline
##

SRC	= my_showstr.c \
	  my_strlcat.c \
	  my_find_prime_sup.c \
	  my_sort_int_tab.c \
	  my_strlen.c \
	  my_getnbr.c \
	  my_square_root.c \
	  my_strlowcase.c \
	  my_isneg.c \
	  my_strcapitalize.c \
	  my_strncat.c \
	  my_is_prime.c \
          my_strcat.c \
	  my_strncmp.c \
	  my_power_rec.c \
	  my_strcmp.c \
	  my_strncpy.c \
	  my_strcpy.c \
	  my_strstr.c \
	  my_putchar.c \
	  my_str_isalpha.c \
	  my_str_to_wordtab.c \
	  my_put_nbr.c \
	  my_str_islower.c \
	  my_strupcase.c \
	  my_putstr.c \
	  my_str_isnum.c \
          my_swap.c \
	  my_revstr.c \
	  my_str_isprintable.c \
	  my_showmem.c \
	  my_str_isupper.c

NAME	= libmy.a

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	mv $(NAME) ./../
	cp my.h ./../../include/

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
