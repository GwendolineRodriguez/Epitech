/*
** tools2.c for tools2 in /home/gwendoline/rendu/Prgelm/colles/my_mixword
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Wed Jun 10 13:50:14 2015 
** Last update Wed Jun 10 14:06:09 2015 
*/

#include "my_mixword.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	my_error(char *str)
{
  write(2, str, my_strlen(str));
  exit(0);
}
