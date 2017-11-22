/*
** my_square_root.c for my_square_root in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 18:40:38 2014 gwendoline rodriguez
** Last update Tue Nov 18 22:32:48 2014 gwendoline rodriguez
*/

int	my_square_root(int nb)
{
  int	i;

  i = 1;
  while (i * i != nb && !(i * i < i) && i < nb)
    i = i + 1;
  if (i * i != nb)
    return (0);
  return (i);
}
