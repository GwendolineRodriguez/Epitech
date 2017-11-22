/*
** check_revword.c for check_revword in /home/gwendoline/rendu/Prgelm/colles/my_mixword/gwen
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Wed Jun 10 12:54:47 2015 
** Last update Wed Jun 10 15:00:45 2015 
*/

#include "my_mixword.h"

int             check_diag_up_left(t_grid *p)
{
  int           c;
  int           i;
  int           j;

  c = 0;
  i = 0;
  j = 0;
  while (p->grid[i++] != NULL)
    {
      while (p->grid[i][j] != '\0')
        {
          if (p->grid[i][j] == p->word[c])
            {
              p->pos_x = i;
              p->pos_y = j;
            }
          if (p->grid[i--][j--] == p->word[c++])
            p->way = DIAG_DOWN_LEFT;
          else if (p->grid[i][j--] == p->word[c])
            c = 0;
        }
    }
  if (p->word[c] == '\0')
    return (1);
  return (0);
}

int             check_diag_up_right(t_grid *p)
{
  int           c;
  int           i;
  int           j;

  c = 0;
  i = 0;
  j = 0;
  while (p->grid[i++] != NULL)
    {
      while (p->grid[i][j] != '\0')
        {
          if (p->grid[i][j] == p->word[c])
            {
              p->pos_x = i;
              p->pos_y = j;
            }
          if (p->grid[i--][j++] == p->word[c++])
            p->way = DIAG_DOWN_LEFT;
          else if (p->grid[i][j--] == p->word[c])
            c = 0;
        }
    }
  if (p->word[c] == '\0')
    return (1);
  return (0);
}

int		check_diag_down_left(t_grid *p)
{
  int		c;
  int		i;
  int		j;
  int		check;

  c = 0;
  i = 0;
  j = 0;
  check = 0;
  while (p->grid[i++] != NULL)
    {
      while (p->grid[i][j] != '\0')
	{
	  if (p->grid[i++][j--] == p->word[c++])
	    p->way = DIAG_DOWN_LEFT;
	  else if (p->grid[i][j--] == p->word[c])
	    c = 0;
	}
    }
  if (p->word[c] == '\0')
    return (1);
  return (0);
}

int             check_vrev(t_grid *p)
{
  int           c;
  int           i;
  int           j;

  c = 0;
  while (p->grid[i++] != NULL)
    {
      i = 0;
      j = 0;
      while (p->grid[i][j] != '\0')
        {
          if (p->grid[i--][j++] == p->word[c++])
	    p->way = UP;
          else if (p->grid[i][j++] == p->word[c])
	    {
	      i = i + c;
	      c = 0;
	    }
        }
    }
  if (p->word[c] == '\0')
    return (1);
  return (0);
}

int             check_hrev(t_grid *p)
{
  int           c;
  int           i;
  int           j;

  c = 0;
  i = 0;
  while (p->grid[i++] != NULL)
    {
      j = 0;
      while (p->grid[i][j] != '\0')
        {
          if (p->grid[i++][j--] == p->word[c++])
	    p->way = LEFT;
          else if (p->grid[i][j++] == p->word[c])
	    {
	      j = j + c;
	      c = 0;
	    }
        }
    }
  if (p->word[c] == '\0')
    return (1);
  return (0);
}

