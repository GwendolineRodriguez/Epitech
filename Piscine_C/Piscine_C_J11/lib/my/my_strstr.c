/*
** my_strstr.c for my_strstr in /home/RODRIG_1/rendu/Piscine_C_J06/ex_04
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Mon Oct  6 22:11:37 2014 rodriguez gwendoline
** Last update Mon Oct 20 13:15:10 2014 rodriguez gwendoline
*/

char     *my_strstr(char *str, char *to_find)
{
  int   i;
  int	n;

  i = 0;
  n = 0;
  while (str[i])
    {
      if (str[i] == to_find[n])
	n = n + 1;
      else
	n = 0;
      if (!to_find[n])
	{
	  i = i - (n - 1);
	  return (str + 1);
	}
      i = i + 1;
    }
  return (0);
}
