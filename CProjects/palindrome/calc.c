/*
** calc.c for calc in /home/gwendoline/rendu/Piscine_Synthese/palindrome
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jun 26 13:29:29 2015 Gwendoline Rodriguez
** Last update Sat Jun 27 16:02:01 2015 Gwendoline Rodriguez
*/

#include "header.h"

void		check_itmax(t_param *p)
{
  if (strcmp(p->itopmax, "<") == 0)
    {
      if (p->it >= p->itmax)
	put_error("pas de solution\n");
    }
  else if (strcmp(p->itopmax, "<=") == 0)
    {
      if (p->it > p->itmax)
        put_error("pas de solution\n");
    }
}

int		check_itmin(t_param *p)
{
  if (strcmp(p->itopmin, ">") == 0)
    {
      if (p->it <= p->itmin)
	return (-1);
    }
  else if (strcmp(p->itopmin, ">=") == 0)
    {
      if (p->it < p->itmin)
	return (-1);
    }
  return (0);
}

int             check_if_palindrome(t_param *p)
{
  int           len;
  int           i;

  i = 0;
  if (p->reverse == 0 && p->check_pass++ == 0)
    p->n = p->save;
  p->nbchar = malloc(sizeof(char) * 50);
  sprintf(p->nbchar, "%d", p->n);
  p->nbchar = convert_base(p->nbchar, "0123456789", p->base);
  len = my_strlen(p->nbchar) - 1;
  p->revchar = malloc((sizeof(char) * my_strlen(p->nbchar)) + 1);
  while (len >= 0)
    {
      p->revchar[i] = p->nbchar[len];
      len--;
      i++;
    }
  p->revchar[my_strlen(p->nbchar)] = '\0';
  return (strcmp(p->revchar, p->nbchar));
}

int            show_palindrome(t_param *p)
{
  check_itmax(p);
  if ((p->check = check_if_palindrome(p)) == 0 && check_itmin(p) == 0)
    {
      if (p->n < p->save)
        put_error("overflow\n");
      if (p->reverse == 0)
	printf("%d donne %d en %d itération(s) (en base %d)\n",
	       p->save, p->n, p->it, p->b);
      else if (p->reverse == 1)
	printf("%d donne %d en %d itération(s) (en base %d)\n",
               p->n, p->save, p->it, p->b);
      return (0);
    }
  else
    {
      p->it++;
      p->nbchar = convert_base(p->nbchar, p->base, "0123456789");
      p->revchar = convert_base(p->revchar, p->base, "0123456789");
      p->rev = atoi(p->revchar);
      p->n = atoi(p->nbchar);
      p->n = p->n + p->rev;
      show_palindrome(p);
    }
  return (0);
}
