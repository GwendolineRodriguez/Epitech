/*
** reverskey.c for reverskey in /home/rodrig_1/rendu/Maths/102chiffrement
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Wed Nov 26 15:04:26 2014 gwendoline rodriguez
** Last update Wed Nov 26 15:05:55 2014 gwendoline rodriguez
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int     *reverskey(int *key)
{
  int   *reversedkey;
  int   test;
  int   i;

  i = 0;
  reversedkey = malloc(4 * sizeof(int));
  test = ((key[0]) * (key[3])) - ((key[1]) * (key[2]));
  if (test == 0)
    {
      write(2, "Error : Matrice not reversible.\n", 31);
      exit (0);
    }
  my_swap(&key[0], &key[3]);
  key[1] = key[1] * (-1);
  key[2] = key[2] * (-1);
  while (i != 4)
    {
      reversedkey[i] = key[i];
      i = i + 1;
    }
  return (reversedkey);
}

