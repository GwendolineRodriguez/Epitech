/*
** header.h for header in /home/gwendoline/rendu/Piscine_Synthese
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jun 15 11:50:39 2015 Gwendoline Rodriguez
** Last update Wed Jul  1 19:50:26 2015 Gwendoline Rodriguez
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

typedef struct  s_employee     t_employee;
typedef struct  s_meeting      t_meeting;

struct          s_employee
{
  char          *id;
  char		*name;
  char		*forename;
  char		*job;
  char		*zip;
  char		*names;
  char		**day;
  char		**zipmeet;
  char		***meeting;
  int		y;
  int		i;
  int		j;
  t_employee    *next;
};

struct		s_meeting
{
  char		*id;
  char		*day;
  char		*zip;
  char		*ids[50];
  char		**names;
  t_meeting     *next;
};

void            my_putchar(char c);
int             my_strlen(char *str);
void            my_putstr(char *str);
void            put_error(char *str);
void            my_putnbr(int nb);
int             my_strcmp(char *s1, char *s2);
int             my_strncmp(char *s1, char *s2, int n);
char            *my_strdup(char *src);
char            *my_strncpy(char *dest, char *src, int n);
char            *get_next_line(const int fd);
void	        setup_agenda(t_employee *employee, t_meeting *meeting, int fd);
t_employee      *init_param_employee(t_employee *employee);
t_meeting       *init_param_meeting(t_meeting *meeting);
t_employee      *get_list_employee();
t_meeting       *get_list_meeting();
void		show_agenda(t_employee *employee, t_meeting *meeting);
char		**my_strtowordtab(char *str);
t_employee      *create_employee();
t_meeting       *create_meeting();
void            display_meeting(t_meeting *meeting, int i);
void            display_employee(t_employee *employee);
void            add_employee(t_employee *employee, char **tab);
void            add_meeting(t_meeting *meeting, char **tab);
t_employee      *get_list_employee(t_employee *employee, int fd);
t_meeting       *get_list_meeting(t_meeting *meeting, int fd);
t_meeting       *update_names(t_meeting *meeting, t_employee *employee, int i);
t_employee      *update_listem(t_employee *employee, t_meeting *meeting);
t_meeting       *update_meeting(t_meeting *meeting, int fd);
int             is_intab(char *str, char **tab);
int             len_tab(char **tab);
char            *rev_word(char *str);

#endif
