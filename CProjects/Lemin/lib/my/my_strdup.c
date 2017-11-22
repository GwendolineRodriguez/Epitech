/*
** my_strdup.c for  in /home/daniel_b/Rendu/PSU_2014_minishell2
** 
** Made by DANIEL Erwan
** Login   <daniel_b@epitech.net>
** 
** Started on  Fri Mar  6 18:30:09 2015 DANIEL Erwan
** Last update Fri Mar  6 18:37:19 2015 DANIEL Erwan
*/

#include <stdlib.h>

char	*my_strdup(char *str)
{
  int	size;
  char	*dup;
  int	i;

  i = 0;
  size = 0;
  while (str[size] != 0)
    size++;
  if (!(dup = malloc(sizeof (char) * size + 1)))
    exit(1);
  while (str[i] != 0)
    {
      dup[i] = str[i];
      i++;
    }
  dup[i] = 0;
  return (dup);
}
