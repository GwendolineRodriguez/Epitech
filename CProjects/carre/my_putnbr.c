/*
** my_putnbr.c for my_putnbr in /home/rodrig_1/rendu/Prgelm/colles/carre
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue May  5 12:05:53 2015 gwendoline rodriguez
** Last update Tue May  5 12:07:58 2015 gwendoline rodriguez
*/

void	my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + 48);
}
