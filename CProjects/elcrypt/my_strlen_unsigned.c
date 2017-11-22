/*
** my_strlen_unsigned.c for my_strlen_unsigned in /home/rodrig_1/rendu/Prgelm/elcrypt
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Sun Mar  1 18:55:31 2015 gwendoline rodriguez
** Last update Sun Mar  1 18:59:14 2015 gwendoline rodriguez
*/

int     my_strlen_unsigned(unsigned char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
