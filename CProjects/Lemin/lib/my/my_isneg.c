/*
** my_isneg.c for my_isneg in /home/daniel_b/Piscine_C_J03
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Wed Oct  1 11:24:15 2014 Erwan DANIEL
** Last update Sat Jan 17 16:07:51 2015 DANIEL Erwan
*/

int	my_isneg(int n)
{
  if (n < 0)
      write(1, "N", 1);
  else
      write(1, "P", 1);
  return (0);
}
