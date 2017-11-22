##
## makefile for makefile in /home/h4ck3r31/rendu/Piscine_C_J11/lib/my
## 
## Made by Bastien ROUGE
## Login   <h4ck3r31@epitech.net>
## 
## Started on  Mon Oct 20 09:40:35 2014 Bastien ROUGE
## Last update Tue Apr  7 16:43:39 2015 DANIEL Erwan
##

SRCS	= my_malloc.c \
	my_strsize.c \
	my_printf.c \
	my_putstr.c \
	my_strcpy.c \
	my_revstr.c \
	my_str_isalpha.c \
	my_strncmp.c \
	my_getnbr.c \
	my_getnbr_base.c \
	my_str_islower.c \
	my_strncpy.c \
	my_showstr.c \
	my_str_isnum.c \
	my_strstr.c \
	my_isneg.c \
	my_str_isprintable.c \
	my_strupcase.c \
	my_str_isupper.c \
	my_swap.c \
	my_power_rec.c \
	my_strcapitalize.c \
	my_putchar.c \
	my_strcat.c \
	my_strlen.c \
	my_put_nbr.c \
	my_putnbr_base.c \
	my_strcmp.c \
	my_strlowcase.c \
	my_parse_str.c \
	my_addstrstr.c \
	my_free_double.c \
	my_strdup.c \
	str_not_empty.c

OBJS	= $(SRCS:.c=.o)

NAME	= libmy.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	cp -f $(NAME) ../$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f ../$(NAME) $(NAME)

re: clean all
