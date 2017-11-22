/*
** my_strcmp.c for  in /home/daniel_b/Piscine_C_J06
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Tue Oct  7 09:21:56 2014 Erwan DANIEL
** Last update Sat Jan 17 16:17:48 2015 DANIEL Erwan
*/

int	my_strcmp(char *s1, char *s2)
{
  int	counter;

  counter = 0;
  while (s1[counter] != '\0')
    {
      if (s1[counter] < s2[counter])
	return (s1[counter] - s2[counter]);
      else if (s1[counter] > s2[counter])
	return (s1[counter] - s2[counter]);
      counter++;
    }
  if (s1[counter] == '\0' && s2[counter] != '\0')
    return (s2[counter] * -1);
  else if (s1[counter] != '\0' && s2[counter] == '\0')
    return (s1[counter]);
  return (0);
}
