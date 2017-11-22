COLOR_E = \033[0m

COLOR_B = \033[32m

COLOR_C = \033[31m

PROM_1  = $(COLOR_B)[Compilation succeeded]$(COLOR_E)

PROM_2  = $(COLOR_B)[Sources Objects Removed]$(COLOR_E)

PROM_3  = $(COLOR_B)[Sources Names Removed]$(COLOR_E)

PROM_4  = $(COLOR_C)[Compilation failed]$(COLOR_E)

CFLAGS += -Wextra

NAME		=        fakeProj

SRC		=	 main.c calcul.c

OBJ		=	$(SRC:.c=.o)

COMP		=	 gcc

RM		=	 rm -f

ZIP		=	 tarball.tar

ZIPFLAGS	=	 -cvvf

UNZIP		=	 tar

UNZIPFLAGS	=	 -xv

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(COMP) $(OBJ) -o $(NAME) $(LDFLAGS) && echo -e "$(PROM_1)" || (echo -e "$(PROM_4)" >&2)1> /dev/null

clean:
	@$(RM) $(OBJ)
	@echo -e "$(PROM_2)"

fclean:		clean
	@$(RM) $(NAME)
	@echo -e "$(PROM_3)"

re:			fclean all

archive:		$(UNZIP) $(ZIPFLAGS) $(ZIP) * && echo "Fichier $(ZIP) généré.\n"
