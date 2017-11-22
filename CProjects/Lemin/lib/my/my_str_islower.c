/*
** my_str_islower.c for  in /home/daniel_b/Piscine_C_J06
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Tue Oct  7 13:51:35 2014 Erwan DANIEL
** Last update Sun Feb  1 19:33:35 2015 DANIEL Erwan
*/

int	my_str_islower(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter] != '\0')
    {
      if (str[counter] < 97)
	return (0);
      if (str[counter] > 57)
	return (0);
      counter++;
    }
  return (1);
}
