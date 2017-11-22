##
## Makefile for Makefile in /home/gwendoline/rendu/Piscine_Synthese
##
## Made by Gwendoline Rdoriguez
## Login   <gwendoline@epitech.net>
##
## Started on  Mon Jun 15 11:31:08 2015 
## Last update Tue Jun 23 18:49:21 2015 
##

COLOR_E = \033[0m

COLOR_B = \033[32m

COLOR_C = \033[31m

PROM_1  = $(COLOR_B)[Compilation succeeded]$(COLOR_E)

PROM_2  = $(COLOR_B)[Sources Objects Removed]$(COLOR_E)

PROM_3  = $(COLOR_B)[Sources Names Removed]$(COLOR_E)

PROM_4	= $(COLOR_C)[Compilation failed]$(COLOR_E)

CFLAGS  +=
LDFLAGS +=

LIBS	=

COMP	=

RM	=

SRC	=

OBJ	=	$(SRC:.c=.o)

NAME	=

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(COMP) $(OBJ) -o $(NAME) $(LDFLAGS) && echo -e "$(PROM_1)" || (echo -e "$(PROM_4)" >&2)1> /dev/null

clean:
	@$(RM) $(OBJ)
	@echo -e "$(PROM_2)"

fclean:		clean
	@$(RM) $(NAME)
	@echo -e "$(PROM_3)"

re:		fclean all
