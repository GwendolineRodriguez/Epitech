/*
** main.c for menger in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d01/ex01
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Wed Jan  6 11:41:43 2016 Gwendoline Rodriguez
** Last update Wed Jan  6 18:38:28 2016 Gwendoline Rodriguez
*/

#include "header.h"

int     if_neg(char *str, int *nb)
{
  int   i;
  int   sign;

  i = 0;
  sign = 0;
  while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
    {
      if (str[i] == '-')
        sign = sign + 1;
      i = i + 1;
    }
  if (sign % 2 != 0)
    *nb = *nb * (-1);
  return (0);
}

int     my_getnbr(char *str)
{
  int   nb;
  int   i;

  nb = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
        {
          nb = nb * 10;
          nb = nb + (str[i] - 48);
          i = i + 1;
        }
      else if (str[i] <= '0' && str[i] >= '9')
        return (nb);
      else        i = i + 1;
    }
  if (nb > 2000000000)
    return (0);
  if_neg(str, &nb);
  return (nb);
}

int    main(int ac, char **av)
{
  int size;
  int level;

  size = 0;
  level = 0;
  if (ac == 3)
    {
      size = my_getnbr(av[1]);
      level = my_getnbr(av[2]);
      if (ac == 3 && size > 0 && level > 0
	  && (size % 3 == 0) && (level <= (size / 3)))
	menger(size, level, 0, 0);
    }
  return (0);
}

