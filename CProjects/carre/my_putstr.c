/*
** my_putstr.c for carre in /home/faure-_l/Colle_carre/carre/lolo
** 
** Made by Loik Fauré-Berlinguette
** Login   <faure-_l@epitech.net>
** 
** Started on  Tue May  5 10:08:45 2015 Loik Fauré-Berlinguette
** Last update Tue May  5 10:09:36 2015 Loik Fauré-Berlinguette
*/

int	my_putstr(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      my_putchar(s[i]);
      i++;
    }
  return (0);
}
