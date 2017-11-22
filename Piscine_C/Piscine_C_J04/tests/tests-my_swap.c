/*
** tests-my_swap.c for tewt-my_swap in /home/RODRIG_1/rendu/Piscine_C_J04/tests
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Thu Oct  2 10:45:45 2014 rodriguez gwendoline
** Last update Fri Oct  3 21:17:43 2014 rodriguez gwendoline
*/

int	my_putchar(int c)
{
  write(1, &c, 1);
}

int	main()
{
  int	a;
  int	b;

  a = '4';
  b = '6';

  my_swap(&a, &b);
  my_putchar(a);
  my_putchar(b);
}
