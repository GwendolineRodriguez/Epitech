/*
** my_revstr_unsigned.c for my_revstr_unsigned in /home/rodrig_1/rendu/Prgelm/elcrypt
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Sun Mar  1 18:46:27 2015 gwendoline rodriguez
** Last update Thu Mar  5 19:16:45 2015 gwendoline rodriguez
*/

#include "my.h"

unsigned char	*my_revstr_unsigned(unsigned char *str)
{
  int		i;
  int		j;
  unsigned char c;

  i = 0;
  j = my_strlen_unsigned(str) - 1;
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

