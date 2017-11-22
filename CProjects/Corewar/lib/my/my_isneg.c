/*
** my_isneg.c for my_isneg in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 18:35:42 2014 gwendoline rodriguez
** Last update Sun Mar  8 23:28:59 2015 gwendoline rodriguez
*/

#include "my.h"

int	my_isneg(int n)
{
  int	positif;
  int	negatif;

  positif = 80;
  negatif = 78;
  if (n >= 0)
    {
      my_putchar(positif);
    }

  else if (n < 0)
    {
      my_putchar(negatif);
    }
  return (0);
}
