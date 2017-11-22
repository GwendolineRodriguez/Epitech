/*
** 102chiffrement.c for 102chiffrement in /home/rodrig_1/rendu/102chiffrement
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Sun Nov 23 21:26:32 2014 gwendoline rodriguez
** Last update Sun Nov 30 23:16:02 2014 gwendoline rodriguez
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char		*encrypt(char *str, int *key, char *base, int i)
{
  int		*matrice;
  int		*crypted;
  int		l;
  int		t;
  int		x;

  l = my_strlen(str);
  if (l % 2 != 0)
    l = l + 1;
  crypted = malloc(sizeof(int) * (my_strlen(str) + 1));
  matrice = my_matrice(str, 0);
  while (i < l)
    {
      if ((i % 2) == 0)
	{
	  x = matrice[i];
	  t = matrice[i + 1];
	  crypted[i] = x * key[0] + t * key[2];
	}
      else if ((i % 2) == 1)
	crypted[i] = x * key[1] + t * key[3];
      i = i + 1;
    }
  printf("chiffrement de \"%s\" à l'aide de la clé %d %d %d %d dans la base \"%s\"\n", str, key[0], key[1], key[2], key[3], base);
  my_putstr("=> ");
  i = 0;
  while (i < l)
    {
      convert_base(crypted[i], base);
      my_putchar(' ');
      i = i + 1;
    }
  my_putchar('\n');
  free(matrice);
}

char		*decrypt(char *str, int *key, char *base, int i)
{
  int		l;
  int		*matrice;
  int		*matuncrypted;
  char		*uncrypted;
  char		**tab;
  int		x;
  int		t;

  matuncrypted = malloc(sizeof(int) * my_strlen(str));
  matrice = malloc(sizeof(int) * my_strlen(str));
  printf("déchiffrement de \"%s\" à l'aide de la clé %d %d %d %d dans la base \"%s\"\n", str, key[0], key[1], key[2], key[3], base);
  key = reverskey(key);
  l = count_word(str);
  my_putstr("=> ");
  while (i < l)
    {
      tab = my_str_to_wordtab(str);
      i = i + 1;
    }
  i = 0;
  while (i < l)
    {
      matrice[i] = my_getnbr_base(tab[i], base);
      i = i + 1;
    }
  i = 0;
  while (i < l)
    {
      if ((i % 2) == 0)
	{
	  x = matrice[i];
	  t = matrice[i + 1];
	  matuncrypted[i] = x * key[0] + t * key[2];
	}
      else if ((i % 2) == 1)
	matuncrypted[i] = x * key[1] + t * key[3];
      i = i + 1;
    }
  uncrypted = uncrypt(matuncrypted, i, str);
  free(matuncrypted);
  free(matrice);
  return(uncrypted);
}

void		main(int ac, char **av)
{
  int		i;
  int		*key;
  char		*cp;
  char		*cp2;
  int		*reversedkey;

  i = 0;
  if (ac == 8)
    {
      key = malloc(sizeof(int) * 4);
      while (i != 4)
	{
	  key[i] = my_getnbr(av[i + 2]);
	  i = i + 1;
	}
      if (my_strcmp(av[7], "0") == 0)
	{
	  cp = encrypt(av[1], key, av[6], 0);
	  free(cp);
	}
      else if (my_strcmp(av[7], "1") == 0)
	{
	  my_putstr(decrypt(av[1], key, av[6], 0));
	  my_putchar('\n');
	}
    }
  else
    my_putstr("Usage : Message key(4 numbers) base flag(0 or 1)\n");
  free(key);
}
