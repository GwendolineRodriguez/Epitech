/*
** simple_list.c for simple_list in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d02a/ex00
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jan  7 15:04:38 2016 Gwendoline Rodriguez
** Last update Thu Jan  7 19:58:16 2016 Gwendoline Rodriguez
*/

#include "simple_list.h"


t_node *list_create_node(double elem)
{
  t_node *node = malloc(sizeof(t_node));

  node->value = elem;
  node->next = NULL;
  return (node);
}

unsigned int list_get_size(t_list list)
{
  int	c;

  c = 0;
  while (list)
    {
      c++;
      list = list->next;
    }
  return (c);
}

t_bool list_is_empty(t_list list)
{
  if (!list)
    return (TRUE);
  return (FALSE);
}

void list_dump(t_list list)
{
  while (list)
    {
      printf("%f\n", list->value);
      list = list->next;
    }
}

t_bool list_add_elem_at_front(t_list *front_ptr, double elem)
{
  t_node *node = list_create_node(elem);

  if (!node) {
    return (FALSE);
  }
  node->next = *front_ptr;
  *front_ptr = node;
  return (TRUE);
}

t_bool list_add_elem_at_back(t_list *front_ptr, double elem)
{
  t_node *node = list_create_node(elem);
  t_list list = *front_ptr;

  if (!node)
    return (FALSE);
  if (!list)
    *front_ptr = node;
  else {
    list = *front_ptr;
    while (list->next) {
      list = list->next;
    }
    list->next = node;
  }
  return (TRUE);
}

t_bool list_add_elem_at_position(t_list * front_ptr, double elem,
				 unsigned int position)
{
  t_list list = *front_ptr;
  t_node *node = list_create_node(elem);

  if (!node)
    return FALSE;
  if (position == 0)
    return list_add_elem_at_front(front_ptr, elem);
  if (!*front_ptr)
    return FALSE;
  while (--position) {
    list = list->next;
    if (!list)
      return FALSE;
  }
  node->next = list->next;
  list->next = node;
  return TRUE;
}

t_bool list_del_elem_at_front(t_list *front_ptr)
{
  t_list list = *front_ptr;

  if (!list)
    return (FALSE);
  *front_ptr = list->next;
  free(list);
  return (TRUE);
}

t_bool list_del_elem_at_back(t_list *front_ptr)
{
  t_list list = *front_ptr;
  t_list previous = NULL;

  if (!list)
    return (FALSE);
  while (list->next) {
    previous = list;
    list = list->next;
  }
  if (previous)
    previous->next = NULL;
  else
    *front_ptr = NULL;
  free(list);
  return (TRUE);
}

t_bool list_del_elem_at_position(t_list *front_ptr, unsigned int position)
{
  if (position == 0) {
    printf("front\n");
    return list_del_elem_at_front(front_ptr);
  }
  t_list previous = *front_ptr;
  t_list list = previous->next;

  if (!*front_ptr)
    return (FALSE);
  while (--position) {
    if (!list) {
      return (FALSE);
    }
    previous = list;
    list = list->next;
  }
  if (list)
    previous->next = list->next;
  free(list);
  return (TRUE);
}

double list_get_elem_at_front(t_list list)
{
  if (!list)
    return (0);
  return (list->value);
}

double list_get_elem_at_back(t_list list)
{
  if (!list)
    return (0);
  while (list->next)
    list = list->next;
  return (list->value);
}

double list_get_elem_at_position(t_list list, unsigned int position)
{
  unsigned int	i;

  i = -1;
  if (!list)
    return (0);
  while (++i <= position) {
    list = list->next;
    if (!list)
      return (0);
  }
  return (list->value);
}

t_node *list_get_first_node_with_value(t_list list, double value)
{
  while (list) {
    if (list->value == value) {
      return (list);
    }
    list = list->next;
  }
  return (NULL);
}

/* int main(void) */
/* { */
/*   t_list list_head = NULL; */
/*   unsigned int size; */
/*   double i = 5.2; */
/*   double j = 42.5; */
/*   double k = 3.3; */

/*   list_add_elem_at_back(&list_head, i); */
/*   list_add_elem_at_back(&list_head, j); */
/*   list_add_elem_at_back(&list_head, k); */

/*   size = list_get_size(list_head); */
/*   printf("Il y a %u elements dans la liste\n", size); */
/*   list_dump(list_head); */

/*   //  list_del_elem_at_back(&list_head); */
/*   list_del_elem_at_position(&list_head, 0); */

/*   size = list_get_size(list_head); */
/*   printf("Il y a %u elements dans la liste\n", size); */
/*   list_dump(list_head); */
/*   return (0); */
/* } */
