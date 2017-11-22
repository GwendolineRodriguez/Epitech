/*
** header.h for header in /home/gwendoline/rendu/Piscine_Synthese
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jun 15 11:50:39 2015 Gwendoline Rodriguez
** Last update Sat Jul  4 18:13:06 2015 Gwendoline Rodriguez
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
#include <dirent.h>
#include <time.h>

#define COUNT 1
#define BUFF_MAX 10000
#define UNUSED __attribute__((unused))

typedef struct	s_individu
{
  char		*option;
  char		*name;
  char		*file;
  char		*rep;
  char		*inode;
  char		*dep;
  char		*gender;
  char		*secu;
  char		*family;
  char		*day;
  char		*mon;
  char		*monletter;
  char		*year;
  char		*cv;
}		t_individu;

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
t_individu	*init_param();
int             my_files(char *str);
char		*strdup(const char *s);
void		get_genealogy(t_individu *id);
t_individu	*get_info(t_individu *id);
void            display_info(t_individu *id);
char            *put_lower(char *str);
int             len_tab(char **tab);
void            get_good_tab(char **tab, char **tabd, char *str);
char            **get_tabd(char **tab, char *str);

#endif
