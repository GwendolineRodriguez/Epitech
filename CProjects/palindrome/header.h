/*
** header.h for header in /home/gwendoline/rendu/Piscine_Synthese
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jun 15 11:50:39 2015 
** Last update Sat Jun 27 16:02:22 2015 Gwendoline Rodriguez
*/

#ifndef HEADER_H_
#define HEADER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define COUNT 1
#define BUFF_MAX 10000
#define UNUSED __attribute__((unused))

typedef struct  s_param
{
  char          *c1;
  char		*c2;
  char		*nbchar;
  char		*revchar;
  char		*base;
  int		n;
  int		save;
  int		b;
  int		rev;
  int		it;
  char		*itopmin;
  char		*itopmax;
  int		itmax;
  int		itmin;
  int		check;
  int		reverse;
  int		check_pass;
}               t_param;

void            my_putchar(char c);
int             my_strlen(char *str);
void            my_putstr(char *str);
void            put_error(char *str);
void            my_putnbr(int nb);
int             my_strcmp(char *s1, char *s2);
int             my_strncmp(char *s1, char *s2, int n);
char		*my_strdup(char *src);
char            *my_strncpy(char *dest, char *src, int n);
char            *get_next_line(const int fd);
void		put_revstr(char *str);
t_param		*init_param();
int		show_palindrome(t_param *p);
char		*convert_base(char *nbr, char *base_from, char *base_to);
char		*get_charbase(int nb);
void            get_opt(char **av, t_param *p);

#endif
