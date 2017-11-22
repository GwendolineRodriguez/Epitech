/*
** list.c for opt_get in /home/duclos_r/Tek-1/Colle/opt_get
** 
** Made by Rémi Duclos
** Login   <duclos_r@epitech.net>
** 
** Started on  Mon May 25 15:49:04 2015 Rémi Duclos
** Last update Mon May 25 16:04:31 2015 Rémi Duclos
*/

#include "opt_get.h"

t_opt	*create_list()
{
  t_opt	*root;

  root = malloc(sizeof(*root));
  if (root == NULL)
    exit(0);
  root->next = root;
  root->prev = root;
  return (root);
}

void	put_in_next(t_opt *i)
{
  t_opt	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    exit(0);
  i->next->prev = new;
  new->next = i->next;
  i->next = new;
  new->prev = i;
}
