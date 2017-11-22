/*
** my_strcmp.c for my_strcmp in /home/RODRIG_1/rendu/Piscine_C_J06/ex_05
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Mon Oct  6 22:47:36 2014 rodriguez gwendoline
** Last update Fri Oct 10 12:02:14 2014 rodriguez gwendoline
*/

int     my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i])
    {
      if (s1[i] < s2[i])
	{
	  return (-1);
	}
      if (s1[i] > s2[i])
	{
	  return (1);
	}
      i = i + 1;
    }
  if (s1[i] < s2[i])
    return (-1);
  if (s1[i] > s2[i])
    return (1);
  return (0);
}
