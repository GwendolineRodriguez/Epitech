/*
** operator.c for operator in /home/RODRIG_1/rendu/Piscine_C_J11/do-op
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Mon Oct 20 21:39:21 2014 rodriguez gwendoline
** Last update Wed Oct 29 13:13:24 2014 rodriguez gwendoline
*/

int	my_add(char *nb1, char *nb2)
{
  int   n;

  n = my_getnbr(nb1) + my_getnbr(nb2);
  return (n);
}

int     my_sub(char *nb1, char *nb2)
{
  int   n;

  n = my_getnbr(nb1) - my_getnbr(nb2);
  return (n);
}

int     my_div(char *nb1, char *nb2)
{
  int   n;

  n = my_getnbr(nb1) / my_getnbr(nb2);
  return (n);
}

int     my_mul(char *nb1, char *nb2)
{
  int   n;

  n = my_getnbr(nb1) * my_getnbr(nb2);
  return (n);
}

int     my_mod(char *nb1, char *nb2)
{
  int   n;

  n = my_getnbr(nb1) % my_getnbr(nb2);
  return (n);
}
