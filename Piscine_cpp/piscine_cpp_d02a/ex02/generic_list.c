/*
** generic_list.c for generic_list in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d02a/ex02
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jan  7 20:00:09 2016 Gwendoline Rodriguez
** Last update Thu Jan  7 20:32:16 2016 Gwendoline Rodriguez
*/

unsigned int list_get_size(t_list list)
{

}

t_bool list_is_empty(t_list list)
{

}

t_bool list_add_elem_at_front(t_list *front_ptr, void *elem)
{

}

t_bool list_add_elem_at_back(t_list *front_ptr, void *elem)
{

}

t_bool list_add_elem_at_position(t_list *front_ptr, void *elem,
				 7 unsigned int position)
{

}

t_bool list_del_elem_at_front(t_list *front_ptr)
{

}

t_bool list_del_elem_at_back(t_list *front_ptr)
{
}

t_bool list_del_elem_at_position(t_list *front_ptr,
				 unsigned int position)
{

}

void list_clear(t_list *front_ptr)
{
}

void *list_get_elem_at_front(t_list list)
{
}

void *list_get_elem_at_back(t_list list)
{
}

void *list_get_elem_at_position(t_list list, unsigned int position)
{
}

typedef void (*t_value_displayer)(void *value);
void list_dump(t_list list, t_value_displayer val_disp)
{

}

typedef int (*t_value_comparator)(void *first, void *second);
t_node *list_get_first_node_with_value(t_list list, void *value,
				       t_value_comparator val_comp)
{

}

void int_displayer(void *data)
{
  int value;
  value = *((int *)data);
  printf(‘‘%d\n’’, value);
}

int int_comparator(void *first, void *second)
{
  int val1;
  int val2;

  val1 = *((int *)first);
  val2 = *((int *)second);
  return (val1 - val2);
}

int main(void)
{
  t_list list_head = NULL;
  unsigned int size;
  int i = 5;
  int j = 42;
  int k = 3;

  list_add_elem_at_back(&list_head, &i);
  list_add_elem_at_back(&list_head, &j);
  list_add_elem_at_back(&list_head, &k);

  size = list_get_size(list_head);
  printf("Il y a %u elements dans la liste\n", size);
  list_dump(list_head, &int_displayer);

  list_del_elem_at_back(&list_head);

  size = list_get_size(list_head);
  printf("Il y a %u elements dans la liste\n", size);
  list_dump(list_head, &int_displayer);

  return (0);
}
