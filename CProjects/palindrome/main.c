/*
** main.c for main in /home/gwendoline/rendu/Piscine_Synthese/palindrome
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jun 26 12:15:16 2015 
** Last update Sat Jun 27 16:54:06 2015 Gwendoline Rodriguez
*/

#include "header.h"

char		*get_charbase(int nb)
{
  char		*base;

  if (nb == 2)
    base = my_strdup("01");
  if (nb == 3)
    base = my_strdup("012");
  if (nb == 4)
    base = my_strdup("0123");
  if (nb == 5)
    base = my_strdup("01234");
  if (nb == 6)
    base = my_strdup("012345");
  if (nb == 7)
    base = my_strdup("0123456");
  if (nb == 8)
    base = my_strdup("01234567");
  if (nb == 9)
    base = my_strdup("012345678");
  if (nb == 10)
    base = my_strdup("0123456789");
  return (base);
}

int		main(int ac, char **av)
{
  t_param		*p;

  p = init_param();
  if (ac > 2 && ac < 7)
    {
      get_opt(av, p);
      show_palindrome(p);
    }
  else
    put_error("argument invalide\n");
  return (0);
}
