/*
** my_putstr.c for my_putstr in /home/cubi_c/rendu/Piscine_C_colles-Semaine_02
** 
** Made by cedric cubizolle
** Login   <cubi_c@epitech.net>
** 
** Started on  Sat Oct 11 22:07:12 2014 cedric cubizolle
** Last update Sat Oct 11 22:07:20 2014 cedric cubizolle
*/

int     my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
