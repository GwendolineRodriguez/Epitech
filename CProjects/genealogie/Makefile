##
## Makefile for Makefile in /home/gwendoline/rendu/Piscine_Synthese/genealogie
##
## Made by Gwendoline Rodriguez
## Login   <gwendoline@epitech.net>
##
## Started on  Thu Jul  2 09:17:38 2015 Gwendoline Rodriguez
## Last update Sat Jul  4 18:21:46 2015 Gwendoline Rodriguez
##

NAME		=	genealogie

SRC		=	main.c \
			build/display_family.c \
			build/init_param.c \
			build/genealogy.c \
			info/file_info.c \
			info/print_info.c \
			build/tools.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

RM		=	rm -f

LIBS		=

TARBALL		=	tarball.tar

CFLAGS += -ansi -pedantic -Wextra -Werror -Wall -I.

SUCCESS  = \033[32;1m[Compilation succeeded]\033[0m

OBJRM  = \033[32;1m[Sources Objects Removed]\033[0m

NAMERM  = \033[32;1m[Sources Names Removed]\033[0m

FAIL  = \033[31;1m[Compilation failed]\033[0m

all:			$(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@ -g3

$(NAME):		$(OBJ)
	@$(CC) $(OBJ) -o $(NAME) && echo -e "$(SUCCESS)" || (echo -e "$(FAIL)" >&2)1> /dev/null

clean:
	@$(RM) $(OBJ)
	@$(RM) *~
	@$(RM) \#*\#
	@echo -e "$(OBJRM)"

fclean:			clean
	@$(RM) $(NAME)
	@echo -e "$(NAMERM)"

re:			fclean all

zip:			tar cvf $(TARBALL) * && echo "Fichier $(TARBALL) généré.\n"
