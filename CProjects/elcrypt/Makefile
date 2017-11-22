##
## Makefile for Makefile in /home/rodrig_1/rendu/Prgelm/elcrypt
##
## Made by gwendoline rodriguez
## Login   <rodrig_1@epitech.net>
##
## Started on  Fri Feb 27 20:44:22 2015 gwendoline rodriguez
## Last update Sun Mar  1 20:50:16 2015 gwendoline rodriguez
##

SRC	=	elcrypt.c \
		parsing.c \
		check_key.c \
		filemove.c \
		encrypt.c \
		feistel.c \
		convert_text.c \
		my_getnbr_base.c \
		my_revstr_unsigned.c \
		my_strlen_unsigned.c

CFLAGS	+=	-Wextra -Wall -Werror
CFLAGS	+=	-pedantic -ansi

OBJ	=	$(SRC:.c=.o)

NAME	=	elcrypt

all:		$(NAME)

$(NAME):	$(OBJ)
	cc $(OBJ) -o $(NAME) -L ./lib/my -lmy

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re:		fclean all
