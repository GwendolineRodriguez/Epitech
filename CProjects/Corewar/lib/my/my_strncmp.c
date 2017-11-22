/*
** my_strncmp.c for my_strncmp in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 18:45:51 2014 gwendoline rodriguez
** Last update Sun Mar  8 23:58:57 2015 gwendoline rodriguez
*/

int     my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i <= n)
    {
      if (s1[i] != s2[i])
	return (s1[i] != s2[i]);
      i = i + 1;
    }
  return (0);
}
