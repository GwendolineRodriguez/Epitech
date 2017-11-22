/*
** my_strstr.c for my_strstr in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 17:59:10 2014 gwendoline rodriguez
** Last update Tue Nov 18 19:38:49 2014 gwendoline rodriguez
*/

#include <stdlib.h>

char	*my_strstr(char *str, char *to_find)
{
  int   i;
  int	n;

  i = 0;
  n = 0;
  while (str[i])
    {
      if (str[i] == to_find[n])
	n = n + 1;
      else
	n = 0;
      if (!to_find[n])
	{
	  i = i - (n - 1);
	  return (str + 1);
	}
      i = i + 1;
    }
  return (NULL);
}
