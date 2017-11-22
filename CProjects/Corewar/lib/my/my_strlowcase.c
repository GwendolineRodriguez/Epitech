/*
** my_strlowcase.c for my_strlowcase in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 19:35:13 2014 gwendoline rodriguez
** Last update Sun Mar  8 23:56:57 2015 gwendoline rodriguez
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
  return (str);
}
