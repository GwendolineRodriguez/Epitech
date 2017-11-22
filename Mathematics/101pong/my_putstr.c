/*
** my_putstr.c for my_putstr in /home/rodrig_1/rendu/101pong
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Mon Nov 10 18:42:40 2014 gwendoline rodriguez
** Last update Tue Nov 11 11:39:31 2014 gwendoline rodriguez
*/

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
