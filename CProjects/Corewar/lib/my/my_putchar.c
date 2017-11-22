/*
** my_putchar.c for my_putchar in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 18:37:30 2014 gwendoline rodriguez
** Last update Sun Mar  8 23:38:11 2015 gwendoline rodriguez
*/

#include <unistd.h>

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}
