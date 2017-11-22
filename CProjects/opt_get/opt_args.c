/*
** opt_args.c for opt_isset in /home/gwendoline/rendu/Prgelm/colles/opt_get/gwen
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Mon May 25 17:25:32 2015 
** Last update Mon May 25 19:48:49 2015 
*/

#include "opt_get.h"

const char	**opt_args(t_opt *options, const char *option)
{
  t_opt		*tmp;

  tmp = options->next;
  while (tmp != options)
    {
      if (my_strcmp(tmp->options, option) != 0)
	tmp = tmp->next;
      else
	return (tmp->args);
    }
  return (NULL);
}
