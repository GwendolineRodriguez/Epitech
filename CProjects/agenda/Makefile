##
## Makefile for Makefile in /home/gwendoline/rendu/Piscine_Synthese/agenda
##
## Made by Gwendoline Rodriguez
## Login   <gwendoline@epitech.net>
##
## Started on  Mon Jun 29 11:57:18 2015 Gwendoline Rodriguez
## Last update Wed Jul  1 17:44:28 2015 Gwendoline Rodriguez
##

NAME		=	agenda

SRC		=	main.c \
			./lib/init_param.c \
			./lib/base.c \
			./lib/strbase.c \
			./lib/my_strtowordtab.c \
			./lib/tools.c \
			./lib/my_revlist.c \
			./display/display_agenda.c \
			./display/setup_agenda.c \
			./display/get_list.c \
			./display/update_list.c \
			./display/update_meeting.c

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

