/*
** my_strncmp.c for my_strncmp in /home/RODRIG_1/rendu/Piscine_C_J06/ex_06
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Mon Oct  6 22:50:40 2014 rodriguez gwendoline
** Last update Tue Oct  7 12:04:02 2014 rodriguez gwendoline
*/

int     my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i < 0)
    {
      if (s1[i] != s2[i])
	return (s1[i] != s2[i]);
      i = i + 1;
    }
  return (0);
}
