/*
** my_strcmp.c for  in /home/daniel_b/Piscine_C_J06
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Tue Oct  7 09:21:56 2014 Erwan DANIEL
** Last update Sun Feb  1 23:40:32 2015 DANIEL Erwan
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	counter;

  counter = 0;
  while (s1[counter] != '\0' && counter != n)
    {
      if (s1[counter] < s2[counter])
	{
	  return (s1[counter] - s2[counter]);
	}
      else if (s1[counter] > s2[counter])
	{
	  return (s1[counter] - s2[counter]);
	}
      counter++;
    }
  if (s1[counter] == '\0' && s2[counter] != '\0')
    {
      return (s2[counter] * -1);
    }
  else if (s1[counter] != '\0' && s2[counter] == '\0')
    {
      return (s1[counter]);
    }
  return (0);
}
