/*
** drawing.h for drawing in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d01/ex03
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Wed Jan  6 22:55:08 2016 Gwendoline Rodriguez
** Last update Wed Jan  6 22:57:46 2016 Gwendoline Rodriguez
*/

#ifndef DRAWING_H_
# define DRAWING_H_

#include <stdint.h>
#include <sys/types.h>

typedef struct	s_point
{
    unsigned int x;
    unsigned int y;
}	t_point;

void draw_square(uint32_t ** img, t_point * orig, size_t size, uint32_t color);

#endif
