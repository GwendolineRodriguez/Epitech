/*
** tools.c for tools in /home/gwendoline/rendu/Prgelm/colles/pretty_calendar/gwen
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Tue Jun  9 21:19:43 2015 
** Last update Tue Jun  9 22:58:34 2015 
*/

#include "calendar.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void		my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + 48);
}

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  dest = malloc((sizeof(char*) * my_strlen(src)) + 1);
  if (dest == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
