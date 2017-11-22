/*
** my_boogle.h for my_boogle in /home/duclos_r/Tek-1/Colle/boogle
** 
** Made by Rémi Duclos
** Login   <duclos_r@epitech.net>
** 
** Started on  Fri Jun  5 14:15:21 2015 Rémi Duclos
** Last update Fri Jun  5 19:40:05 2015 
*/

#ifndef BOOGLE_H_
# define BOOGLE_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

# define CMP(str1, str2) (str1 != NULL && str2 != NULL && my_strcmp(str1, str2) == 0)

typedef struct	s_boogle
{
  int		size;
  char		**grid;
  char		*word;
  int		**pos;
  int		color;
}		t_boogle;

int	my_strlen(char *str);
void	my_putstr(char *str);
int	check_errors(t_boogle *boogle, char *grid);
void	my_putchar(char c);
void	parsing(int ac, char **av, t_boogle *boogle);
void	game(t_boogle *boogle);
void	*get_first(t_boogle *boogle, int first);
int	check_arourd(t_boogle *boogle, int pos);
int	conditions(t_boogle *boogle, int pos);
int	my_strcmp(char *s1, char *s2);
void	my_error(char *str);
int	my_getnbr(char *str);
char	*get_grid_str(char *src, char *dest);

#endif /* BOOGLE_H_ */
