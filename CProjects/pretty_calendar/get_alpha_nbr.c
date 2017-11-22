/*
** get_alpha_nbr.c for get_alpha_nbr in /home/gwendoline/rendu/Prgelm/colles/pretty_calendar/gwen
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Tue Jun  9 21:29:09 2015 
** Last update Tue Jun  9 22:58:13 2015 
*/

#include "calendar.h"

char            *get_alpha_nbr3(int nb)
{
  char		*alpha;

  if (nb == 21)
    alpha = my_strcpy(alpha, "vingt et un");
  else if (nb == 22)
    alpha = my_strcpy(alpha, "vingt deux");
  else if (nb == 23)
    alpha = my_strcpy(alpha, "vingt trois");
  else if (nb == 24)
    alpha = my_strcpy(alpha, "vingt quatre");
  else if (nb == 25)
    alpha = my_strcpy(alpha, "vingt cinq");
  else if (nb == 26)
    alpha = my_strcpy(alpha, "vingt six");
  else if (nb == 27)
    alpha = my_strcpy(alpha, "vingt sept");
  else if (nb == 28)
    alpha = my_strcpy(alpha, "vingt huit");
  else if (nb == 29)
    alpha = my_strcpy(alpha, "vingt neuf");
  else if (nb == 30)
    alpha = my_strcpy(alpha, "trente");
  else if (nb == 31)
    alpha = my_strcpy(alpha, "trente et un");
  return (alpha);
}

char            *get_alpha_nbr2(int nb)
{
  char          *alpha;

  if (nb == 11)
    alpha = my_strcpy(alpha, "onze");
  else if (nb == 12)
    alpha = my_strcpy(alpha, "douze");
  else if (nb == 13)
    alpha = my_strcpy(alpha, "treize");
  else if (nb == 14)
    alpha = my_strcpy(alpha, "quatorze");
  else if (nb == 15)
    alpha = my_strcpy(alpha, "quinze");
  else if (nb == 16)
    alpha = my_strcpy(alpha, "seize");
  else if (nb == 17)
    alpha = my_strcpy(alpha, "dix-sept");
  else if (nb == 18)
    alpha = my_strcpy(alpha, "dix-huit");
  else if (nb == 19)
    alpha = my_strcpy(alpha, "dix-neuf");
  else if (nb == 20)
    alpha = my_strcpy(alpha, "vingt");
  else
    alpha = get_alpha_nbr3(nb);
  return (alpha);
}

char		*get_alpha_nbr(int nb)
{
  char		*alpha;

  if (nb == 1)
    alpha = my_strcpy(alpha, "premier");
  else if (nb == 2)
    alpha = my_strcpy(alpha, "deux");
  else if (nb == 3)
    alpha = my_strcpy(alpha, "trois");
  else if (nb == 4)
    alpha = my_strcpy(alpha, "quatre");
  else if (nb == 5)
    alpha = my_strcpy(alpha, "cinq");
  else if (nb == 6)
    alpha = my_strcpy(alpha, "six");
  else if (nb == 7)
    alpha = my_strcpy(alpha, "sept");
  else if (nb == 8)
    alpha = my_strcpy(alpha, "huit");
  else if (nb == 9)
    alpha = my_strcpy(alpha, "neuf");
  else if (nb == 10)
    alpha = my_strcpy(alpha, "dix");
  else
    alpha = get_alpha_nbr2(nb);
  return (alpha);
}
