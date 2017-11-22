/*
** my_strcmp.c for my strcmp in /home/kerebe_p/git/Piscine_C_J06
** 
** Made by Paul Kerebel
** Login   <kerebe_p@epitech.net>
** 
** Started on  Mon Oct  6 17:09:22 2014 Paul Kerebel
** Last update Wed Oct  8 19:01:48 2014 Paul Kerebel
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] > s2[i])
        {
          return (1);
        }
      if (s1[i] < s2[i])
        {
          return (-1);
        }
      i = i + 1;
    }
  return (0);
}
