/*
** my_free_double.c for  in /home/daniel_b/Rendu/PSU_2014_minishell1
** 
** Made by DANIEL Erwan
** Login   <daniel_b@epitech.net>
** 
** Started on  Sat Jan 31 18:01:15 2015 DANIEL Erwan
** Last update Sat Jan 31 21:51:21 2015 DANIEL Erwan
*/

#include <stdlib.h>

void	my_free_double(char **foo)
{
  int	i;

  while (foo[i])
    free(foo[i++]);
  free(foo);
}
