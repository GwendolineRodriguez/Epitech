/*
** one_dash.c for opt_get in /home/duclos_r/Tek-1/Colle/opt_get/tmp
** 
** Made by Rémi Duclos
** Login   <duclos_r@epitech.net>
** 
** Started on  Mon May 25 17:12:00 2015 Rémi Duclos
** Last update Mon May 25 18:52:55 2015 Rémi Duclos
*/

#include "opt_get.h"

int	one_dash(const char *format, t_opt *opt)
{
  t_opt	*tmp;
  char	cmp;
  int	cnt;

  cmp = format[1];
  tmp = opt->next;
  while (tmp != opt)
    {
      cnt = 0;
      while (tmp->options[cnt] != '\0')
	{
	  if (tmp->options[cnt] == cmp
	      && count_args(format) == count_line(tmp->args))
	    {
	      tmp->check = 1;
	      return (0);
	    }
	  cnt++;
	}
      tmp = tmp->next;
    }
  return (-1);
}
