/*
** my_putnbr_base.c for my_putnbr_base in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Mon Nov 24 15:23:21 2014 gwendoline rodriguez
** Last update Sun Mar  8 23:40:22 2015 gwendoline rodriguez
*/

#include "my.h"

void	my_putnbr_base(int matrice, char *base)
{
  int   s;
  int   diviseur;
  int   result;

  diviseur = 1;
  s = my_strlen(base);
  if (matrice < 0)
    matrice = -matrice;
  while ((matrice / diviseur) >= s)
    diviseur = diviseur * s;
  while (diviseur > 0)
    {
      result = (matrice /diviseur) % s;
      my_putchar(base[result]);
      diviseur = diviseur / s;
    }
}

