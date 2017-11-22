/*
** my_putstr.c for my_putstr in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 18:38:14 2014 gwendoline rodriguez
** Last update Sun Mar  8 23:42:14 2015 gwendoline rodriguez
*/

#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (i);
}
