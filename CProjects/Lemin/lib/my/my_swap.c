/*
** my_swap for  in /home/daniel_b/Piscine_C_J04
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Thu Oct  2 11:24:52 2014 Erwan DANIEL
** Last update Sun Feb  1 19:29:35 2015 DANIEL Erwan
*/

int	my_swap(int *a, int *b)
{
  int	temp_integer;

  temp_integer = *a;
  *a = *b;
  *b = temp_integer;
  return (0);
}
