##
## Makefile for  in /home/daniel_b/Rendu/CPE_2014_lemin
## 
## Made by DANIEL Erwan
## Login   <daniel_b@epitech.net>
## 
## Started on  Fri Apr 24 16:19:06 2015 DANIEL Erwan
## Last update Tue Apr 28 18:01:13 2015 DANIEL Erwan
##

NAME	=	lemin

SRCS	=	main.c \
		read_map.c \
		load_map.c \
		load_map2.c \
		algo_erwan.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-g

LDFLAGS	=	-L/usr/lib64 -L./lib/minilibx/ -lmlx -L/usr/lib64/X11 -lXext -lX11 -L./lib/ -lm -lmy -lexp

CC	=	cc

RM	=	rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib/my/
	make -C lib/minilibx/
	make -C lib/explode/
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	make -C lib/my/ clean
	make -C lib/minilibx/ clean
	make -C lib/explode/ clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clear fclean re
