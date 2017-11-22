/*
** main.c for carre in /home/faure-_l/Colle_carre
** 
** Made by Loik Fauré-Berlinguette
** Login   <faure-_l@epitech.net>
** 
** Started on  Tue May  5 09:32:08 2015 Loik Fauré-Berlinguette
** Last update Tue May  5 12:10:25 2015 gwendoline rodriguez
*/

#include <stdlib.h>

int	isnumber(char nb)
{
  if (nb >= '0' && nb <= '9')
    return (1);
  else
    return (0);
}

int	my_atoi(char *nb)
{
  int	i;
  int	num;

  i = 0;
  num = 0;
  while (isnumber(nb[i]) == 1)
    {
      num = ((nb[i] - 48) + num * 10);
      i++;
    }
  if (num == 0)
    my_error("Integer must be > 0\n");
  return (num);
}

int	pars(int ac, char **av)
{
  int	l;
  int	h;

  l = 10;
  h = 10;
  if (ac == 5)
    {
      l = my_atoi(av[2]);
      h = my_atoi(av[4]);
    }
  get_square(l, h);
  return (0);
}

int	main(int ac, char **av)
{
  pars(ac, av);
  my_putchar('\n');
  return (0);
}
