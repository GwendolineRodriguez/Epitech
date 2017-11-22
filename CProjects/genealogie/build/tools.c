/*
** tools.c for tools in /home/gwendoline/rendu/Piscine_Synthese/genealogie
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jul  3 15:20:16 2015 Gwendoline Rodriguez
** Last update Sat Jul  4 14:46:54 2015 Gwendoline Rodriguez
*/

#include "header.h"

void            put_error(char *str)
{
  write(2, str, strlen(str));
}


char            *put_lower(char *str)
{
  int           i;
  char          *new;

  i = -1;
  new = strdup(str);
  while (new[++i])
    {
      if (new[i] >= 'A' && new[i] <= 'Z')
        new[i] = new[i] + 32;
    }
  return (new);
}

int             len_tab(char **tab)
{
  int           i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
