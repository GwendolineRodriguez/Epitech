/*
** allum1.c for allum1 in /home/rodrig_1/rendu/Prgelm/Allum1
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Sat Feb 21 10:00:04 2015 gwendoline rodriguez
** Last update Sun Feb 22 18:01:13 2015 gwendoline rodriguez
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int		*my_tab()
{
  int           *tab;
  int		i;
  int		nb;

  i = 0;
  nb = 1;
  if ((tab = malloc(5 * sizeof(int))) == NULL)
    return (0);
  tab[4] = -1;
  while (tab[i] != -1)
    {
      tab[i] = nb;
      i++;
      nb = nb + 2;
    }
  return (tab);
}

int		*my_pyramid(int *tab, int c)
{
  int		j;
  int		space;

  space = 10;
  system("clear");
  while (tab[c] != -1)
    {
      j = 0;
      while (j < (space - 1))
	{
	  my_putchar(' ');
	  j++;
	}
      j = 0;
      while (j < tab[c])
	{
	  my_putchar('|');
	  j++;
	}
      c++;
      space = space - 1;
      my_putchar('\n');
    }
  return (tab);
}

int		result(int check)
{
  write(1, "Game over !\n", 12);
  my_putchar('\n');
  if (check % 2 == 0)
    my_putstr("Badass ! You win !\n");
  else        my_putstr("Sorry, looser !\n");
  return (0);
}

int		main(int ac, char **av)
{
  int		*tab;
  char		*buffer;
  int		check;

  if ((buffer = malloc(100 * sizeof(char))) == NULL)
    return (0);
  tab = my_tab();
  check = 0;
  if (ac == 1)
    {
      my_pyramid(tab, 0);
      while (tab[0] != 0 || tab[1] != 0 || tab[2] != 0 || tab[3] != 0)
	{
	  tab = my_pyramid(game(tab, buffer), 0);
	  check++;
	  if (((tab[0] != 0) || (tab[1] != 0)) || ((tab[2] != 0) || (tab[3] != 0)))
	    {
	      my_putstr("Please wait for the computer to play...\n");
	      sleep(2);
	      tab = my_pyramid(ia(tab), 0);
	      check++;
	    }
	}
      result(check);
    }
}
