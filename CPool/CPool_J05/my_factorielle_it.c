/*
** my_factorielle_it.c for my_factorielle_it in /home/RODRIG_1/rendu/Piscine_C_J05
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Mon Oct  6 20:30:51 2014 rodriguez gwendoline
** Last update Mon Oct  6 20:50:29 2014 rodriguez gwendoline
*/

int	my_factorielle_it(int nb)
{
  int	res;
  int	i;

  res = 1;
  i = 1;
  if (nb < 0 || nb > 12)
    return (0);
  while (nb > 0)
    {
      res = res * i;
      if (res < 0)
	return (0);
      nb = nb - 1;
      i = i + 1;
    }
  return (res);
}
