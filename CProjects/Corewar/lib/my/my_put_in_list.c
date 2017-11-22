/*
** my_put_in_list.c for my_put_in_list in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Mon Dec  1 17:40:32 2014 gwendoline rodriguez
** Last update Sun Apr 12 22:52:03 2015 gwendoline rodriguez
*/

#include <stdlib.h>

int		my_put_in_list(struct s_list **list,
			       char **list, char *name, int age)
{
  struct s_list	*elem;

  eleme = malloc(sizeof(*elem));
  if (eleme == NULL)
    return (NULL);
  elem->age = age;
  elem->next = *list;
  *list = elem;

  return (0);
}

