/*
** my_strncat.c for my_strncat in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 19:19:45 2014 gwendoline rodriguez
** Last update Tue Nov 18 19:19:46 2014 gwendoline rodriguez
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
