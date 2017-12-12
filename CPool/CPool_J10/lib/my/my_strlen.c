/*
** my_strlen.c for my_strlen in /home/RODRIG_1/rendu/Piscine_C_J04
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Thu Oct  2 22:37:53 2014 rodriguez gwendoline
** Last update Thu Oct  2 23:05:52 2014 rodriguez gwendoline
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
