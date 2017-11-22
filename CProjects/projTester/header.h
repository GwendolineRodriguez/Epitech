/*
** header.h for header in /home/gwendoline/rendu/Piscine_Synthese
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jun 15 11:50:39 2015 
** Last update Wed Jan  6 15:26:49 2016 Gwendoline Rodriguez
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

typedef struct  s_list      t_list;

typedef struct	s_data
{
  int		goodbin;
  int		output;
  int		stats;
  int		goodtest;
  char		*fileout;
  int		check_res;
  int		check_entree;
  int		check_args;
  int		check_ok;
  int		check_ko;
  char		*input;
}		t_data;

struct		s_list
{
  char		**args;
  char		*type;
  char		*inputfile;
  char		*res;
  t_list	*next;
  t_list	*prev;
};

typedef struct	s_param
{
  char		*bin;
  t_list	*list;
  t_data	*data;
}		t_param;

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
t_param         *init_param();
void		check_opt(char **av, char **env, t_param *p);
void		test_args(t_param *p, int fd);
int             open_file(char **av, t_param *p, int fd);
char            **my_strtowordtab(char *str);
t_list		*create_elem();
void            put_in_next(t_list *list);
void            fill_list(t_param *p, char *line, t_list *tmp);
void            get_list(char **av, t_param *p, int fd);
void		put_stats(t_param *p);
void            call_son(t_param *p, int fd, int *pipefd, t_list *tmp);
void            call_father(t_param *p, int fd, int *pipefd, t_list *tmp);

#endif
