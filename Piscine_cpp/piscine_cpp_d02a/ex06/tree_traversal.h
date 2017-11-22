#ifndef TREE_TRAVERSAL_H_
# define TREE_TRAVERSAL_H_

# include "generic_list.h"

/*
** Types
*/

/* Tree */

typedef struct	s_tree_node
{
  void			*data;
  struct s_tree_node	*parent;
  t_list		children;
}		t_tree_node;

typedef t_tree_node	*t_tree;

/* Misc */

typedef void	(*t_dump_func)(void *data);

/* Generic Container */

typedef t_bool	(*t_push_func)(void *container, void *data);
typedef void*	(*t_pop_func)(void *container);

typedef struct	s_container
{
  void		*container;
  t_push_func	push_func;
  t_pop_func	pop_func;
}		t_container;

/*
** Functions
*/

/* Informations */

t_bool	tree_is_empty(t_tree tree);
void	tree_node_dump(t_tree_node *tree_node, t_dump_func dump_func);

/* Modifications */

t_bool		init_tree(t_tree *tree_ptr, void *data);
t_tree_node	*tree_add_child(t_tree_node *tree_node, void *data);
t_bool		tree_destroy(t_tree* tree_ptr);

/* Access */

void	tree_traversal(t_tree tree, t_container *container, t_dump_func dump_func);

#endif /* !TREE_TRAVERSAL_H_ */

