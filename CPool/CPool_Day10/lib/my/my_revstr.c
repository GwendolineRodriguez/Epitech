/*
** my_revstr.c for my_revstr in /home/RODRIG_1/rendu/Piscine_C_J06/ex_03
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Mon Oct  6 17:25:17 2014 rodriguez gwendoline
** Last update Tue Oct  7 11:26:16 2014 rodriguez gwendoline
*/

char    *my_revstr(char *str)
{
  int   i;
  int	j;
  char	c;

  i = 0;
  j = my_strlen(str) - 1;
  while (i < j)
    {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
      i = i + 1;
      j = j - 1;
    }
  return str;
}
