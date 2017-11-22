/*
** my_power_it.c for my_power_it in /home/RODRIG_1/rendu/Piscine_C_J05
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Mon Oct  6 21:08:31 2014 rodriguez gwendoline
** Last update Tue Oct  7 08:32:41 2014 rodriguez gwendoline
*/

int	my_power_it(int	nb, int	power)
{
  int	res;

  if (power == 0)
    return (1);
  else if (power < 0)
    return (0);
  res = nb;
  while (power > 1)
    {
      res = res * nb;
      if (res < 0)
	return (0);
      power = power - 1;
    }
  return (res);
}
