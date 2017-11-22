/*
** type_str.c for type mode in /home/kerebel/Documents/EPITECH/marvin
** 
** Made by kerebe_p
** Login   <kerebe_p@epitech.eu>
** 
** Started on  Sat Jan  3 15:32:25 2015 kerebe_p
** Last update Sat Jan  3 15:32:25 2015 kerebe_p
*/

#include "include/my.h"

int	d_var(char type[11][10], char name[11][20], char *av, char *str)
{
  int	i;

  i = 0;
  if (def_check(type, av) <= 0)
    return (-1);
  check_var(type, av, str);
  while (type[i][0] != '\0')
    {
      if (check(type[i], av) == 1)
	printf("%s", name[i]);
      i = i + 1;
    }
  i = def_check(type, av);
  while (def_check(type, &av[i]) > 0)
    i = i + def_check(type, &av[i]);
  printf(" nommé ");
  while (av[i] == '*' || av[i] == '[' || av[i] == ']'
	 || av[i] == ' ' || av[i] == ',')
    i = i + 1;
  while (av[i] != ';' && av[i] != '\0' && av[i] != ' '
	 && av[i] != '[' && av[i] != '*' && av[i] != ')' && av[i] != ',')
    printf("%c", av[i++]);
  if (my_strcmp("Declaration d'", str) == 0)
    printf(".");
  return (i);
}

int	d_func(char type[11][10], char name[11][20], char *av, char *str)
{
  char	*h;
  char	*f;
  int	c;

  if (def_check(type, av) <= 0)
    return (-1);
  c = len_f(av);
  h = malloc(sizeof(char) * c);
  f = malloc(sizeof(char) * my_strlen(&av[c]));
  if (f == NULL || h == NULL)
    return (-1);
  cpy_half(av, h);
  my_strcpy(f, &av[c]);
  printf("%s%s ", str, &h[def_check(type, h)]);
  disp_p(type, name, f);
  check_var(type, h, " et renvoyant ");
  disp_t(type, name, h);
  free(h);
  free(f);
  printf(".");
  return (0);
}
