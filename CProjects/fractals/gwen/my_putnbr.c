/*
** my_putnbr.c for my_putnbr in /home/rodrig_1/fractals/gwen
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Apr 28 11:47:48 2015 gwendoline rodriguez
** Last update Tue Apr 28 11:49:04 2015 gwendoline rodriguez
*/

void	my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + 48);
}
