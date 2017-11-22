#ifndef MAP_H_
# define MAP_H_

#include "generic_list.h"

/* Types */

typedef struct  s_pair
{
    void        *key;
    void        *value;
}               t_pair;

typedef t_list t_map;

typedef int (*t_key_comparator)(void *first_key, void *second_key);

/* Informations */

unsigned int    map_get_size(t_map map);
t_bool          map_is_empty(t_map map);

/* Internals */

t_key_comparator    key_cmp_container(t_bool store, t_key_comparator new_key_cmp);
int     pair_comparator(void *first, void *second);

/* Modification */

t_bool  map_add_elem(t_map *map_ptr, void *key, void *value, t_key_comparator key_cmp);
t_bool  map_del_elem(t_map *map_ptr, void *key, t_key_comparator key_cmp);

/* Access */

void    *map_get_elem(t_map map, void *key, t_key_comparator key_cmp);

#endif /* !MAP_H_ */
