/*
** my_strcpy for  in /home/daniel_b/Piscine_C_J06
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Mon Oct  6 11:37:33 2014 Erwan DANIEL
** Last update Sun Feb  1 19:38:13 2015 DANIEL Erwan
*/

#include <stdlib.h>

char	*my_strcpy(char *src)
{
  char	*new;
  int	size;

  size = 0;
  while (src[size++]);
  if (!(new = malloc(sizeof (char) * size)))
    return (0);
  while (size)
    new[--size] = src[size];
  return (new);
}
