/*
** my_is_prime.c for my_is_prime in /home/RODRIG_1/rendu/Piscine_C_J07/lib/my
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Tue Oct  7 17:46:18 2014 rodriguez gwendoline
** Last update Mon Oct 20 20:44:00 2014 rodriguez gwendoline
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
