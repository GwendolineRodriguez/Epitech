/*
** opt_get.h for opt_get.h in /home/duclos_r/Tek-1/Colle/opt_get
** 
** Made by Rémi Duclos
** Login   <duclos_r@epitech.net>
** 
** Started on  Mon May 25 15:10:25 2015 Rémi Duclos
** Last update Mon May 25 18:23:35 2015 Rémi Duclos
*/

#ifndef OPT_GET_H_
# define OPT_GET_H_

# define NCMP(str, str2, size) (my_strncmp(str, str2, size) == 0)

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef int	t_bool;
typedef int	t_pos;

typedef	struct	s_opt
{
  char		*options;
  const char	**args;
  t_pos		pos;
  int		check;
  struct s_opt	*next;
  struct s_opt	*prev;
}		t_opt;

t_opt	*opt_get(int ac, char **av, const char *format);
void	parsing(int ac, char **av, t_opt *opt);
void	fill_list(t_opt *opt, char **av, int *cnt);
char	*get_word(const char *str);
int	double_dash(const char *format, t_opt *options);
int	count_line(const char **buffer);
t_opt	*create_list();
void	put_in_next(t_opt *i);
int	my_strcmp(char *s1, const char *s2);
int	my_strncmp(char *s1, char *s2, int size);
char	*my_strdup(char *str);

#endif /* endif */

