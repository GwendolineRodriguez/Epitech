/*
** my_sort_wordtab.c for my_sort_wordtab in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Mon Dec  1 14:48:19 2014 gwendoline rodriguez
** Last update Sun Mar  8 23:48:43 2015 gwendoline rodriguez
*/

#include "my.h"

int	len_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      i++;
    }
  return (i);
}

void	swaptab(char **tab, int i, int j)
{
  char *str;

  str = tab[i];
  tab[i] = tab[j];
  tab[j] = str;
}

int	my_sort_wordtab(char **tab)
{
  int	len;
  int	i;
  int	j;

  len = len_tab(tab);
  while (len > 0)
    {
      i = 1;
      j = 0;
      while (tab[i])
	{
	  if (my_strcmp(tab[j], tab[i]) > 0)
	    swaptab(tab, j, i);
	  i++;
	  j++;
	}
      len--;
    }
  return (0);
}
