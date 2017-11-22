/*
** check_ifword.c for check_ifword in /home/gwendoline/rendu/Prgelm/colles/my_mixword/gwen
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Wed Jun 10 12:00:10 2015 
** Last update Wed Jun 10 14:56:47 2015 
*/

#include "my_mixword.h"

int             check_diag_down_right(t_grid *p)
{
  int           i;
  int           j;
  int           c;

  c = 0;
  i = 0;
  j = 0;
  while (p->grid[i++] != NULL)
    {
      while (p->grid[i][j] != '\0')
        {
          if (p->grid[i++][j++] == p->word[c++])
            {
              p->pos_x = i;
              p->pos_y = j;
              p->way = DIAG_DOWN_RIGHT;
            }
          else if (p->grid[i][j++] == p->word[c])
            c = 0;
        }
    }
  if (p->word[c] == '\0')
    return (1);
  return (0);
}

int             check_v(t_grid *p)
{
  int           i;
  int           j;
  int           c;

  c = 0;
  while (p->grid[i++] != NULL)
    {
      i = 0;
      j = 0;
      while (p->grid[i][j] != '\0')
        {
          if (p->grid[i++][j] == p->word[c++])
	    {
	      p->pos_x = i;
	      p->pos_y = j;
	      p->way = DOWN;
	    }
          else if (p->grid[i][j++] == p->word[c])
            c = 0;
        }
    }
  if (p->word[c] == '\0')
    return (1);
  return (0);
}

int		check_h(t_grid *p)
{
  int		i;
  int		j;
  int		c;

  i = -1;
  c = 0;
  while (p->grid[++i] != NULL)
    {
      j = 0;
      while (p->grid[i][j] != '\0')
	{
	  if (p->grid[i][j] == p->word[c++])
	    {
	      p->pos_x = i;
	      p->pos_y = j;
	      p->way = RIGHT;
	    }
	  else
	    c = 0;
	  j++;
	}
    }
  if (p->word[c] == '\0')
    return (1);
  return (0);
}
