/*
** my_str_isnum.c for  in /home/daniel_b/Piscine_C_J06
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Tue Oct  7 13:44:06 2014 Erwan DANIEL
** Last update Sun Feb  1 19:42:30 2015 DANIEL Erwan
*/

int	my_str_isnum(char *str)
{
  int	counter;
  int	return_value;

  return_value = 0;
  counter = 0;
  while (str[counter] != '\0')
    {
      if (str[counter] < 48)
	return (0);
      if (str[counter] > 57)
	return (0);
      counter++;
    }
  return (1);
}
