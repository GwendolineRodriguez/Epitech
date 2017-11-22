/*
** my_power_rec.c for my_power_rec in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 18:36:47 2014 gwendoline rodriguez
** Last update Tue Nov 18 18:36:48 2014 gwendoline rodriguez
*/

int	my_power_rec(int nb, int power)
{
  int	x;

  x = nb;
  if (power > 0)
    return (nb = (my_power_rec(nb, power - 1) * x));
  return (1);
}
