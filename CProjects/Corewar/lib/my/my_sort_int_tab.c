/*
** my_sort_int_tab.c for my_sort_int_tab in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 18:40:17 2014 gwendoline rodriguez
** Last update Sun Mar  8 23:47:11 2015 gwendoline rodriguez
*/

#include "my.h"

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	nb;
  int	sort;

  nb = 0;
  sort = 0;
  while (sort == 0)
    {
      i = 0;
      sort = 1;
      while ((i + 1) < size)
	{
	  if (tab[i] < tab[i + 1])
	    {
	      sort = 0;
	      my_swap(&tab[i], &tab[i + 1]);
	    }
	  i = i + 1;
	}
      nb = nb + 1;
    }
}
