/*
** my_getnbr_base.c for my_getnbr_base in /home/rodrig_1/Downloads
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Wed Nov 26 17:53:14 2014 gwendoline rodriguez
** Last update Sun Mar  8 23:24:20 2015 gwendoline rodriguez
*/

#include "my.h"

int     init(char *base, int *nbr, int *j, int *i)
{
  int   len;

  len = my_strlen(base);
  *nbr = 0;
  *j = 0;
  *i = 1;
  return (len);
}

int     check_neg(char *s)
{
  int   i;
  int   cpt;

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

int     check_base(char *base, int n)
{
  int   i;

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

int     my_getnbr_base(char *str, char *base)
{
  int   nbr;
  int   len;
  int   j;
  int   k;
  int   i;

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
      else
        if ((str[j] != '-' && str[j] != '+'))
          return (0);
      j = j + 1;
    }
  return (nbr * i);
}
