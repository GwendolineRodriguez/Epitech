/*
** my_putnbr.c for my_putnbr in /home/gwendoline/rendu/Prgelm/colles/master_mind/gwen
**
** Made by rodrig_1
** Login   <gwendoline@epitech.net>
**
** Started on  Thu May 21 14:10:17 2015 
** Last update Thu May 21 14:12:16 2015 
*/

void		my_putnbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + 48);
}
