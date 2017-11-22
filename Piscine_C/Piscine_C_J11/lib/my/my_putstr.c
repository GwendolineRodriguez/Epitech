/*
** my_putstr.c for my_putstr in /home/RODRIG_1/rendu/Piscine_C_J04
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Thu Oct  2 18:10:42 2014 rodriguez gwendoline
** Last update Thu Oct  2 22:33:40 2014 rodriguez gwendoline
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
