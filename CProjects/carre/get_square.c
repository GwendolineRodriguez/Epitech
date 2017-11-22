/*
** get_square.c for get_square in /home/rodrig_1/rendu/Prgelm/colles/carre
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue May  5 09:44:41 2015 gwendoline rodriguez
** Last update Tue May  5 12:43:26 2015 gwendoline rodriguez
*/

void	get_up_square(int l)
{
  int	ls;
  int	c;

  ls = l - 1;
  c = 0;
  my_putstr("    ");
  while (c <= (l * 2))
    {
      my_putnbr(c);
      c++;
    }
  my_putchar('\n');
  my_putstr("     ");
  while (ls >= 0)
    {
      my_putchar('_');
      if (ls != 0)
	my_putchar(' ');
      else
	my_putchar('\n');
      ls--;
    }
}

void	get_lign(int ls, int hs)
{
  if (hs > 9)
    my_putstr("  ");
  else
    my_putstr("   ");
  while (ls >= 0)
    {
      my_putchar('|');
      if (ls != 0)
	my_putchar('_');
      else
	my_putchar('\n');
      ls--;
    }
}

void	get_square(int l, int h)
{
  int	hs;
  int	ld;

  hs = h;
  ld = l;
  while (hs > 0)
    {
      if (ld == l)
	get_up_square(l);
      my_putnbr(hs);
      get_lign(l, hs);
      ld--;
      hs--;
    }
}
