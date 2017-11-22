/*
1;2802;0c** parsing.c for parsing in /home/gwendoline/rendu/Prgelm/colles/boogle/gwen
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jun  5 16:43:16 2015 
** Last update Fri Jun  5 20:02:41 2015 
*/

#include "my_boogle.h"

void		my_error(char *str)
{
  write(1, str, my_strlen(str));
  exit(0);
}

void		init_boogle(t_boogle *boogle)
{
  boogle->size = 4;
  boogle->grid = NULL;
  boogle->word = NULL;
  boogle->pos = NULL;
  boogle->color = 0;
}

void		init_grid(t_boogle *boogle)
{
  int		i;

  i = 0;
  boogle->grid = malloc((sizeof(char*) * boogle->size) + 1);
  if (boogle->grid == NULL)
    my_error("Error on malloc.\n");
  while (i < boogle->size)
    {
      boogle->grid[i] = malloc((sizeof(char) * boogle->size) + 1);
      if (boogle->grid[i] == NULL)
	my_error("Error on malloc.\n");
      i++;
    }
  boogle->grid[i] = NULL;
}

void		get_grid(char *str, t_boogle *boogle)
{
  int		i;
  int		j;
  int		cpt;

  i = 0;
  j = 0;
  cpt = 0;
  init_grid(boogle);
  while (boogle->grid[i] != NULL)
    {
      cpt = 0;
      while (cpt < boogle->size)
	{
	  boogle->grid[i][cpt] = str[j];
	  j++;
	  cpt++;
	}
      boogle->grid[i][cpt] = '\0';
      i++;
    }
}

void		parsing(int ac, char **av, t_boogle *boogle)
{
  int		i;
  char		*grid;

  i = 1;
  init_boogle(boogle);
  if (ac > 1)
    {
      while (av[i] != NULL)
	{
	  if (CMP(av[i],"-s") && av[i + 1] != NULL)
	    boogle->size = my_getnbr(av[i + 1]);
	  else if (CMP(av[i], "-g") && av[i + 1] != NULL)
	    {
	      get_grid(av[i + 1], boogle);
	      grid = get_grid_str(av[i + 1], grid);
	    }
	  else if (CMP(av[i], "-w") && av[i + 1] != NULL)
	    boogle->word = av[i + 1];
	  else if (CMP(av[i], "--color"))
	    boogle->color = 1;
	  i++;
	}
    }
  check_errors(boogle, grid);
}
