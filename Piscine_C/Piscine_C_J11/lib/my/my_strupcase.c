/*
** my_strupcase.c for my_strupcase in /home/RODRIG_1/rendu/Piscine_C_J06/ex_07
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Mon Oct  6 22:51:49 2014 rodriguez gwendoline
** Last update Wed Oct  8 12:59:26 2014 rodriguez gwendoline
*/

char     *my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] = str[i] - 32;
      i = i + 1;
    }
  return str;
}
