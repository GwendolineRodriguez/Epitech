/*
** main.c for main in /home/gwendoline/rendu/Piscine_Synthese/projTester
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jun 18 12:02:16 2015 
** Last update Sat Jun 20 22:16:19 2015 
*/

#include "header.h"

void            check_opt(char **av, char **env, t_param *p)
{
  int		i;

  i = 3;
  while (av[i] != NULL)
    {
      if (my_strcmp(av[i], "-o") == 0 && p->data->goodtest == 1
	  && av[i + 1] != NULL
	  && my_strcmp(av[i + 1], "-stats") != 0)
	{
	  p->data->output = 1;
	  p->data->fileout = my_strdup(av[i + 1]);
	}
      else if (my_strcmp(av[i], "-stats") == 0 && p->data->goodtest == 1)
	p->data->stats = 1;
      else if (my_strcmp(av[i - 1], "-o") != 0)
	put_error("! Fichier mal formaté !\n");
      i++;
    }
}

void		projTester(char **av, char **env, t_param *p)
{
  int		fd;

  if ((fd = open(av[2], O_RDONLY)) > 0)
    p->data->goodtest = 1;
  else
    put_error("! Fichier mal formaté !\n");
  get_list(av, p, fd);
  check_opt(av, env, p);
  test_args(p, fd);
  if (p->data->stats == 1)
    put_stats(p);
}

int		main(int ac, char **av, char **env)
{
  t_param	*p;

  p = init_param();
  if (ac > 2)
    {
      p->bin = my_strdup(av[1]);
      projTester(av, env, p);
    }
  else
    put_error("! Fichier mal formaté !\n");
  return (0);
}
