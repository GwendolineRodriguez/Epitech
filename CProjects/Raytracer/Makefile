## Makefile for Makefile in /home/rodrig_1/rendu/Minilibx-TP
##
## Made by gwendoline rodriguez
## Login   <rodrig_1@epitech.net>
##
## Started on  Wed Nov 19 10:09:20 2014 gwendoline rodriguez
## Last update Mon Nov 13 16:03:33 2017 Gwendoline Rodriguez
##

CFLAGS		+=      -Wextra -Wall -Werror
CFLAGS		+=      -pedantic -ansi

SRC		=	main.c \
			graph.c \
			volumes.c \
			effect.c

OBJ		=	$(SRC:.c=.o)

NAME		=	raytracer

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my/
		cc $(OBJ) -o $(NAME) -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

clean:
	make clean -C ./lib/my/
	rm -rf $(OBJ) $(OBJLIB)

fclean:	clean
	make fclean -C ./lib/my/
	rm -rf $(LIB)

re:	fclean all
	make re -C ./lib/my/
