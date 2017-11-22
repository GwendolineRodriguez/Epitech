/*
** convert_base.c for convert_base in /home/gwendoline/rendu/Piscine_Synthese/palindrome
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jun 26 16:09:26 2015 
** Last update Fri Jun 26 18:55:17 2015 
*/

#include "header.h"

char	*my_revstr(char *str)
{
  int	i;
  int	j;
  char	c;

  i = -1;
  j = my_strlen(str) - 1;
  while (++i < j)
    {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
      j--;
    }
  return (str);
}

char	*convert_base(int nb, char *base_to)
{
  int	i;
  char	*res;

  i = 0;
  if ((res = malloc(sizeof(char) * 50)) == NULL)
    put_error("ERROR on malloc\n");
  /* nb = my_getnbr_base(nbr, base_from); */
  while (nb > 0)
    {
      res[i] = base_to[nb % my_strlen(base_to)];
      nb = nb / my_strlen(base_to);
      i++;
    }
  res[i] = '\0';
  res = my_revstr(res);
  return (res);
}
