/*
** my_parse_str.c for  in /home/daniel_b/Rendu/PSU_2014_minishell1/lib/my
** 
** Made by DANIEL Erwan
** Login   <daniel_b@epitech.net>
** 
** Started on  Fri Jan 30 02:04:02 2015 DANIEL Erwan
** Last update Sun Feb  1 22:50:19 2015 DANIEL Erwan
*/

#include <stdlib.h>
#include <stdio.h>

char	*get_next_elem(char **str, char key)
{
  char	*elem;
  int	size;
  int	i;

  size = 0;
  i = 0;
  while (*str[0] != 0 && *str[0] == key)
    str[0]++;
  while (str[0][size] != 0 && str[0][size] != key)
    size++;
  if (str[0][0] == 0)
    return (0);
  if (!(elem = malloc(sizeof (char) * (size + 1))))
    exit(1);
  while (i < size)
    {
      elem[i] = *str[0];
      str[0]++;
      i++;
    }
  elem[i] = 0;
  return (elem);
}

char	**my_parse_str(char *str, char key)
{
  char	**tab;
  int	nb_elem;
  int	i;

  nb_elem = 1;
  i = 0;
  while (str[i] != 0)
    if (str[i++] == key)
      nb_elem++;
  if (!(tab = malloc(sizeof (char *) * (nb_elem + 1))))
    exit(1);
  i = 0;
  while (i < nb_elem)
    {
      tab[i] = get_next_elem(&str, key);
      i++;
    }
  tab[i] = 0;
  return (tab);
}
