#ifndef SIMPLE_BTREE_H_
# define SIMPLE_BTREE_H_

/*
** Types
*/

typedef enum	e_bool
  {
    FALSE,
    TRUE
  }		t_bool;

typedef struct	s_node
{
  double	value;
  struct s_node	*left;
  struct s_node	*right;
}		t_node;

typedef t_node	*t_tree;

/*
** Functions
*/

/* Informations */

t_bool		btree_is_empty(t_tree tree);

unsigned int	btree_get_size(t_tree tree);
unsigned int	btree_get_depth(t_tree tree);

/* Modifications */

t_bool	btree_create_node(t_tree *root_ptr, double value);
t_bool	btree_delete(t_tree *root_ptr);

/* Access */

double	btree_get_max_value(t_tree tree);
double	btree_get_min_value(t_tree tree);

#endif /* !SIMPLE_BTREE_H_ */

