/*
** my_strcapitalize for  in /home/daniel_b/Piscine_C_J06
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Tue Oct  7 11:27:15 2014 Erwan DANIEL
** Last update Sat Jan 17 16:16:21 2015 DANIEL Erwan
*/

char	*my_strcapitalize(char *str)
{
  int	counter;
  int	size_of_str;

  counter = 0;
  size_of_str = 0;
  while (str[size_of_str] != '\0')
    size_of_str++;
  while (counter != size_of_str)
    {
      if (str[counter] >= 97 && str[counter] <= 122)
	if (str[counter - 1] >= 32 && str[counter - 1] <= 47)
	  if (str[counter - 1] != 39)
	    str[counter] = str[counter] - 32;
      if (counter == 0)
	if (str[counter] >= 97 && str[counter] <= 122)
	  str[counter] = str[counter] - 32;
      counter++;
    }
  return (0);
}
