/*
** main.c for main in /home/rodrig_1/fractals/gwen
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Apr 28 11:36:00 2015 gwendoline rodriguez
** Last update Tue Apr 28 14:56:16 2015 gwendoline rodriguez
*/

#include "fractals.h"

int	display_solo(char *s, int i)
{
  while (s[i] != 0)
    {
      if (s[i] == '#')
	my_putchar('#');
      else if (s[i] == ' ')
	my_putchar(' ');
      else if (s[i] == '@')
	return (i + 1);
      i++;
    }
  return (i);
}

void	display(int pos, int i, t_fract *fr)
{
  int	j;

  j = fr->nb;
  while (fr->one[i] != 0)
    {
      if (fr->one[i] == '#')
	my_putchar('#');
      else if (fr->one[i] == ' ')
	my_putchar(' ');
      if (fr->one[i] == '@')
	{
	  if (fr->nb > 1)
	    {
	      pos = display_solo(fr->one, pos);
	      fr->nb--;
	    }
	  else
	    display_solo(fr->two, 0);
	  my_putchar('\n');
	}
      if (fr->one[i + 1] == '\0' && j == 2)
      	pos = display_solo(fr->one, pos);
      i++;
    }
}

int	pars(char **av, t_fract fr)
{
  int	i;
  int	n;

  fr.nb = my_getnbr(av[1]);
  n = fr.nb;
  fr.one = av[2];
  fr.two = av[3];
  my_putchar('\n');
  if (n == 0)
    my_putchar('#');
  else
    {
      while (n > 0)
	{
	  display(0, 0, &fr);
	  if ((n - 1) > 0)
	    my_putchar('\n');
	  n--;
	}
    }
  my_putchar('\n');
  return (0);
}
