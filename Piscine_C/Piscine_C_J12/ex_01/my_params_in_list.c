/*
** my_params_in_list.c for my_params_in_list in /home/RODRIG_1/rendu/Piscine_C_J12/ex_01
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Tue Oct 21 11:01:11 2014 rodriguez gwendoline
** Last update Wed Dec  3 13:33:43 2014 gwendoline rodriguez
*/

#include <stdlib.h>
#include "./../include/mylist.h"

int		my_put_in_list(t_list **list, char *data)
{
  t_list	*elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem->data = data;
  elem->next = *list;
  *list = elem;
  return (0);
}

t_list		*my_params_in_list(int ac, char **av)
{
  int		i;
  t_list	*list;

  i = 0;
  list = NULL;
  while (i <= (ac - 1))
    {
      my_put_in_list(&list, av[i]);
      i = i + 1;
    }
  return (list);
}

int		main(int ac ,char **av)
{
  my_show_list(my_params_in_list(ac, av));
}
