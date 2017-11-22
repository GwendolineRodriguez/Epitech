#ifndef QUEUE_H_
# define QUEUE_H_

# include "generic_list.h"

typedef t_list  t_queue;

/* informations */

unsigned int    queue_get_size(t_queue queue);
t_bool          queue_is_empty(t_queue queue);

/* Modification */

t_bool  queue_push(t_queue *queue_ptr, void *elem);
t_bool  queue_pop(t_queue *queue_ptr);

/* Access */

void    *queue_front(t_queue queue);

#endif /* !QUEUE_H_ */
