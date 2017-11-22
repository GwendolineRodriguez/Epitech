/*
** tools.c for my_mixword in /home/duclos_r/Tek-1/Colle/my_mixword
** 
** Made by Rémi Duclos
** Login   <duclos_r@epitech.net>
** 
** Started on  Wed Jun 10 09:19:36 2015 Rémi Duclos
** Last update Wed Jun 10 11:27:40 2015 Rémi Duclos
*/

#include "my_mixword.h"

int     my_strlen(char *str)
{
  int   cnt;

  cnt = 0;
  while (str[cnt] != '\0')
    cnt++;
  return (cnt);
}

int	my_strcmp(char *s1, char *s2)
{
  int	cnt;

  cnt = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (0);
  while (s1[cnt] != '\0' && s2[cnt] != '\0')
    {
      if (s1[cnt] != s2[cnt])
	return (0);
      cnt++;
    }
  return (1);
}

char	*my_strdup(char *src)
{
  char	*dest;
  int	cnt;

  cnt = 0;
  dest = malloc(sizeof(*dest) * (my_strlen(src) + 1));
  while (src[cnt] != '\0')
    {
      dest[cnt] = src[cnt];
      cnt++;
    }
  dest[cnt] = '\0';
  return (dest);
}
