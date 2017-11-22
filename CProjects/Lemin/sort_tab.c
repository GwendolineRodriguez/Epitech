/*
** sort_tab.c for sort_tab in /home/rodrig_1/rendu/Prgelm/CPE_2014_lemin
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Sat May  2 15:08:21 2015 gwendoline rodriguez
** Last update Sat May  2 15:36:11 2015 gwendoline rodriguez
*/

#include "lemin.h"

int     len_tab(char **tab)
{
  int   i;

  i = 0;
  while (tab[i])
      i++;
  return (i);
}

void    swaptab(char **tab, int i, int j)
{
  char *str;

  str = tab[i];
  tab[i] = tab[j];
  tab[j] = str;
}

t_peak	**sort_tab(t_peak **tab)
{
  int   len;
  int   i;
  int   j;

  len = len_tab(tab);
  while (len > 0)
    {
      i = 1;
      j = 0;
      while (tab[i])
	{
	  if (my_strlen(tab[j]) < my_strlen(tab[i]))
	    swaptab(tab, j, i);
	  i++;
	  j++;
	}
      len--;
    }
  return (tab);
}
