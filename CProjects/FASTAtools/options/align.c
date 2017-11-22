/*
** align.c for align in /home/gwendoline/rendu/Piscine_Synthese/FASTAtools
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jun 25 19:53:19 2015 
** Last update Thu Jun 25 21:03:04 2015 
*/

#include "header.h"

void		display_align(char *str)
{
  char		s1[4000];
  char		s2[4000];
  int		j;
  int		i;

  j = 0;
  i = 0;
  str = get_epur_str(str, -1, 0);
  while (str[i] != '\0')
    {
      if (str[i] == '>')
	while (str[i++] != '\n');
      while (str[i++] != '\n' && str[i] != '\0')
	s1[j] = str[i];
      s1[j] = '\0';
      while (str[i++] != '\0' && str[i] == '\n');
      j = 0;
      while (str[i++] != '\n' && str[i] != '\0')
        s2[j] = str[i];
      s2[j] = '\0';
      i++;
    }
  printf("%s%s\n", s1, s2);
}
