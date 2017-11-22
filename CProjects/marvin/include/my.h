/*
** my.h for lib in /home/kerebel/Documents/EPITECH/marvin
** 
** Made by kerebe_p
** Login   <kerebe_p@epitech.eu>
** 
** Started on  Sat Jan  3 12:53:13 2015 kerebe_p
** Last update Sat Jan  3 12:53:13 2015 kerebe_p
*/

#ifndef MY_H_
# define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	to_find(char *str, char *m);
void	check_var(char type[11][10], char *av, char *w);
int	check(char *type, char *str);
int	def_check(char type[11][10], char *av);
int	check_par(char *str);
int	check_bra(char *str);
int	checkpoint(char *str);
int	check_errors(char *str);
int	check_opt(char *av);
void	name_fill(char name[11][20]);
void	type_fill(char type[11][10]);
void	my_marvin(char type[11][10], char name[11][20], char *av);
void	my_putchar(char c);
int	my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *dest, char *src);
int	my_strlen(char *str);
void	cpy_half(char *av, char *h);
int	len_f(char *av);
int	skip(char *av);
void	disp_t(char type[11][10], char name[11][20], char *line);
int	disp_p(char type[11][10], char name[11][20], char *f);
int	d_var(char type[11][10], char name[11][20], char *av, char *str);
int	d_func(char type[11][10], char name[11][20], char *av, char *str);
int	check_index(char c);
int	check_for(char *str);

#endif
