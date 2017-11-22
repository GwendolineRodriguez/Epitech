#ifndef STACK_H_
# define STACK_H_

# include "generic_list.h"

typedef t_list  t_stack;

/* informations */

unsigned int    stack_get_size(t_stack stack);
t_bool          stack_is_empty(t_stack stack);

/* Modification */

t_bool  stack_push(t_stack *stack_ptr, void *elem);
t_bool  stack_pop(t_stack *stack_ptr);

/* Access */

void    *stack_top(t_stack stack);

#endif /* !STACK_H_ */
