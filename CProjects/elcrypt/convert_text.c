/*
** convert_text.c for convert_text in /home/rodrig_1/rendu/Prgelm/elcrypt
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Sun Mar  1 20:47:57 2015 gwendoline rodriguez
** Last update Sun Mar  1 23:11:04 2015 gwendoline rodriguez
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "my.h"

char                    *conv_text(char *tex, int i, int j, char *av)
{
  char                  **oct;

  if ((oct = malloc(sizeof(char*) * 8)) == NULL)
    exit(0);
  while (i < 8)
    {
      if ((oct[i] = malloc(sizeof(char) * 9)) == NULL)
	exit(0);
      while (j <= 8)
	oct[i][j++] = '\0';
      i++;
    }
  i = 0;
  while (av[i] != '\0')
    oct = tab_text(&j, &i, av, oct);
  i = 0;
  while (i < 8)
    {
      oct[i] = my_revstr(oct[i]);
      tex = strcat(tex, oct[i++]);
    }
  return (tex);
}

char                    *parity_bit(char *key_prim, char *key)
{
  int                   i;
  int                   j;

  i = 0;
  j = 0;
  while (key[i] != '\0')
    {
      if ((i + 1) % 8 != 0)
	key_prim[j++] = key[i];
      i++;
    }
  key_prim[56] = '\0';
  return (key_prim);
}

char                    *rotate_key(char *key_prim)
{
  char                  tab[5];
  int                   i;
  int                   j;

  i = 0;
  j = 0;
  while (i < 4)
    {
      tab[i] = key_prim[i];
      i++;
    }
  tab[i] = '\0';
  i = 4;
  while (key_prim[i] != '\0')
    {
      key_prim[i - 4] = key_prim[i];
      i++;
    }
  while ((i - 4) < 56)
    {
      key_prim[i - 4] = tab[j++];
      i++;
    }
  return (key_prim);
}

char                    *or_exc(char *dest, char *src)
{
  int                   i;

  i = 0;
  while (dest[i] != '\0')
    {
      if (dest[i] == '0' && src[i] == '1')
	dest[i] = '1';
      else if (dest[i] == '1' && src[i] == '0')
	dest[i] = '1';
      else        dest[i] = '0';
      i++;
    }
  return (dest);
}

int                     my_exp(int val, int n)
{
  if (n == 0)
    val = 1;
  else if (n == 1)
    val = 2;
  else if (n == 2)
    val = 4;
  else if (n == 3)
    val = 8;
  else if (n == 4)
    val = 16;
  else if (n == 5)
    val = 32;
  else if (n == 6)
    val = 64;
  else if (n == 7)
    val = 128;
  return (val);
}
