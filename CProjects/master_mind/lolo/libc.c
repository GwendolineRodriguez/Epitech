/*
** libc.c for master_mind in /home/faure-_l/Colle/master_mind/lolo
** 
** Made by Loik Fauré-Berlinguette
** Login   <faure-_l@epitech.net>
** 
** Started on  Thu May 21 14:09:38 2015 Loik Fauré-Berlinguette
** Last update Thu May 21 14:41:38 2015 Loik Fauré-Berlinguette
*/

#include <stdlib.h>

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}

void	my_putstr(char *s)
{
  int	idx;

  idx = 0;
  while (*s)
    my_putchar(s[idx++]);
}

int	my_strlen(char *s)
{
  int	idx;

  idx = 0;
  while (s[idx])
    {
      s[idx];
      idx++;
    }
  return (idx);
}

int	my_strncmp(char *s1, char *s2, size_t len)
{
  while (len-- && *s1 && *s1 == *s2)
    {
      ++s1;
      ++s2;
    }
  return (*s1 - *s2);
}

void	my_error(char *s)
{
  int	len;

  len = my_strlen(s);
  write(2, s , len);
  exit(1);
}
