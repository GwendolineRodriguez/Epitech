/*
** my_putchar.c for my_putchar in /home/rodrig_1/fractals/gwen
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Apr 28 11:40:38 2015 gwendoline rodriguez
** Last update Tue Apr 28 10:25:56 2015 Loik Fauré-Berlinguette
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      my_putchar(s[i]);
      i++;
    }
}
