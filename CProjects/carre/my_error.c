/*
** my_error.c for my_error in /home/rodrig_1/rendu/Prgelm/colles/carre/lolo
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue May  5 11:04:56 2015 gwendoline rodriguez
** Last update Tue May  5 11:07:58 2015 gwendoline rodriguez
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_error(char *str)
{
  write(2, str, my_strlen(str));
  exit(0);
}
