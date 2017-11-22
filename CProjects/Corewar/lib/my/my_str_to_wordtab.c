/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 18:17:56 2014 gwendoline rodriguez
** Last update Mon Mar  9 01:24:56 2015 gwendoline rodriguez
*/

#include <stdlib.h>
#include "my.h"

int     my_count_char(char *s, int *i)
{
  int   cpt;

  cpt = 0;
  while (s[*i] && ((s[*i] >= 'a' && s[*i] <= 'z')
		   || (s[*i] >= 'A' && s[*i] <= 'Z')
		   || (s[*i] >= '0' && s[*i] <= '9')))
    {
      cpt = cpt + 1;
      *i = *i + 1;
    }
  return (cpt);
}

int	my_count_word(char *str)
{
  int	i;
  int	cpt;

  i = 0;
  cpt = 0;
  while (str[i])
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
	  || (str[i] >= '0' && str[i] <= '9'))
	{
	  cpt = cpt + 1;
	  while (str[i] && ((str[i] >= 'a' && str[i] <= 'z')
			    || (str[i] >= 'A' && str[i] <= 'Z')
			    || (str[i] >= '0' && str[i] <= '9')))
	    i = i + 1;
	}
      i = i + 1;
    }
  return (cpt);
}

char    **my_str_to_wordtab(char *str)
{
  int   i;
  int   n;
  int   word;
  char  **tab;

  i = 0;
  n = 0;
  word = my_count_word(my_strdup(str));
  tab = (char **)malloc(sizeof(char *) * word);
  while (str[i] && word > 0)
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
	  || (str[i] >= '0' && str[i] <= '9'))
	{
	  tab[n] = my_strdup(str + i);
	  tab[n][my_count_char(str, &i)] = '\0';
	  n = n + 1;
	  word = word - 1;
	}
      i = i + 1;
    }
  tab[my_count_word(my_strdup(str))] = NULL;
  return (tab);
}
