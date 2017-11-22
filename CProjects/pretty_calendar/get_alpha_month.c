/*
** get_alpha_month.c for get_alpha_month in /home/gwendoline/rendu/Prgelm/colles/pretty_calendar/gwen
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Tue Jun  9 22:23:13 2015 
** Last update Tue Jun  9 22:57:55 2015 
*/

#include "calendar.h"

char            *get_alpha_month2(int mon)
{
  char          *alpha;

  if (mon == 10)
    alpha = my_strcpy(alpha, "novembre");
  else if (mon == 11)
    alpha = my_strcpy(alpha, "décembre");
  else
    alpha = NULL;
}

char		*get_alpha_month(int mon)
{
  char		*alpha;

  if (mon == 0)
    alpha = my_strcpy(alpha, "janvier");
  else if (mon == 1)
    alpha = my_strcpy(alpha, "février");
  else if (mon == 2)
    alpha = my_strcpy(alpha, "mars");
  else if (mon == 3)
    alpha = my_strcpy(alpha, "avril");
  else if (mon == 4)
    alpha = my_strcpy(alpha, "mai");
  else if (mon == 5)
    alpha = my_strcpy(alpha, "juin");
  else if (mon == 6)
    alpha = my_strcpy(alpha, "juillet");
  else if (mon == 7)
    alpha = my_strcpy(alpha, "août");
  else if (mon == 8)
    alpha = my_strcpy(alpha, "septembre");
  else if (mon == 9)
    alpha = my_strcpy(alpha, "octobre");
  else
    alpha = get_alpha_month2(mon);
  return (alpha);
}
