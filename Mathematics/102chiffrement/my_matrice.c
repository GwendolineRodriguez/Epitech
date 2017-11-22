/*
** my_matrice.c for my_matrice in /home/rodrig_1/rendu/Maths/102chiffrement
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Wed Nov 26 14:54:20 2014 gwendoline rodriguez
** Last update Wed Nov 26 14:54:21 2014 gwendoline rodriguez
*/

#include <stdlib.h>
#include <stdio.h>

int     put_in_matrice(char c)
{
  char  base[27];
  int   i;

  i = 0;
  my_strcpy(base, " abcdefghijklmnopqrstuvwxyz");
  while (base[i] != c)
    i++;
  return (i);
}

int     *my_matrice(char *str, int i)
{
  int   *matrice;

  matrice = malloc(sizeof(int*) * (my_strlen(str) + 1));
  while (str[i] != '\0')
    {
      matrice[i] = put_in_matrice(str[i]);
      i = i + 1;
    }
  if (my_strlen(str) % 2 == 1)
    matrice[i] = 0;
  return (matrice);
}

