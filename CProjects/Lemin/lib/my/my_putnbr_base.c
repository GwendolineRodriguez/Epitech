/*
** my_putnbr_base for  in /home/daniel_b/Piscine_C_J06
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Tue Oct  7 21:10:20 2014 Erwan DANIEL
** Last update Sun Feb  1 19:46:20 2015 DANIEL Erwan
*/

int	my_putnbr_base(int nb, char *base)
{
  int	result;
  int	diviseur;
  int	size_base;

  size_base = 0;
  while (base[size_base] != '\0')
    size_base++;
  if (nb < 0)
    {
      write(1, "-", 1);
      nb = -nb;
    }
  diviseur = 1;
  while ((nb / diviseur) >= size_base)
    diviseur = diviseur * size_base;
  while (diviseur > 0)
    {
      result = (nb / diviseur) % size_base;
      write(1, &base[result], 1);
      diviseur = diviseur / size_base;
    }
  return (0);
}
