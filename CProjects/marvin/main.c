/*
** main.c for marvin in /home/kerebel/Documents/EPITECH/marvin
** 
** Made by kerebe_p
** Login   <kerebe_p@epitech.eu>
** 
** Started on  Fri Jan  2 20:31:51 2015 kerebe_p
** Last update Fri Jan  2 20:31:51 2015 kerebe_p
*/

#include "include/my.h"

int	check_opt(char *av)
{
  int	i;

  i = 0;
  while (av[i] != '\0')
    {
      if (av[i] == '(')
	return (1);
      i = i + 1;
    }
  return (0);
}

void	name_fill(char name[11][20])
{
  my_strcpy(name[0], " caractere");
  my_strcpy(name[1], " entier");
  my_strcpy(name[2], " statique");
  my_strcpy(name[3], " void");
  my_strcpy(name[4], " flottant");
  my_strcpy(name[5], " flottant double");
  my_strcpy(name[6], " court");
  my_strcpy(name[7], " non signe");
  my_strcpy(name[8], " signe");
  my_strcpy(name[9], " long");
  my_strcpy(name[10], " constante");
  name[11][0] = '\0';
}

void	type_fill(char type[11][10])
{
  my_strcpy(type[0], "char ");
  my_strcpy(type[1], "int ");
  my_strcpy(type[2], "static ");
  my_strcpy(type[3], "void ");
  my_strcpy(type[4], "float ");
  my_strcpy(type[5], "double ");
  my_strcpy(type[6], "short ");
  my_strcpy(type[7], "unsigned ");
  my_strcpy(type[8], "signed ");
  my_strcpy(type[9], "long ");
  my_strcpy(type[10], "const ");
  type[11][0] = '\0';
}

void	my_marvin(char type[11][10], char name[11][20], char *av)
{
  int	opt;
  int	out;

  opt = check_opt(av);
  if (opt == 1)
    out = d_func(type, name, av, "Declaration de la fonction ");
  else
    out = d_var(type, name, av, "Declaration d'");
  if (out <= 0)
    printf("Invalid line, no matching found!");
}

int	main(int ac, char **av)
{
  char	type[11][10];
  char	name[11][20];

  if (ac == 1 || av[1][0] == '\0')
    {
      printf("No argument or void string!\n");
      return (-1);
    }
  if (check_errors(av[1]) < 0)
      return (-1);
  name_fill(name);
  type_fill(type);
  my_marvin(type, name, av[1]);
  printf("\n");
  return (0);
}
