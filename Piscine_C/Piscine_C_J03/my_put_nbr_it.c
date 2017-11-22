/*
** my_put_nbr.c for my_put_nbr in /home/RODRIG_1/rendu/Piscine_C_J04
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Wed Oct  8 20:04:14 2014 rodriguez gwendoline
** Last update Fri Oct 10 09:37:32 2014 rodriguez gwendoline
*/

int     count_col(int nb)
{
  int   n;

  n = 0;
  while (nb > 0)
    {
      n = n + 1;
      nb = nb / 10;
    }
  return (n);
}

int	my_put_nbr(int nb)
{
  int	n;
  int	nb2;
  int	exp;

  exp = n * 
  nb = nb2;
  n = count_col(nb);
  while (n > 0)
    {
      nb2 = nb2 / exp;
      n = n - 1;
      exp = exp * 10;
    }
  my_putchar(nb2);
}

int	main()
{
  int nb;

  nb = 209;
  //count_col(nb);
  my_put_nbr(nb);
  my_putchar('\n');
}
