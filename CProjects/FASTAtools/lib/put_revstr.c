/*
** put_revstr.c for put_revstr in /home/gwendoline/rendu/Piscine_Synthese/FASTAtools/lib
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Wed Jun 24 16:21:24 2015 
** Last update Thu Jun 25 21:21:28 2015 
*/

#include "header.h"

void            put_revstr(char *str)
{
  int           len;

  len = my_strlen(str) - 1;
  while (len >= 0)
    {
      my_putchar(str[len]);
      len--;
    }
}
