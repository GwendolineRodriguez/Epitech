/*
** tools.c for tools in /home/rodrig_1/fractals/gwen
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Apr 28 11:52:30 2015 gwendoline rodriguez
** Last update Tue Apr 28 12:01:53 2015 gwendoline rodriguez
*/

#include <stdlib.h>

int             my_getnbr(char *str)
{
  int           nb;
  int           i;

  nb = 0;
  i = 0;
  nb = str[i] - 48;
  return (nb);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

void            my_error(char *str)
{
  write(2, str, my_strlen(str));
  exit(0);
}

