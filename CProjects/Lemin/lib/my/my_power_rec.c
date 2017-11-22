/*
** my_power_rec for  in /home/daniel_b/Piscine_C_J05
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Fri Oct  3 14:43:21 2014 Erwan DANIEL
** Last update Sat Jan 17 16:08:46 2015 DANIEL Erwan
*/

int	my_power_rec(int nb, int power)
{
  if (power == 0)
    return (nb);
  else if (power == 1)
    return (nb);
  else if (power > 1)
    return (nb * my_power_rec(nb, power - 1));
}
