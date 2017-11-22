/*
** list.c for pretty_calendar in /home/duclos_r/Tek-1/Colle/pretty_calendar
** 
** Made by Rémi Duclos
** Login   <duclos_r@epitech.net>
** 
** Started on  Tue Jun  9 20:01:32 2015 Rémi Duclos
** Last update Tue Jun  9 20:10:04 2015 Rémi Duclos
*/

#include "calendar.h"

t_calendar	*create_list()
{
  t_calendar	*cal;

  cal = malloc(sizeof(*cal));
  if (cal == NULL)
    exit(0);
  cal->next = cal;
  cal->prev = cal;
}

void		put_in_next(t_calendar *cal)
{
  t_calendar	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    exit(0);
  cal->next->prev = new;
  new->next = cal->next;
  cal->next = new;
  new->prev = cal;
}
