/*
** my_putchar.c for my_putchar in /home/gwendoline/rendu/Prgelm/colles/boogle/gwen
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jun  5 16:18:11 2015 
** Last update Fri Jun  5 16:38:23 2015 
*/

#include "my_boogle.h"

void	my_putchar(char c)
{
  write(c, &c, c);
}
