/*
** main.c for main in /home/gwendoline/rendu/Prgelm/colles/master_mind/gwen
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Thu May 21 14:40:28 2015 
** Last update Thu May 21 15:25:35 2015 
*/

#include "header.h"

void		get_init_pions(t_dat *data)
{
  int		i;
  int		c;

  i = 0;
  c = 48;
  while (i <= 7)
    {
      data.pions[i] = c;
      i++;
      c++;
    }
  data.pions[i] == '\0';
}

void		init_data(t_dat *data)
{
  if (data.code = malloc(5 * sizeof(char)) != 0)
    my_error("Error on code malloc\n");
  get_random_code(&data);
  if (data.pions = malloc(9 * sizeof(char)) != 0)
    my_error("Error on pion malloc\n");
  get_init_pions(&data);
  data.nb_tent = 10;
  data.code_len = 4;
}

int		parse_opt(char **av)
{
  int		i;
  t_dat		data;

  i = 0;
  data = init_data(&data);
  while (av[i] != NULL)
    {
      if (av[i][0] == '-')
	{
	  if (av[i][1] == 'c')
	    get_code(av[i + 1], &data);
	  else if (av[i][1] == 'p')
	    get_pions(av[i + 1], &data);
	  else if (av[i][1] == 't')
	    get_tentativ(av[i + 1], &data);
	  else if (av[i][1] == 's')
	    get_slots(av[i + 1], &data);
	}
      i++;
    }
  return (0);
}

int		main(int ac, char **av)
{
  if (ac > 1 && av <= 8)
    parse_opt(av);
  else
    my_error("./my_masternmind -c [CODE] -p [PIONS] -t [tentatives] -s [SLOTS]\n");
}
