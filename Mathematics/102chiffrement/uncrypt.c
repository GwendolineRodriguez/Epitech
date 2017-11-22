/*
** uncrypt.c for uncrypt in /home/rodrig_1/rendu/Maths/102chiffrement
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Sat Nov 29 23:55:01 2014 gwendoline rodriguez
** Last update Sun Nov 30 23:17:22 2014 gwendoline rodriguez
*/

#include <stdlib.h>
#include <stdio.h>

char     put_in_str(int nb)
{
  char  base[27];
  int   i;

  i = 0;
  if ((nb + 96) == '`')
    base[i] = ' ';
  else
    while (base[i] != (nb + 96))
      i++;
  return (base[i]);
}

char     *uncrypt(int *matrice, int imax, char *str)
{
  char   *uncrypted;
  int	i;
  int	l;

  i = 0;
  uncrypted = malloc(sizeof(char*) * (my_strlen(str)));
  if (matrice[imax] == 0)
    l = count_word(str) - 1;
  else
    l = count_word(str);
  while (i != l)
    {
      uncrypted[i] = put_in_str(matrice[i]);
      i = i + 1;
    }
  return (uncrypted);
}
