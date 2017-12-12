/*
** my_sort_int_tab.c for my_sort_int_tab in /home/rodrig_1/rendu/Piscine_C_J04
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 22:34:43 2014 gwendoline rodriguez
** Last update Mon Dec  8 11:35:00 2014 gwendoline rodriguez
*/

void    my_sort_int_tab(int *tab, int size)
{
  int   i;
  int   sort;
  int   nb;

  nb = 0;
  sort = 0;
  while (sort == 0)
    {
      i = 0;
      sort = 1;
      while ((i + 1) < size)
	{
	  if (tab[i] > tab[i + 1])
	    {
	      sort = 0;
	      my_swap(&tab[i], &tab[i + 1]);
	    }
	  i = i + 1;
	}
      nb = nb + 1;
    }
}

int	main()
{
  int	*tab[];

  tab[0] = 1;
  my_sort_int_tab(tab, 6);
}
