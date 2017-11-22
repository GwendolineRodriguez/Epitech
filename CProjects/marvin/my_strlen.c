/*
** my_strlen.c for my strlen in /home/kerebe_p/git/Piscine_C_J04
** 
** Made by Paul Kerebel
** Login   <kerebe_p@epitech.net>
** 
** Started on  Thu Oct  2 16:34:36 2014 Paul Kerebel
** Last update Mon Oct 20 13:44:12 2014 Paul Kerebel
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
