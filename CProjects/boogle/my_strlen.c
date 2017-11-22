/*
** my_strlen.c for my_strlen in /home/gwendoline/rendu/Prgelm/colles/boogle/gwen
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jun  5 16:28:38 2015 
** Last update Fri Jun  5 16:39:05 2015 
*/

#include "my_boogle.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return(i);
}
