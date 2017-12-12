/*
** colle3.c for colle3 in /home/maure_d/rendu/Piscine_C_colles-Semaine_03
** 
** Made by Damien MAURE
** Login   <maure_d@epitech.net>
** 
** Started on  Sat Oct 25 18:33:59 2014 Damien MAURE
** Last update Sat Oct 25 23:24:55 2014 Damien MAURE
*/

#include <unistd.h>
#define BUFF_SIZE (4096)

int	colle1_1(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == 'o')
	{
	  my_putstr("[colle1-1]");
	  my_putchar(' ');
	  my_putchar('[');
	  my_put_nbr(my_strlen_colle(str));
	  my_putchar(']');
	  my_putchar(' ');
	  my_putchar('[');
	  my_put_nbr(count_height(str, i, 0));
	  my_putchar(']');
	  return (0);
	}
      i = i + 1;
    }
}

int	colle1_2(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '*')
        {
          my_putstr("[colle1-2]");
	  my_putchar(' ');
	  my_putchar('[');
          my_put_nbr(my_strlen_colle(str));
          my_putchar(']');
	  my_putchar(' ');
          my_putchar('[');
          my_put_nbr(count_height(str, i, 0));
          my_putchar(']');
          return (0);
        }
      i = i + 1;
    }
}

int	colle1_3(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  if (str[0] == 'A' && str[my_strlen_colle(str) - 1] == 'A' && str[i - 2] == 'C')
    {
      my_putstr("[colle1-3]");
      my_putchar(' ');
      my_putchar('[');
      my_put_nbr(my_strlen_colle(str));
      my_putchar(']');
      my_putchar(' ');
      my_putchar('[');
      my_put_nbr(count_height(str, i, 0));
      my_putchar(']');
      return (0);
    }
}

int     colle1_4(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  if (str[0] == 'A' && str[my_strlen_colle(str) - 1] == 'C' && str[i - 2] == 'C')
    {
      my_putstr("[colle1-4]");
      my_putchar(' ');
      my_putchar('[');
      my_put_nbr(my_strlen_colle(str));
      my_putchar(']');
      my_putchar(' ');
      my_putchar('[');
      my_put_nbr(count_height(str, i, 0));
      my_putchar(']');
      return (0);
    }
}

int     colle1_5(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  if (str[0] == 'A' && str[my_strlen_colle(str) - 1] == 'C' && str[i - 2] == 'A')
    {
      my_putstr("[colle1-5]");
      my_putchar(' ');
      my_putchar('[');
      my_put_nbr(my_strlen_colle(str));
      my_putchar(']');
      my_putchar(' ');
      my_putchar('[');
      my_put_nbr(count_height(str, i, 0));
      my_putchar(']');
      return (0);
    }
}
