/*
** colle2-04.c for colle2-04 in /home/cubi_c/rendu/Piscine_C_colles-Semaine_02/tests
** 
** Made by cedric cubizolle
** Login   <cubi_c@epitech.net>
** 
** Started on  Sat Oct 11 15:30:51 2014 cedric cubizolle
** Last update Sun Oct 12 09:31:37 2014 cedric cubizolle
*/

#include <stdlib.h>
#include <unistd.h>

int	more_space(int n, int max)
{
  while (n <= max)
    {
      my_putchar(' ');
      n = n + 1;
    }
}

int	less_space(int n)
{
  while (n != 0)
    {
      my_putchar(' ');
      n = n - 1;
    }
}

char	*string(char *str, int n, int max)
{
  int	i;

  i = 0;
  while (1)
    {
      if (n < max)
	{
	  while (str[i] != '\0')
	    {
	      my_putchar(str[i]);
	      more_space(n, max);
	      i = i + 1;
	    }
        }
      else
	{
	  while (str[i] != '\0')
            {
              my_putchar(str[i]);
              less_space(5);
              i = i + 1;
            }
	}
      usleep(100000);
    }
}

int	main(int argc, char **argv)
{
  if (argc == 2)
    string(argv[1], 0, 5);
}
