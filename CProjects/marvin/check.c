/*
** check.c for check in /home/kerebel/Documents/EPITECH/marvin
** 
** Made by kerebe_p
** Login   <kerebe_p@epitech.eu>
** 
** Started on  Sat Jan  3 12:53:13 2015 kerebe_p
** Last update Sat Jan  3 12:53:13 2015 kerebe_p
*/

#include "include/my.h"

int	to_find(char *str, char *m)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  while (str[i] != '\0' && str[i] != ',')
    {
      if (my_strcmp(m, &str[i]) == 0)
	c = c + 1;
      i = i + 1;
    }
  return (c);
}

void	check_var(char type[11][10], char *av, char *w)
{
  int	s;
  int	z;

  s = def_check(type, av);
  z = to_find(av, "[]") + to_find(av, "*");
  while (def_check(type, &av[s]) > 0)
    s = s + def_check(type, &av[s]);
  printf("%s", w);
  while (z > 0)
    {
      printf("un pointeur sur ");
      z = z - 1;
    }
  if (z == 0)
    printf("une variable de type");
}

int	check(char *type, char *str)
{
  int	i;
  int	z;

  i = 0;
  z = 0;
  while (str[i] != '\0' && str[i] != ',')
    {
      z = 0;
      if ((i > 0 && str[i - 1] == ' ') || i == 0)
	{
	  while (str[i] == type[z] && str[i] != '\0')
	    {
	      z = z + 1;
	      i = i + 1;
	    }
	}
      if (type[z] == '\0')
	return (1);
      if (str[i] != '\0' && str[i] != ',')
	i = i + 1;
    }
  return (0);
}

int	def_check(char type[11][10], char *av)
{
  int	i;
  int	z;

  i = 0;
  z = 0;
  while (type[i][0] != '\0')
    {
      if (check(type[i], av) == 1)
	z = z + my_strlen(type[i]);
      i = i + 1;
    }
  return (z);
}
