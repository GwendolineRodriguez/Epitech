/*
** prerequis.c for prerequis in /home/gwendoline/rendu/Piscine_Synthese/agenda
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jun 29 09:11:11 2015 Gwendoline Rodriguez
** Last update Wed Jul  1 16:52:05 2015 Gwendoline Rodriguez
*/

#include "header.h"

typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
}		t_list;

int		my_revlist_synthese(t_list **begin)
{
  t_list	*tmp;
  t_list	*next;
  t_list	*prev;

  tmp = *begin;
  prev = 0;
  while (tmp)
    {
      next = tmp->next;
      tmp->next = prev;
      prev = tmp;
      tmp = next;
    }
  *begin = prev;
  return (0);
}

t_list		*my_findnodeeqinlist_synthese(t_list *begin, void *data_ref,
					      int (*cmp)(void*, void*))
{
  t_list		*tmp;

  tmp = begin;
  while (tmp)
    {
      if ((*cmp)(data_ref, tmp->data) == 0)
	return(tmp);
      tmp = tmp->next;
    }
  return (NULL);
}
