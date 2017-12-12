/*
** drawing.c for drawing in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d01/ex03
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Wed Jan  6 22:52:36 2016 Gwendoline Rodriguez
** Last update Wed Jan  6 22:54:52 2016 Gwendoline Rodriguez
*/

#include <stdint.h>
#include <sys/types.h>
#include "drawing.h"

void		draw_square(uint32_t ** img, t_point * orig, size_t size, uint32_t color)
{
  uint32_t	j;
  uint32_t	i;

  i = 0;
  while (i < size)
    {
      j = -1;
      while (++j < size)
	img[orig->x + i][orig->y + j] = color;
      ++i;
    }
}
