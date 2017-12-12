/*
** my_strncat.c for my_strncat in /home/RODRIG_1/rendu/Piscine_C_J07/lib/my
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Tue Oct  7 17:59:43 2014 rodriguez gwendoline
** Last update Wed Oct  8 13:20:20 2014 rodriguez gwendoline
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    {
      i = i + 1;
    }

  while (src[j] != '\0' || j <= nb)
    {
      dest[i] = src[j];
      j = j + 1;
    }
  dest[i] = '\0';
  return (dest);
}
