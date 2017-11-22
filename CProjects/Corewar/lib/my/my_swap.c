/*
** my_swap.c for my_swap in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 18:47:11 2014 gwendoline rodriguez
** Last update Tue Nov 18 18:47:24 2014 gwendoline rodriguez
*/

int	my_swap(int *a, int *b)
{
  int c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
