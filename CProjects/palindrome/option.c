/*
** option.c for option in /home/gwendoline/rendu/Piscine_Synthese/palindrome
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jun 26 21:17:56 2015 Gwendoline Rodriguez
** Last update Sat Jun 27 17:10:53 2015 Gwendoline Rodriguez
*/

#include "header.h"

void            fill_constraint(char *str, t_param *p)
{
  int           i;
  int           j;
  char		*itop;

  i = 0;
  j = 0;
  if ((itop = malloc(sizeof(char) * 3)) == NULL)
    put_error("ERROR on malloc\n");
  while (str[i] == '>' || str[i] == '<' || str[i] == '=')
    itop[j++] = str[i++];
  itop[j] = '\0';
  if (itop[0] == '<' && p->itmax == 0)
    {
      p->itopmax = my_strdup(itop);
      p->itmax = atoi(&str[i]);
    }
  else if (p->itmin == 0)
    {
      p->itopmin = my_strdup(itop);
      p->itmin = atoi(&str[i]);
    }
}

void            get_opt(char **av, t_param *p)
{
  int           i;

  i = 2;
  if (atoi(av[2]) > 10 || atoi(av[2]) <= 1 || atoi(av[1]) <= 0)
    put_error("argument invalide\n");
  p->b = atoi(av[2]);
  p->save = atoi(av[1]);
  if (atoi(av[1]) > 2147483647)
    put_error("argument invalide\n");
  p->base = get_charbase(p->b);
  while (av[++i] != NULL)
    {
      if (strcmp(av[i], "reverse") == 0)
	p->reverse = 1;
      else
	fill_constraint(av[i], p);
    }
}
