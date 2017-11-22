##
## Makefile for Makefile in /home/gwendoline/rendu/Piscine_Synthese/palindrome
##
## Made by 
## Login   <gwendoline@epitech.net>
##
## Started on  Fri Jun 26 12:14:38 2015 
## Last update Sat Jun 27 12:39:57 2015 Gwendoline Rodriguez
##

NAME    =       palindrome

SRC     =       main.c \
		init_param.c \
		calc.c \
		option.c \
		./lib/base.c \
                ./lib/strbase.c \
                ./lib/my_strtowordtab.c \
		./lib/convert_base.c

CC	=	cc

RM	=	rm -f

COLOR_E = \033[0m

COLOR_B = \033[32;1m

COLOR_C = \033[31;1m

PROM_1  = $(COLOR_B)[Compilation succeeded]$(COLOR_E)

PROM_2  = $(COLOR_B)[Sources Objects Removed]$(COLOR_E)

PROM_3  = $(COLOR_B)[Sources Names Removed]$(COLOR_E)

PROM_4  = $(COLOR_C)[Compilation failed]$(COLOR_E)

CFLAGS  += -ansi -pedantic -Wextra -Werror -Wall -I.

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) && echo -e "$(PROM_1)" || (echo -e "$(PROM_4)" >&2)1> /dev/null

clean:
	@$(RM) $(OBJ)
	@$(RM) *~
	@$(RM) \#*\#
	@echo -e "$(PROM_2)"

fclean:		clean
	@$(RM) $(NAME)
	@echo -e "$(PROM_3)"

re:		fclean all
