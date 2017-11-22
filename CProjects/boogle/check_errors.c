/*
** check_errors.c for check_errors in /home/gwendoline/rendu/Prgelm/colles/boogle/gwen
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jun  5 17:06:11 2015 
** Last update Fri Jun  5 19:58:17 2015 
*/

#include "my_boogle.h"

int		is_num(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > '9' || str[i] < '0')
	return (-1);
      i++;
    }
  return (0);
}

int		my_getnbr(char *str)
{
  int		nb;
  int		i;

  nb = 0;
  i = 0;
  if (is_num(str) != 0)
    my_error("Size must be a positive number.\n");
  while (str[i] != '\0')
    {
      nb = (nb * 10) + (str[i] - 48);
      i++;
    }
  return (nb);
}

char		*get_grid_str(char *src, char *dest)
{
  int		i;

  i = 0;
  dest = malloc((sizeof(char) * my_strlen(src)) + 1);
  if (dest == NULL)
    my_error("Error on malloc.\n");
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] == '\0';
  return (dest);
}

int		check_errors(t_boogle *boogle, char *grid)
{
  int		i;

  i = 0;
  while (boogle->word[i] != '\0')
    {
      if (boogle->word[i] < 'a' || boogle->word[i] > 'z')
	my_error("word must be in lower keys.\n");
      i++;
    }
  if ((boogle->size * boogle->size) != my_strlen(grid))
    my_error("The grid does not have good number of character.\n");
  return (0);
}
