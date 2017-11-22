/*
** main.c for main in /home/rodrig_1/fractals/gwen
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Apr 28 11:36:00 2015 gwendoline rodriguez
** Last update Tue Apr 28 10:28:08 2015 Loik Fauré-Berlinguette
*/

#include "fractals.h"

int	pars(char **av, t_fract fr)
{
  int	i;

  fr.nb = my_getnbr(av[1]);
  fr.one = av[2];
  fr.two = av[3];
  if (fr.nb == 0)
    my_putstr("\n#\n");
  else if (fr.nb == 1)
    {
      
    }
  return (0);
}
