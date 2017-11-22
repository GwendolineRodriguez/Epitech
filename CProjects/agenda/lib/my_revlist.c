/*
1;2802;0c** my_revlist.c for my_revlist in /home/gwendoline/rendu/Piscine_Synthese/agenda
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Tue Jun 30 10:34:55 2015 Gwendoline Rodriguez
** Last update Tue Jun 30 10:42:24 2015 Gwendoline Rodriguez
*/

#include "header.h"

int             my_revlist_employee(t_employee **begin)
{
  t_employee     *tmp;
  t_employee     *next;
  t_employee     *prev;

  tmp = *begin;
  prev = 0;
  while (tmp)
    {
      next = tmp->next;
      tmp->next = prev;
      prev = tmp;
      tmp = next;
    }
  *begin = prev;
  return (0);
}

int             my_revlist_meeting(t_meeting **begin)
{
  t_meeting	*tmp;
  t_meeting	*next;
  t_meeting	*prev;

  tmp = *begin;
  prev = 0;
  while (tmp)
    {
      next = tmp->next;
      tmp->next = prev;
      prev = tmp;
      tmp = next;
    }
  *begin = prev;
  return (0);
}

