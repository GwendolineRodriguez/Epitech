/*
** div.c for div in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d02m/ex04
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jan  7 14:28:36 2016 Gwendoline Rodriguez
** Last update Thu Jan  7 16:46:23 2016 Gwendoline Rodriguez
*/

#include "castmania.h"

int	integer_div(int a, int b)
{
  int	res;

  res = 0;
  if (b != 0)
    res = a / b;
  return (res);
}

float	decimale_div(int a, int b)
{
  int   res;

  res = 0;
  if (b != 0)
    res = a / (float) b;
  return (res);
}

void	exec_div(t_div *operation)
{
  if(operation->div_type == INTEGER) {
    ((t_integer_op *) operation->div_op)->res =
      integer_div(((t_integer_op *) operation->div_op)->a, ((t_integer_op *) operation->div_op)->b);
  }
  else if(operation->div_type == DECIMALE) {
    ((t_decimale_op *) operation->div_op)->res =
      decimale_div(((t_decimale_op *) operation->div_op)->a, ((t_decimale_op *) operation->div_op)->b);
  }
}
