/*
** my_strlowcase for  in /home/daniel_b/Piscine_C_J06
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Tue Oct  7 10:48:53 2014 Erwan DANIEL
** Last update Sun Feb  1 19:32:23 2015 DANIEL Erwan
*/

char	*my_strlowcase(char *str)
{
  int	size_of_str;
  int	counter;

  counter = 0;
  size_of_str = 0;
  while (str[size_of_str] != '\0')
    size_of_str++;
  while (counter != size_of_str)
    {
      if (str[counter] >= 65 && str[counter] <= 90)
	str[counter] = str[counter] + 32;
      counter++;
    }
  return (str);
}
