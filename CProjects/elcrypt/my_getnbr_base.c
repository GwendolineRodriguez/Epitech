/*
** my_getnbr_base.c for getnbr_base in /home/leboeu_q/sem2/rush1
**
** Made by Quentin Leboeuf
** Login   <leboeu_q@epitech.net>
**
** Started on  Fri Feb 27 23:56:14 2015 Quentin Leboeuf
** Last update Sun Mar  1 18:52:53 2015 gwendoline rodriguez
*/

#include "structs.h"

long     init(char *base, long *nbr, long *j, long *i)
{
  long   len;

  len = my_strlen_long(base);
  *nbr = 0;
  *j = 0;
  *i = 1;
  return (len);
}

long     check_neg(char *s)
{
  long   i;
  long   cpt;

  i = 0;
  cpt = 0;
  while (s[i] && (s[i] < '0' || s[i] > '9'))
    {
      if (s[i] == '-')
	{
	  cpt = cpt + 1;
	}
      i = i + 1;
    }
  if (cpt % 2 == 0)
    {
      return (1);
    }
  return (-1);
}

long     check_base(char *base, long n)
{
  long   i;

  n = 0;
  while (base[n])
    {
      i = 0;
      while (base[i])
	{
	  if (i != n)
	    {
	      if (base[n] == base[i])
		{
		  return (-1);
		}
	    }
	  i = i + 1;
	}
      n = n + 1;
    }
  return (0);
}

long     my_getnbr_base(char *str, char *base)
{
  long   nbr;
  long   len;
  long   j;
  long   k;
  long   i;

  len = init(base, &nbr, &j, &i);
  i = check_neg(str);
  if (check_base(base, 0) == -1)
    return (0);
  while (str[j])
    {
      k = 0;
      while (k < len && base[k] != str[j])
	k = k + 1;
      if (base[k] == str[j])
	nbr = nbr * len + k;
      else if ((str[j] != '-' && str[j] != '+'))
	return (0);
      j = j + 1;
    }
  return (nbr * i);
}

