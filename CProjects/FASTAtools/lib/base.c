/*
** tools.c for tools in /home/gwendoline/rendu/Piscine_Synthese
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jun 15 11:34:09 2015 
** Last update Wed Jun 24 17:29:49 2015 
*/

#include "header.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void		put_error(char *str)
{
  write(2, str, my_strlen(str));
  exit(1);
}

void		my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + 48);
}
