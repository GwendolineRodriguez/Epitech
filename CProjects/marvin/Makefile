##
## Makefile for make in /home/kerebel/bin
## 
## Made by kerebe_p
## Login   <kerebe_p@epitech.eu>
## 
## Started on  Fri Dec  5 05:43:19 2014 kerebe_p
## Last update Fri Dec  5 05:43:19 2014 kerebe_p
##

SRC	= check.c \
	  main.c \
	  my_putchar.c \
	  my_strcmp.c \
	  my_strcpy.c \
	  my_strlen.c \
	  tool.c \
	  errors.c \
	  errors2.c \
	  type_str.c \

OBJ	= $(SRC:.c=.o)

NAME	= marvin

RM	= rm -f

CFLAGS += -W -Wall -ansi -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean
