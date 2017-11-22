/*
** encrypt.c for encrypt in /home/leboeu_q/sem2/rush1
**
** Made by Quentin Leboeuf
** Login   <leboeu_q@epitech.net>
**
** Started on  Fri Feb 27 23:34:11 2015 Quentin Leboeuf
** Last update Thu Mar  5 18:35:04 2015 gwendoline rodriguez
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "my.h"

long			 my_strlen_long(char *str)
{
  long			i;

  i = 0;
  while (str[i])
    {
      i = i + 1;
    }
  return (i);
}

char			*convert_base(char *nbr, char *base_from,
				      char *base_to)
{
  long			i;
  long			nb;
  char			*res;

  i = 0;
  if ((res = malloc(sizeof(char) * 300)) == NULL)
    exit(0);
  nb = my_getnbr_base(nbr, base_from);
  while (nb > 0)
    {
      res[i] = base_to[nb % my_strlen_long(base_to)];
      nb = nb / my_strlen_long(base_to);
      i = i + 1;
    }
  res[i] = '\0';
  while (i != 64)
    res[i++] = '0';
  res[i] = '\0';
  res = my_revstr(res);
  return (res);
}

char			**tab_text(int *j, int *i, char *av, char **oct)
{
  *j = 0;
  while (*j < 8)
    {
      if ((av[*i] & 1) == 1)
	oct[*i] = strcat(oct[*i], "1\0");
      else
	oct[*i] = strcat(oct[*i], "0\0");
      (*j)++;
      av[*i] >>= 1;
    }
  oct[*i][8] = '\0';
  (*i)++;
  return (oct);
}
