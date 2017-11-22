/*
** opt_get.c for opt_get in /home/duclos_r/Tek-1/Colle/opt_get
** 
** Made by Rémi Duclos
** Login   <duclos_r@epitech.net>
** 
** Started on  Mon May 25 15:09:07 2015 Rémi Duclos
** Last update Mon May 25 20:51:26 2015 
*/

#include "opt_get.h"

t_opt	*opt_get(int ac, char **av, const char *format)
{
  t_opt	*opt;
  int	res;

  opt = create_list();
  opt->pos = -1;
  parsing(ac, av, opt);
  res = check_format(opt, format);
  if (res == -1)
    return (NULL);
  else
    return (opt);
}

void	parsing(int ac, char **av, t_opt *opt)
{
  t_opt	*tmp;
  int	cnt;

  cnt = 0;
  tmp = opt;
  while (cnt < ac)
    {
      if (NCMP(av[cnt], "-", 1) || NCMP(av[cnt], "--", 2))
	{
	  put_in_next(tmp);
	  tmp = tmp->next;
	  fill_list(tmp, av, &cnt);
	}
      else
	cnt++;
    }
}

void	fill_list(t_opt *opt, char **av, int *cnt)
{
  int	i;

  opt->options = my_strdup(av[(*cnt)]);
  i = ++(*cnt);
  while (av[i] != NULL && av[i][0] != '-')
    i++;
  opt->args = malloc(sizeof((*opt->args)) * (i - (*cnt) + 1));
  if (opt->args == NULL)
    exit(0);
  i = 0;
  while (av[(*cnt)] != NULL && av[(*cnt)][0] != '-')
    {
      opt->args[i] = my_strdup(av[(*cnt)]);
      i++;
      (*cnt)++;
    }
  opt->args[i] = NULL;
  opt->pos = opt->prev->pos + 1;
}

int	main(int ac, char **av)
{
  t_opt	*res;

  res = opt_get(ac, av, "--help -a -f");
}
