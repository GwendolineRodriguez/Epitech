/*
** test.c for my_put_nbr in /home/daniel_b/Piscine_C_J03
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Thu Oct  2 01:37:20 2014 Erwan DANIEL
** Last update Sun Feb  1 19:39:37 2015 DANIEL Erwan
*/

int	get_next(int number)
{
  char	c;

  c = (number % 10) + 0x30;
  if (number < 10)
    {
      write(1, &c, 1);
      return;
    }
  number = number / 10;
  get_next(number);
  write(1, &c, 1);
  return (0);
}

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      write(1, "-", 1);
      get_next(nb * -1);
    }
  else
    get_next(nb);
  return (0);
}
