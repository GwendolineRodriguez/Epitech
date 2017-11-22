##
## Makefile for Makefile in /home/rodrig_1/rendu/Prgelm/elcrypt
##
## Made by gwendoline rodriguez
## Login   <rodrig_1@epitech.net>
##
## Started on  Fri Feb 27 20:44:22 2015 gwendoline rodriguez
## Last update Sun Apr 12 23:15:48 2015 gwendoline rodriguez
##

SRC		=	asm/assembler/main.c \
			asm/assembler/my_put_str_tofile.c \
			asm/assembler/op.c \
			asm/assembler/get_file.c \
			asm/assembler/put_params_inhexa.c \
			asm/assembler/corheader.c \
			asm/assembler/get_clean_line.c \
			asm/assembler/check_line.c \
			asm/manage_error/analyse_data.c \
			asm/manage_error/analyse_header.c \
			asm/manage_error/instruction.c

CFLAGS		+=	-Wextra -Wall -Werror
CFLAGS		+=	-pedantic -ansi

SRCLIB           =      ./lib/my/my_find_prime_sup.c \
                        ./lib/my/my_getnbr.c \
                        ./lib/my/my_getnbr_base.c \
                        ./lib/my/my_isneg.c \
                        ./lib/my/my_is_prime.c \
                        ./lib/my/my_power_rec.c \
                        ./lib/my/my_printf.c \
                        ./lib/my/my_putchar.c \
                        ./lib/my/my_putnbr.c \
                        ./lib/my/my_putnbr_base.c \
                        ./lib/my/my_putstr.c \
                        ./lib/my/my_revstr.c \
                        ./lib/my/my_showmem.c \
                        ./lib/my/my_showstr.c \
                        ./lib/my/my_sort_int_tab.c \
                        ./lib/my/my_sort_wordtab.c \
                        ./lib/my/my_square_root.c \
                        ./lib/my/my_strcapitalize.c \
                        ./lib/my/my_strcat.c \
                        ./lib/my/my_strcmp.c \
                        ./lib/my/my_strcpy.c \
                        ./lib/my/my_strdup.c \
                        ./lib/my/my_str_isalpha.c \
                        ./lib/my/my_str_islower.c \
                        ./lib/my/my_str_isnum.c \
                        ./lib/my/my_str_isprintable.c \
                        ./lib/my/my_str_isupper.c \
                        ./lib/my/my_strlcat.c \
                        ./lib/my/my_strlen.c \
			./lib/my/my_strlen_tab.c \
                        ./lib/my/my_strlowcase.c \
                        ./lib/my/my_strncat.c \
                        ./lib/my/my_strncmp.c \
                        ./lib/my/my_strncpy.c \
                        ./lib/my/my_strstr.c \
                        ./lib/my/my_str_to_wordtab.c \
                        ./lib/my/my_strupcase.c \
                        ./lib/my/my_swap.c \
                        ./lib/my/get_next_line.c

OBJ		=	$(SRC:.c=.o)

OBJLIB          =       $(SRCLIB:.c=.o)

NAME		=	./asm/asm

LIB		=	libmy.a

all:		$(LIB) $(NAME)

$(LIB):                 $(OBJLIB)
	ar rc $(LIB) $(OBJLIB)
	ranlib $(LIB)

$(NAME):		$(OBJ)
	cc $(OBJ) -o $(NAME) -L ./ -lmy

clean:
	rm -rf $(OBJ) $(OBJLIB)

fclean:			clean
	rm -rf $(NAME) $(LIB)

re:			fclean all
