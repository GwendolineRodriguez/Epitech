/*
** game.c for game in /home/rodrig_1/rendu/Prgelm/Allum1
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Sat Feb 21 11:25:59 2015 gwendoline rodriguez
** Last update Sun Feb 22 17:57:18 2015 gwendoline rodriguez
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int		my_error(char *str)
{
  int		len;

  len = my_strlen(str);
  write(2, str, len);
  return (0);
}

int		lines(int *tab, char *buffer)
{
  int           i;
  int           nb;
  int           ret;
  int           check;

  check = 0;
  while (check == 0)
    {
      write(1, "Enter number of line.\n", 22);
      ret = read(0, buffer, 100);
      if ((ret > 0) && (my_getnbr(buffer) > 0) && (my_getnbr(buffer) < 5)
	  && (tab[(my_getnbr(buffer) - 1)] != 0))
	{
	  i = my_getnbr(buffer) - 1;
	  check = 1;
	}
      else
	my_error("Error : number must be between 1 and 4 and non empty.\n");
    }
  return (i);
}

int		*matchs(int *tab, char *buffer, int i)
{
  int           nb;
  int           ret;
  int           check;

  check = 0;
  while (check == 0)
    {
      write(1, "Enter number of match.\n", 23);
      ret = read(0, buffer, 100);
      if ((ret > 0) && (my_getnbr(buffer) > 0)
	  && (my_getnbr(buffer) <= tab[i]))
	{
	  nb = tab[i] - my_getnbr(buffer);
	  check = 1;
	}
      else
	my_error("Error : matchs must be between 1 and number max of matchs.\n");
    }
  tab[i] = nb;
  return (tab);
}

int		*game(int *tab, char *buffer)
{
  int		i;

  i = lines(tab, buffer);
  tab = matchs(tab, buffer, i);
  return (tab);
}

int		*ia(int *tab)
{
  int		i;

  i = 3;
  while (tab[i] == 0)
    i--;
  if (tab[i] > 0 && tab[i] > 4)
    tab[i] = tab[i] % 4;
  else if (tab[i] > 1)
    tab[i] = 1;
  else if (tab[i] == 1)
    tab[i] = 0;
  else
    my_error("Computer does not find any solution");
  return (tab);
}
