/*
** Pushswap.c for Pushswap in /home/rodrig_1/rendu/Prgelm/CPE_2014_Pushswap
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Mon Dec  1 13:59:29 2014 gwendoline rodriguez
** Last update Mon Dec  8 11:28:38 2014 gwendoline rodriguez
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"

int             my_put_in_list(t_list **list, int nb)
{
  t_list	*elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem->nb = nb;
  elem->next = *list;
  *list = elem;
  return (0);
}

t_list		*my_params_in_list(int ac, char **av)
{
  int		i;
  t_list	*list;

  i = 1;
  list = NULL;
  while (my_getnbr(av[i]) > my_getnbr(av[i + 1]))
    {
      my_swap(my_getnbr(av[i]), my_getnbr(av[i + 1]));
      i = i + 1;
    }
  i = 1;
  while (i < ac)
    {
      my_put_in_list(&list, my_getnbr(av[i]));
      i = i + 1;
    }
  return (list);
}

void            show_list(struct s_list *list)
{
  struct s_list *tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putnbr(tmp->nb);
      my_putchar(' ');
      tmp = tmp->next;
    }
  my_putchar('\n');
}

int		main(int ac, char **av)
{
  show_list(my_params_in_list(ac, av));
}
