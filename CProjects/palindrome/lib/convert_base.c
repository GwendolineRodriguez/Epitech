/*
** convert_base.c for convert_base in /home/gwendoline/lib/my
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline.rodriguez@epitech.eu>
**
** Started on  Thu Oct  9 17:32:09 2014 Gwendoline Rodriguez
** Last update Sat Jun 27 12:29:47 2015 Gwendoline Rodriguez
*/

#include "header.h"

char    *my_revstr(char *str)
{
  int   i;
  int   j;
  char  c;

  i = -1;
  j = my_strlen(str) - 1;
  while (++i < j)
    {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
      j--;
    }
  return (str);
}

char    *conv_base(int nb)
{
  char  *new;
  int   count;

  if (!(new = malloc(sizeof(char) * (nb + 1))))
    exit(0);
  count = -1;
  while (++count < nb)
    new[count] = count + 48;
  new[count] = 0;
  return (new);
}

int	pos_base(char chr, char *base)
{
  int	pos;

  pos = 0;
  while (*(base + pos) && *(base + pos) != chr)
    pos++;
  if (*(base + pos))
    return (pos);
  else
    return (-1);
}

int	my_getnbr_base(char *str, char *base)
{
  int	res;
  int	size;

  if (*str == '-')
    return (-my_getnbr_base(str + 1, base));
  if (*str == '+')
    return (my_getnbr_base(str + 1, base));
  size = my_strlen(base);
  res = 0;
  while (*str)
    {
      res *= size;
      res += pos_base(*str, base);
      str++;
    }
  return (res);
}

char    *convert_base(char *nbr, char *base_from, char *base_to)
{
  int   count;
  int   nb;
  char  *res;

  count = 0;
  res = malloc(sizeof(char) * 300);
  nb = my_getnbr_base(nbr, base_from);
  while (nb > 0)
    {
      res[count] = base_to[nb % my_strlen(base_to)];
      nb = nb / my_strlen(base_to);
      count++;
    }
  res[count] = '\0';
  res = my_revstr(res);
  return (res);
}
