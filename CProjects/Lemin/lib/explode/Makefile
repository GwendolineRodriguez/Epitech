##
## Makefile for  in /home/rouge_b/rendu/Prog_elem/CPE_2014_lemin/lib/explode
## 
## Made by Bastien Rougé
## Login   <rouge_b@epitech.net>
## 
## Started on  Mon Apr 27 17:41:29 2015 Bastien Rougé
## Last update Mon Apr 27 19:37:28 2015 Bastien Rougé
##

SRCS	= explode.c \
	functions_explode.c

OBJS	= $(SRCS:.c=.o)

NAME = libexp.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	cp -f $(NAME) ../$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f ../$(NAME) $(NAME)

re: fclean all
