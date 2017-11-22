/*
** explode.c for  in /home/rouge_b/rendu/PersoProject/my_explode
** 
** Made by Bastien Rougé
** Login   <rouge_b@epitech.net>
** 
** Started on  Mon Apr 27 15:12:41 2015 Bastien Rougé
** Last update Tue Apr 28 00:57:19 2015 Bastien Rougé
*/

#include <stdlib.h>
#include <stdio.h>
#include "explode.h"

int	nb_occur(my_explode_t *exp)
{
  int	occur;
  int	count;
  int	count2;

  occur = 0;
  count = -1;
  count2 = 0;
  while (exp->str[++count])
    {
      if (exp->str[count] == exp->expr[count2])
	count2++;
      else if (!exp->expr[count2])
	{
	  if (exp->str[count - count2 - 1] && !occur)
	    occur++;
	  if (exp->str[count])
            occur++;
	  count2 = 0;
	}
      else
	count2 = 0;
    }
  return (occur);
}

int	nb_chartocpy(my_explode_t *exp, int mode, int ref)
{
  int	count;

  count = 0;
  while (exp->str[ref])
    {
      if (exp_match(exp, mode, ref))
	return (count);
      else
	count++;
      if (mode)
	ref++;
      else
	ref--;
    }
  return (count);
}

void	cpyresult(my_explode_t *exp, int mode, int ref, int occur)
{
  int	len;
  int	count;
  int	chartocpy;

  len = my_tablen(exp->result);
  if (!(exp->result[len] = malloc(sizeof(char) *
				  (nb_chartocpy(exp, mode, ref) + 1))))
    exit(0);
  count = -1;
  chartocpy = nb_chartocpy(exp, mode, ref);
  if (!mode)
    ref -= chartocpy - 1;
  while (++count != chartocpy)
    {
      exp->result[len][count] = exp->str[ref];
      ref++;
    }
  exp->result[len][count] = 0;
  exp->result[len + 1] = 0;
}

void	parse_explode(my_explode_t *exp)
{
  int   occur;
  int   count;
  int   count2;

  occur = 0;
  count = -1;
  count2 = 0;
  while (exp->str[++count])
    {
      if (exp->str[count] == exp->expr[count2])
        count2++;
      else if (!exp->expr[count2])
        {
          if (exp->str[count - count2 - 1] && !occur)
	    cpyresult(exp, 0, count - count2 - 1, occur++);
          if (exp->str[count])
            cpyresult(exp, 1, count, occur++);
          count2 = 0;
        }
      else
        count2 = 0;
    }
}

char		**my_explode(char *expr, char *str)
{
  my_explode_t	*exp;

  if (!(exp = malloc(sizeof(*exp))))
    exit(0);
  exp->expr = expr;
  exp->str = str;
  if (!(exp->result = malloc(sizeof(char*) * (nb_occur(exp) + 1))))
    exit(0);
  exp->result[0] = 0;
  parse_explode(exp);
  return (exp->result);
}
