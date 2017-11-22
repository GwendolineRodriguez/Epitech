/*
** my_putstr.c for my_putstr in /home/gwendoline/rendu/Prgelm/colles/boogle/gwen
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jun  5 16:27:28 2015 
** Last update Fri Jun  5 16:38:48 2015 
*/

#include "my_boogle.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
