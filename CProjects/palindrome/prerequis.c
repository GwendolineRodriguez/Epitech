/*
** prerequis.c for prerequis.c in /home/gwendoline/rendu/Piscine_Synthese/palindrome
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jun 26 11:18:26 2015 
** Last update Sun Jun 28 14:34:48 2015 Gwendoline Rodriguez
*/

int		my_factrec_synthese(int nb)
{
  if (nb == 0)
    return (1);
  if (nb > 0 && nb < 13)
    nb = nb * my_factrec_synthese(nb - 1);
  else
    return (0);
  return (nb);
}

int		my_squareroot_synthese(int nb)
{
  int		s;

  s = nb;
  if (s > 1000000000)
    nb = nb / 10000;
  if (nb == 0)
    return (0);
  else if (nb == 1)
    return (1);
  nb = nb / 2;
  while (nb > 0 && s <= 2147483647)
    {
      if ((nb * nb) == s)
	return (nb);
      nb--;
    }
  return (-1);
}
