/*
** my_strdup.c for my_strdup in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 18:28:44 2014 gwendoline rodriguez
** Last update Sun Mar  8 23:49:41 2015 gwendoline rodriguez
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char	*dest;
  int	length;

  length = my_strlen(src);
  dest = malloc(sizeof(char) * (length + 1));
  length = 0;
  while (src[length] != '\0')
    {
      dest[length] = src[length];
      length = length + 1;
    }
  dest[length] = '\0';
  return (dest);
}
