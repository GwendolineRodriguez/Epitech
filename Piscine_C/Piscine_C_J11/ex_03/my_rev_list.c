/*
** my_rev_list.c for my_rev_list in /home/RODRIG_1/rendu/Piscine_C_J12/ex_03
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Tue Oct 21 17:54:56 2014 rodriguez gwendoline
** Last update Tue Oct 21 20:05:41 2014 rodriguez gwendoline
*/

#include <stdlib.h>
#include "./../include/mylist.h"

int             my_put_in_list(t_list **list, char *data)
{
  t_list        *elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem->data = data;
  elem->next = *list;
  *list = elem;
  return (0);
}

t_list          *my_params_in_list(int ac, char **av)
{
  int           i;
  t_list        *list;

  list = NULL;
  while (i <= (ac - 1))
    {
      my_put_in_list(&list, av[i]);
      i = i + 1;
    }
  my_show_list(my_rev_list(list));
  free(elem);
  return (list);
}

void             my_show_list(t_list *list)
{
  t_list        *tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->list);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

int     my_rev_list(t_list **begin)
{

}

int             main(int argc, char **argv)
{
  my_params_in_list(argc, argv);
}
