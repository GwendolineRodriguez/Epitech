/*
** my_revstr.c for my_revstr in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 18:38:42 2014 gwendoline rodriguez
** Last update Sun Mar  8 23:43:34 2015 gwendoline rodriguez
*/

#include "my.h"

char    *my_revstr(char *str)
{
  int   i;
  int	j;
  char	c;

  i = 0;
  j = my_strlen(str) - 1;
  while (i < j)
    {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
      i = i + 1;
      j = j - 1;
    }
  return (str);
}
