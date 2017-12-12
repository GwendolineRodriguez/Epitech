NAME		=	menger

SRC		=	main.c \
			menger.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

RM		=	rm -f

TARBALL		=	tarball.tar

CFLAGS          +=      -ansi -pedantic -Wextra -Werror -Wall -I.

SUCCESS         =       \033[32;1m[Compilation succeeded]\033[0m

OBJRM           =       \033[32;1m[Sources Objects Removed]\033[0m

NAMERM          =       \033[32;1m[Sources Names Removed]\033[0m

FAIL            =       \033[31;1m[Compilation failed]\033[0m

all:			$(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

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

