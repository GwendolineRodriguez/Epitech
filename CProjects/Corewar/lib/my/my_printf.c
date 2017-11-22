/*
** my_printf.c for my_printf in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Wed Nov 12 09:36:51 2014 gwendoline rodriguez
** Last update Sun Mar  8 23:37:17 2015 gwendoline rodriguez
*/

#include <stdarg.h>
#include "my.h"

int     my_printf(char *format, ...)
{
  format = "my_printf\n";
  my_putstr(format);
  return (0);
}
