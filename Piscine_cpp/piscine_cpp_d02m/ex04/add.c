/*
** add.c for add in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d02m/ex04
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jan  7 14:29:41 2016 Gwendoline Rodriguez
** Last update Thu Jan  7 16:51:59 2016 Gwendoline Rodriguez
*/

#include "castmania.h"

int	normal_add(int a, int b)
{
  int	res;

  res = a + b;
  return (res);
}

int	absolute_add(int a, int b)
{
  int	res;

  res = abs(a) + abs(b);
  return (res);
}

void	exec_add(t_add *operation)
{
  if (operation->add_type == NORMAL) {
    operation->add_op.res = normal_add(operation->add_op.a, operation->add_op.b);
  }
  else if (operation->add_type == ABSOLUTE) {
    operation->add_op.res = absolute_add(operation->add_op.a, operation->add_op.b);
  }
}
