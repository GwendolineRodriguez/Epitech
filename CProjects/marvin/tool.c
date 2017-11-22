/*
** tool.c for tool in /home/kerebel/Documents/EPITECH/marvin
** 
** Made by kerebe_p
** Login   <kerebe_p@epitech.eu>
** 
** Started on  Sun Jan  4 11:59:19 2015 kerebe_p
** Last update Sun Jan  4 11:59:19 2015 kerebe_p
*/

#include "include/my.h"

void	cpy_half(char *av, char *h)
{
  int	i;
  int	z;

  i = 0;
  z = 0;
  while (av[i] != '(')
    {
      h[z] = av[i];
      i = i + 1;
      z = z + 1;
    }
}

int	len_f(char *av)
{
  int	i;

  i = 0;
  while (av[i] != '('  && av[i] != '\0')
    i = i + 1;
  return (i);
}

int	skip(char *av)
{
  int	i;

  i = 0;
  while (av[i] == ' ' || av[i] == ',' || av[i] == '(')
    i = i + 1;
  return (i);
}

void	disp_t(char type[11][10], char name[11][20], char *line)
{
  int	i;

  i = 0;
  while (type[i][0] != '\0')
    {
      if (check(type[i], line) == 1)
	printf("%s", name[i]);
      i = i + 1;
    }
}

int	disp_p(char type[11][10], char name[11][20], char *f)
{
  int	c;
  int	a;

  c = skip(f);
  a = d_var(type, name, &f[c], "prennant en parametre ");
  if (a < 0)
    return (-1);
  c = c + a;
  c = c + skip(&f[c]);
  while (c < my_strlen(&f[1]))
    {
      a = d_var(type, name, &f[c], ",");
      if (a < 0)
	return (-1);
      c = c + a;
      c = c + skip(&f[c]);
    }
  return (0);
}
