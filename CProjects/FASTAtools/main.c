/*
** main.c for main in /home/gwendoline/rendu/Piscine_Synthese/FASTAtools
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Wed Jun 24 12:11:23 2015 
** Last update Thu Jun 25 19:53:08 2015 
*/

#include "header.h"

void		check_seq(char *str)
{
  int		i;
  int		cnt;

  i = 0;
  cnt = 0;
  while (str[i] != 0)
    {
      if (str[i] == '>')
	cnt++;
      i++;
    }
  if (cnt != 2)
    put_error("Le fichier doit contenir exactement 2 séquences.\n");
  display_align(str);
}

void		get_str(t_param *p)
{
  int		rd;

  if ((rd = read(0, p->buffer, BUFF_MAX)) == -1)
    put_error("ERROR: file is empty\n");
  p->buffer[rd] = '\0';
}

int		main(int ac, char **av)
{
  t_param	*p;

  p = init_param();
  if (ac > 1)
    {
      get_str(p);
      if (atoi(av[1]) == 1)
	display_simple(p->buffer);
      else if (atoi(av[1]) == 2)
	display_arn(p->buffer);
      else if (atoi(av[1]) == 3)
        display_reverse(p->buffer);
      else if (atoi(av[1]) == 4 && av[2] != NULL)
        display_k_mers(p->buffer, atoi(av[2]));
      else if (atoi(av[1]) == 7)
	check_seq(p->buffer);
    }
  else
    put_error("Usage : ./FASTAtools option [k]\n");
  return (0);
}
