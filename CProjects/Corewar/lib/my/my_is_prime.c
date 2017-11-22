/*
** my_is_prime.c for my_is_prime in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 18:36:18 2014 gwendoline rodriguez
** Last update Tue Nov 18 19:38:23 2014 gwendoline rodriguez
*/

int	my_is_prime(int nb)
{
  int	i;

  i = 2;
  if (nb == 0 || nb == 1)
    return (0);
  if (nb == 2)
    return (1);
  while (i < nb)
    {
      if (nb % i == 0)
	return (0);
      i = i + 1;
    }
  return (1);
}
