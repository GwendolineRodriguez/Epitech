/*
** my_putchar.c for my putchar in /home/kerebe_p/git/Piscine_C_J03
** 
** Made by Paul Kerebel
** Login   <kerebe_p@epitech.net>
** 
** Started on  Wed Oct  1 13:16:34 2014 Paul Kerebel
** Last update Wed Oct  8 12:06:32 2014 Paul Kerebel
*/

#include "include/my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
