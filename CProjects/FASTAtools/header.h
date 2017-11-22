/*
** header.h for header in /home/gwendoline/rendu/Piscine_Synthese
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jun 15 11:50:39 2015 
** Last update Fri Jun 26 01:19:06 2015 
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

/* typedef struct  s_list      t_list; */

/* struct		s_list */
/* { */
/*   char		*k_mer; */
/*   t_list	*next; */
/*   t_list	*prev; */
/* }; */

typedef struct	s_param
{
  char		*file;
  char		buffer[BUFF_MAX + 1];
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
int		len_tab(char **tab);
void		put_revstr(char *str);
char		get_char_comp(char c);
t_param         *init_param();
char		*get_epur_str(char *str, int i, int j);
void		display_simple(char *str);
void		display_arn(char *str);
void		display_reverse(char *str);
void            display_k_mers(char *str, int k);
void		display_align(char *str);
/* void		check_opt(char **av, char **env, t_param *p); */
/* void		test_args(t_param *p, int fd); */
/* int             open_file(char **av, t_param *p, int fd); */
/* char            **my_strtowordtab(char *str); */
/* t_list		*create_elem(); */
/* void            put_in_next(t_list *list); */
/* void            fill_list(t_param *p, char *line, t_list *tmp); */
/* void            get_list(char **av, t_param *p, int fd); */
/* void		put_stats(t_param *p); */
/* void            call_son(t_param *p, int fd, int *pipefd, t_list *tmp); */
/* void            call_father(t_param *p, int fd, int *pipefd, t_list *tmp); */

#endif
