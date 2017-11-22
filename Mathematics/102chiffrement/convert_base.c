/*
** convert_base.c for convert_base in /home/rodrig_1/rendu/Maths/102chiffrement
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Wed Nov 26 15:05:20 2014 gwendoline rodriguez
** Last update Wed Nov 26 19:25:11 2014 gwendoline rodriguez
*/

#include "my.h"

char    convert_base(int matrice, char *base)
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
  return (base[result]);
}
