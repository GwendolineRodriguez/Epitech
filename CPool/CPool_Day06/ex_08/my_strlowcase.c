/*
** my_strlowcase.c for my_strlowcase in /home/RODRIG_1/rendu/Piscine_C_J06/ex_08
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Mon Oct  6 22:53:04 2014 rodriguez gwendoline
** Last update Tue Oct  7 14:41:31 2014 rodriguez gwendoline
*/

char     *my_strlowcase(char *str)
{
  int	i;

  i = 0; 
  while (str[i] >= 'A' && str[i] <= 'Z')
    {
      str[i] = str[i] + 32;
      i = i + 1;
    }
}
