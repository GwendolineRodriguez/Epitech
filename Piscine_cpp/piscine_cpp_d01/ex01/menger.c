/*
** menger.c for menger in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d01/ex01
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Wed Jan  6 11:46:23 2016 Gwendoline Rodriguez
** Last update Wed Jan  6 20:16:24 2016 Gwendoline Rodriguez
*/

#include "header.h"

void	menger(int size, int level, int x, int y)
{
  size = size / 3;
  printf("%03d %03d %03d\n", size, x + size, y + size);
  if ((level > 1) && (size / 3) > 0)
    {
      level -= 1;
      menger(size, level, x, y);
      menger(size, level, x, y + size);
      menger(size, level, x, y + 2 * size);
      menger(size, level, x + size, y);
      menger(size, level, x + size, y + 2 * size);
      menger(size, level, x + 2 * size, y);
      menger(size, level, x + 2 * size, y + size);
      menger(size, level, x + 2 * size, y + 2 * size);
    }
}
/* menger(size, level, x, y); */
/* menger(size, level, x, y + size / 3); */
/* menger(size, level, x, y + 2 * size); */
/* menger(size, level, x + size, y); */
/* menger(size, level, x + size, y + 2 * size); */
/* menger(size, level, x + 2 * size, y); */
/* menger(size, level, x + 2 * size, y + size); */
/* menger(size, level, x + 2 * size, y + 2 * size); */

