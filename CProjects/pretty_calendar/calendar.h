/*
** calendar.h for calendar in /home/duclos_r/Tek-1/Colle/pretty_calendar
** 
** Made by Rémi Duclos
** Login   <duclos_r@epitech.net>
** 
** Started on  Tue Jun  9 18:44:43 2015 Rémi Duclos
** Last update Tue Jun  9 21:32:30 2015 Rémi Duclos
*/

#ifndef	CALENDAR_H_
# define CALENDAR_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef	struct	s_calendar	t_calendar;

struct		s_calendar
{
  int		year;
  int		month;
  int		day;
  int		h_begin;
  int		h_end;
  char		*activity;
  t_calendar	*next;
  t_calendar	*prev;
};

void		parsing(char **av);
void		fill_list(t_calendar *cal, char *buffer);
int		get_nbr_sep(char *buffer, int *cnt);
char		*strdup_sep(char *buffer, int *cnt, char sep);
t_calendar	*create_list();
void		put_in_next(t_calendar *cal);
char		*get_alpha_nbr(int nb);
char		*get_alpha_month(int mon);
char		*my_strcpy(char *dest, char *src);
void		show_list(t_calendar *cal);
void		my_putchar(char c);
void		my_putstr(char *str);
void		my_putnbr(int nb);

#endif /* CALENDAR_H_ */
