#ifndef SIMPLE_LIST_H_
# define SIMPLE_LIST_H_

/*
** Includes
*/

#include <stdio.h>
#include <stdlib.h>

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
    double          value;
    struct s_node   *next;
}               t_node;

typedef t_node   *t_list;


/*
** Functions
*/

/* Informations */

unsigned int    list_get_size(t_list list);
t_bool          list_is_empty(t_list list);
void            list_dump(t_list list);

/* Modification */

t_bool  list_add_elem_at_front(t_list *front_ptr, double elem);
t_bool  list_add_elem_at_back(t_list *front_ptr, double elem);
t_bool  list_add_elem_at_position(t_list *front_ptr, double elem, unsigned int position);

t_bool  list_del_elem_at_front(t_list *front_ptr);
t_bool  list_del_elem_at_back(t_list *front_ptr);
t_bool  list_del_elem_at_position(t_list *front_ptr, unsigned int position);

/* Value Access */

double   list_get_elem_at_front(t_list list);
double   list_get_elem_at_back(t_list list);
double   list_get_elem_at_position(t_list list, unsigned int position);

/* Node Access */

t_node  *list_get_first_node_with_value(t_list list, double value);


#endif /* !SIMPLE_LIST_H_ */
