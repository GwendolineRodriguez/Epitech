/*
** my_power_rec.c for my_power_rec in /home/RODRIG_1/rendu/Piscine_C_J05
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Mon Oct  6 21:18:11 2014 rodriguez gwendoline
** Last update Mon Oct  6 21:21:18 2014 rodriguez gwendoline
*/

int	my_power_rec(int nb, int power)
{
  int	x;

  x = nb;
  if (power > 0)
    return (nb = (my_power_rec(nb, power - 1) * x));
  return (1);
}
