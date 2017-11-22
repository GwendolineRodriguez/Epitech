/*
** my_strcmp.c for my_strcmp in /home/gwendoline/rendu/Prgelm/colles/opt_get/gwen
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Mon May 25 17:28:01 2015 
** Last update Mon May 25 19:47:27 2015 
*/

#include "opt_get.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + 48);
}

int	my_strcmp(char *s1, const char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] == s2[i])
	i++;
      else
	return (-1);
    }
  if (s2[i] != '\0')
    return (-1);
  return (0);
}

int	my_strncmp(char *s1, char *s2, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      if (s1[i] == s2[i])
        i++;
      else
        return (-1);
    }
  return (0);
}

char	*my_strdup(char *str)
{
  char	*ret;
  int	cnt;

  cnt = 0;
  ret = malloc(sizeof(*ret) * (my_strlen(str) + 1));
  while (str[cnt] != '\0')
    ret[cnt] = str[cnt++];
  ret[cnt] = '\0';
  return (ret);
}
