/*
** functions_explode.c for  in /home/rouge_b/rendu/PersoProject/my_explode
** 
** Made by Bastien Rougé
** Login   <rouge_b@epitech.net>
** 
** Started on  Mon Apr 27 15:51:45 2015 Bastien Rougé
** Last update Tue Apr 28 01:07:57 2015 Bastien Rougé
*/

#include "explode.h"

int     my_tablen(char **tab)
{
  int   count;

  count = 0;
  while (tab[count])
    count++;
  return (count);
}

int	exp_match(my_explode_t *exp, int mode, int ref)
{
  int	count;

  count = 0;
  while (exp->str[ref])
    {
      if (exp->str[ref] == exp->expr[count])
	count++;
      else if (!exp->expr[count])
	return (1);
      else
	return (0);
      if (mode)
	ref++;
      else
	ref--;
    }
  if (!exp->expr[count])
    return (1);
  else
    return (0);
}
