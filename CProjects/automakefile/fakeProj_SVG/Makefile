NAME	=        fakeProj

SRC	=	 main.c calcul.c

OBJ	=	$(SRC:.c=.o)

COMP	=	 clang

RM	=	 rm -f

LIBS	=	 libs

all:	$(NAME)

$(NAME):	$(OBJ)
	$(COMP) $(NAME) $(OBJ) $(LIBS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

archive:	tar $(ZIPFLAGS) $(ZIP) *
