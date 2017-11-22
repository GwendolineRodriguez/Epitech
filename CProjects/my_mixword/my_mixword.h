/*
** my_mixword.h for my_mixword in /home/duclos_r/Tek-1/Colle/my_mixword
** 
** Made by Rémi Duclos
** Login   <duclos_r@epitech.net>
** 
** Started on  Wed Jun 10 09:21:10 2015 Rémi Duclos
** Last update Wed Jun 10 14:41:57 2015 
*/

#ifndef MY_MIXWORD_H_
# define MY_MIXWORD_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define DIAG_UP_LEFT 5
#define DIAG_DOWN_LEFT 6
#define DIAG_UP_RIGHT 7
#define DIAG_DOWN_RIGHT 8

typedef	struct	s_grid
{
  char		**grid;
  char		**color;
  char		*word;
  int		size;
  int		pos_x;
  int		pos_y;
  int		way;
}		t_grid;

int     my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
char	*my_strdup(char *src);
void	get_grid(char *file, t_grid *grid);
void	fill_grid(char **wordtab, t_grid *grid);
char	**str_to_wordtab(char *line, char sep);
void	show_tab(char **buffer);
int	my_getnbr(char *str);
void	my_putchar(char c);
void	my_putstr(char *str);
int	check_h(t_grid *p);
int	check_v(t_grid *p);
int	check_hrev(t_grid *p);
int	check_vrev(t_grid *p);
int	check_diag_up_right(t_grid *p);
int	check_diag_up_left(t_grid *p);
int	check_diag_down_right(t_grid *p);
int	check_diag_down_left(t_grid *p);
void	my_error(char *str);
int	reader(t_grid *p);
char	*parsing(int ac, char **av, t_grid *grid);

#endif /* MY_MIXWORD_H_ */
