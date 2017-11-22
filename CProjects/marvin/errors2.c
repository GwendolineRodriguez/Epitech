/*
** errors2.c for errors2 in /home/rodrig_1/rendu/Prgelm/marvin
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Sun Jan  4 17:56:58 2015 gwendoline rodriguez
** Last update Sun Jan  4 18:27:35 2015 gwendoline rodriguez
*/

#include "include/my.h"

int	check_index(char c)
{
  int	i;
  char	index[20];

  i = 0;
  my_strcpy(index, "%!?<>+/\\-#$&~.@=:^");
  while (index[i] != '\0')
    {
      if (index[i] == c)
	return (-1);
      i = i + 1;
    }
  return (0);
}

int	check_for(char *str)
{
  int	i;
  int	e;

  i = 0;
  e = 0;
  while (str[i] != '\0')
    {
      e = check_index(str[i]);
      if (e == -1)
	{
	  printf("Forbidden character '%c' !\n", str[i]);
	  return (-1);
	}
      i = i + 1;
    }
  return (0);
}
