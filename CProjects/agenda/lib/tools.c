/*
** list.c for list in /home/gwendoline/rendu/Piscine_Synthese/agenda
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jun 29 11:58:29 2015 Gwendoline Rodriguez
** Last update Wed Jul  1 17:36:19 2015 Gwendoline Rodriguez
*/

#include "header.h"

char            *rev_word(char *str)
{
  char          *res;
  char          *tmp;
  char          **tab;

  tab = my_strtowordtab(str);
  tmp = my_strdup(tab[1]);
  res = strcat(tmp, " ");
  res = strcat(res, tab[0]);
  return (res);
}

int             len_tab(char **tab)
{
  int           i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

int             is_intab(char *str, char **tab)
{
  int           j;

  j = -1;
  while (tab[++j])
    {
      if (my_strcmp(str, tab[j]) == 0)
        return (0);
    }
  return (-1);
}

t_employee      *create_employee()
{
  t_employee    *elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    exit(0);
  return (elem);
}

t_meeting	*create_meeting()
{
  t_meeting	*elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    exit(0);
  return (elem);
}
