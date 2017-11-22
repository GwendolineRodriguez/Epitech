/*
** bsq.c for bsq in /home/rodrig_1/rendu/Prgelm/CPE_2014_bsq
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Mon Dec 15 11:08:06 2014 gwendoline rodriguez
** Last update Fri Jan 16 17:24:02 2015 gwendoline rodriguez
*/

#include <stdlib.h>
#include <header.h>

char		*change_str(char *str, int x, int y, int size)
{
  int		i;

  i = 0;
  while (str[i] != '\n')
    {
      if (str[i] == '.' && i >= x && (i + x) <= size)
	str[i] = 'x';
      i++;
    }
  return (str);
}

int		make_square(char **s, int x, int y, int size)
{
  int		i;

  i = 0;
  while (i != recup)
    {
      my_putstr(change_str(s[i], x, y, size));
      i++;
    }
  return (0);
}

char		check_square(char **s, int x, int recup)
{
  int		xsave;
  int		ysave;
  int		y;

  xsave = 0;
  ysave = 0;
  while (s[y][x] != 'o')
    {
      y = 0;
      if (s[y][x] == '.')
	{
	  xsave++;
	  y++;
	  while (s[y][x] == '.' && x != save)
	    x++;
	}
      else
	y++;
    }
  make_square(s, x, y, recup);
}

int		main()
{
  char		**s;
  int		recup;
  int		i;

  i = 0;
  if ((s = malloc(30000 * sizeof(char**))) == NULL)
    return (0);
  recup = my_getnbr(get_next_line(0));
  while ((s[i] = get_next_line(0)))
    i++;
  i = 0;
  check_square(s, 0, recup);
  free(s);
  return (0);
}
