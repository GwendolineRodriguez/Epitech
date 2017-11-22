##
## Makefile for FASTAtools in /home/gwendoline/rendu/Piscine_Synthese/FASTAtools
##
## Made by 
## Login   <gwendoline@epitech.net>
##
## Started on  Wed Jun 24 11:08:02 2015 
## Last update Fri Jun 26 01:19:33 2015 
##

NAME    =       FASTAtools

SRC     =       main.c \
                ./lib/base.c \
                ./lib/strbase.c \
                ./lib/my_strtowordtab.c \
                ./lib/put_revstr.c \
		./lib/sort_tab.c \
		./lib/get_char_comp.c \
                ./options/init_param.c \
                ./options/display.c \
                ./options/k_mer.c \
		./options/align.c

CC	=	cc

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
	@rm -rf $(OBJ)
	@echo -e "$(PROM_2)"

fclean:		clean
	@rm -rf $(NAME)
	@echo -e "$(PROM_3)"

re:		fclean all
