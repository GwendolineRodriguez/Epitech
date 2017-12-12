/*
** my_strdup.c for my_strdup in /home/RODRIG_1/rendu/Piscine_C_J08/ex_01
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Wed Oct  8 10:28:11 2014 rodriguez gwendoline
** Last update Wed Oct  8 15:55:51 2014 rodriguez gwendoline
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  char	*dest;
  int	length;

  length = my_strlen(src);
  dest = malloc(length + 1);
  length = 0;
  while (src[length] != '\0')
    {
      dest[length] = src[length];
      length = length + 1;
    }
  dest[length] = '\0';
  return (dest);
}
