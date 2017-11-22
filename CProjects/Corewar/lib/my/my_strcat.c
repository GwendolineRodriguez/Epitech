/*
** my_strcat.c for my_strcat in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 18:41:29 2014 gwendoline rodriguez
** Last update Sun Apr 12 22:55:01 2015 gwendoline rodriguez
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int   i;
  int   j;
  char	*result;

  i = my_strlen(dest);
  j = my_strlen(src);
  if ((result = (char*)malloc(sizeof(char) * (i + j + 2))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (dest[j])
    result[i++] = dest[j++];
  j = 0;
  while (src[j])
    result[i++] = src[j++];
  result[i] = '\0';
  return (result);
}
