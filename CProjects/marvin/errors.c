/*
** errors.c for errors in /home/rodrig_1/rendu/Prgelm/marvin
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Sun Jan  4 15:35:52 2015 gwendoline rodriguez
** Last update Sun Jan  4 18:30:08 2015 gwendoline rodriguez
*/

#include "include/my.h"

int	check_par(char *str)
{
  int	i;
  int	d;
  int	f;

  i = 0;
  d = 0;
  f = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '(')
	d = d + 1;
      if (str[i] == ')')
	f = f + 1;
      i = i + 1;
    }
  if (d != f)
    {
      printf("There is a missing parenthesis!\n");
      return (-1);
    }
  return (0);
}

int	check_bra(char *str)
{
  int	i;
  int	d;
  int	f;

  i = 0;
  d = 0;
  f = 0;
  while (str[i + 1] != '\0')
    {
      if (str[i] == '[')
	d = d + 1;
      if (str[i] == ']')
	f = f + 1;
      i = i + 1;
    }
  if (d != f)
    {
      printf("There is a missing bracket!\n");
      return (-1);
    }
  return (0);
}

int	checkpoint(char *str)
{
  int   len;

  len = my_strlen(str) - 1;
  while (len > 0)
    {
      if (str[len] != ' ' && str[len] != ';')
	{
	  printf("Character '%c' at the end, ", str[len]);
	  printf("must end line with ';'");
	  return (-1);
	}
      if (str[len] == ';')
	return (0);
      len = len - 1;
    }
  return (-1);
}

int	check_errors(char *str)
{
  int	e;

  e = 0;
  e = e + checkpoint(str);
  e = e + check_par(str);
  e = e + check_bra(str);
  e = e + check_for(str);
  return (e);
}
