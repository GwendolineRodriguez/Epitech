/*
** parsing.c for my_mixword in /home/duclos_r/Tek-1/Colle/my_mixword
** 
** Made by Rémi Duclos
** Login   <duclos_r@epitech.net>
** 
** Started on  Wed Jun 10 11:01:53 2015 Rémi Duclos
** Last update Wed Jun 10 15:01:46 2015 
*/

#include "my_mixword.h"

char	*parsing(int ac, char **av, t_grid *grid)
{
  char	*file;
  int	cnt;

  cnt = 0;
  grid->size = -1;
  while (cnt < ac)
    {
      if (my_strcmp(av[cnt], "-f") == 1 && av[cnt + 1] != NULL)
	file = my_strdup(av[cnt + 1]);
      else if (my_strcmp(av[cnt], "-s") == 1 && av[cnt + 1] != NULL)
	grid->size = my_getnbr(av[cnt + 1]);
      cnt++;
    }
  if (grid->size == -1)
    grid->size = 8;
  return (file);
}

int	is_num(char *str)
{
  int	cnt;

  cnt = 0;
  while (str[cnt] != '\0')
    {
      if (str[cnt] < '0' || str[cnt] > '9')
	return (0);
      cnt++;
    }
  return (1);
}

int	my_getnbr(char *str)
{
  int	nb;
  int	cnt;

  nb = 0;
  cnt = 0;
  if (is_num(str) == 0)
    {
      write(2, "Size can't be negative\n", 23);
      exit(0);
    }
  while (str[cnt] != '\0')
    nb = (nb * 10) + (str[cnt++] - '0');
  return (nb);
}
