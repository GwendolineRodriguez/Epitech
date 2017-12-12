/*
** my_aff_comb.c for my_aff_comb in /home/RODRIG_1/rendu/Piscine_C_J03
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Wed Oct  1 15:14:46 2014 rodriguez gwendoline
** Last update Tue Nov 18 19:05:17 2014 gwendoline rodriguez
*/

int	my_aff_comb()
{
  int	u;
  int	d;
  int	c;

  u = 2;
  d = 1;
  c = 0;
  while (c <= 9)
    {
      c = d + 1;
      my_putchar(u + "0");

      while (d <= 8)
	{
	  d = u + 1;
	  my_putchar(d + "0");

	  while (c <= 7)
	    {
	      u = c + 1;
	      my_putchar(c + "0");
	      my_putchar(32);
	    }
	}
    }
  return (0);
}
