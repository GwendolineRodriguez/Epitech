/*
** operator.c for operator in /home/RODRIG_1/rendu/Piscine_C_J11/do-op
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Mon Oct 20 21:39:21 2014 rodriguez gwendoline
** Last update Tue Oct 21 19:49:03 2014 rodriguez gwendoline
*/

int	my_add(char *nb1, char *nb2)
{
  int   n;

  n = my_getnbr(nb1) + my_getnbr(nb2);
  my_put_nbr(n);
  my_putchar('\n');
  return (0);
}

int     my_sub(char *nb1, char *nb2)
{
  int   n;

  n = my_getnbr(nb1) - my_getnbr(nb2);
  my_put_nbr(n);
  my_putchar('\n');
  return (0);
}

int     my_div(char *nb1, char *nb2)
{
  int   n;

  n = my_getnbr(nb1) / my_getnbr(nb2);
  my_put_nbr(n);
  my_putchar('\n');
  return (0);
}

int     my_mul(char *nb1, char *nb2)
{
  int   n;

  n = my_getnbr(nb1) * my_getnbr(nb2);
  my_put_nbr(n);
  my_putchar('\n');
  return (0);
}

int     my_mod(char *nb1, char *nb2)
{
  int   n;

  n = my_getnbr(nb1) % my_getnbr(nb2);
  my_put_nbr(n);
  my_putchar('\n');
  return (0);
}
