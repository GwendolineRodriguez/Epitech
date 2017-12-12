#ifndef GENERIC_LIST_H_
# define GENERIC_LIST_H_

/*
** Types
*/

typedef enum e_bool
{
    FALSE,
    TRUE
}            t_bool;

typedef struct  s_node
{
    void            *value;
    struct s_node   *next;
}               t_node;

typedef t_node   *t_list;


/*
** Functions
*/

/* Informations */

unsigned int    list_get_size(t_list list);
t_bool          list_is_empty(t_list list);

typedef void    (*t_value_displayer)(void *value);

void            list_dump(t_list list, t_value_displayer val_disp);

/* Modification */

t_bool  list_add_elem_at_front(t_list *front_ptr, void *elem);
t_bool  list_add_elem_at_back(t_list *front_ptr, void *elem);
t_bool  list_add_elem_at_position(t_list *front_ptr, void *elem, unsigned int position);

t_bool  list_del_elem_at_front(t_list *front_ptr);
t_bool  list_del_elem_at_back(t_list *front_ptr);
t_bool  list_del_elem_at_position(t_list *front_ptr, unsigned int position);

void    list_clear(t_list *front_ptr);

/* Value Access */

void    *list_get_elem_at_front(t_list list);
void    *list_get_elem_at_back(t_list list);
void    *list_get_elem_at_position(t_list list, unsigned int position);

/* Node Access */

typedef int (*t_value_comparator)(void *first, void *second);

t_node  *list_get_first_node_with_value(t_list list, void *value, t_value_comparator val_comp);


#endif /* !GENERIC_LIST_H_ */
