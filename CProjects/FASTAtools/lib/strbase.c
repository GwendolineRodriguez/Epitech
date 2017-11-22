/*
** tools2.c for tools2 in /home/gwendoline/rendu/Piscine_Synthese
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jun 15 15:36:18 2015 
** Last update Wed Jun 24 17:30:01 2015 
*/

#include "header.h"

char            *my_strncpy(char *dest, char *src, int n)
{
  int           i;

  i = 0;
  dest = malloc((sizeof(char*) * my_strlen(src)) + 1);
  if (dest == NULL)
    return (NULL);
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] == s2[i])
        i++;
      else
	return (1);
    }
  if (s2[i] != '\0')
    return (1);
  return (0);
}

char		*my_strdup(char *src)
{
  char		*dest;
  int		length;

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

int		my_strncmp(char *s1, char *s2, int n)
{
  int		i;

  i = 0;
  while (i <= n)
    {
      if (s1[i] != s2[i])
        return (1);
      i = i + 1;
    }
  return (0);
}

char            *get_next_line(const int fd)
{
  static int    read_size;
  static int    i;
  char          str[COUNT + 1];
  char          *str_r;
  int           a;

  a = 0;
  str_r = malloc(sizeof(str_r) + (sizeof(char) * COUNT + 1000));
  while (str[i] != '\n')
    {
      if ((read_size = read(fd, str, COUNT)) == -1 || read_size == 0)
        return (NULL);
      i = 0;
      str[read_size] = 0;
      while (str[i] != 0 && str[i] != '\n')
        str_r[a++] = str[i++];
    }
  str_r[a] = '\n';
  a++;
  str_r[a] = 0;
  return (str_r);
}

