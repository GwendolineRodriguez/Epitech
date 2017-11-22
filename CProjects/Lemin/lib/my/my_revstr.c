/*
** my_revstr.c for  in /home/daniel_b/Piscine_C_J06
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Mon Oct  6 15:53:20 2014 Erwan DANIEL
** Last update Sun Feb  1 19:43:13 2015 DANIEL Erwan
*/

char	*my_revstr(char *str)
{
  int	counter;
  int	size_of_str;
  char	temp_char;

  size_of_str = get_array_size(str) - 1;
  counter = 0;
  while (counter != size_of_str / 2)
    {
      temp_char = str[counter];
      str[counter] = str[size_of_str - counter];
      str[size_of_str - counter] = temp_char;
      counter++;
    }
  return (str);
}

int	get_array_size(char *str)
{
  char	*temp_str;
  int	size_of_array;

  temp_str = str;
  size_of_array = 0;
  while (*temp_str != '\0')
    {
      size_of_array++;
      temp_str = temp_str + sizeof (char);
    }
  return (size_of_array);
}
