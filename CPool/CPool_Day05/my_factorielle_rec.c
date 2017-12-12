/*
** my_factorielle_rec.c for my_factorielle_rec in /home/rodrig_1/rendu/Piscine_C_J05
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 19:44:56 2014 gwendoline rodriguez
** Last update Tue Nov 18 19:44:57 2014 gwendoline rodriguez
*/

int	my_factorielle_rec(int nb)
{
  int	i;

  i = nb;
  if (i < 0 || i > 12)
    return (0);
  else if (i == 0)
    return (1);
  else
    return (i * my_factorielle_rec(i - 1));
}
