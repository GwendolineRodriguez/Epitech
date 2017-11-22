/*
** double_dash.c for double_dash in /home/gwendoline/rendu/Prgelm/colles/opt_get/tmp
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Mon May 25 19:03:50 2015 
** Last update Mon May 25 18:53:17 2015 Rémi Duclos
*/

#include "opt_get.h"

int		double_dash(const char *format, t_opt *opt)
{
  t_opt		*tmp;
  char		*option;
  int		args;

  args = 0;
  option = get_word(format);
  tmp = opt->next;
  while (tmp != opt)
    {
      if (my_strcmp(tmp->options, option) != 0)
	tmp = tmp->next;
      else
	{
	  args = count_args(format);
	  if (args == count_line(tmp->args))
	    {
	      tmp->check = 1;
	      return (0);
	    }
	  else
	    return (-1);
	}
    }
  return (-1);
}

int		count_line(const char **buffer)
{
  int		i;

  i = 0;
  while (buffer[i++] != NULL);
  return (--i);
}
