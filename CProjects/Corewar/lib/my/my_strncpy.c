/*
** my_strncpy.c for my_strncpy in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 17:57:13 2014 gwendoline rodriguez
** Last update Tue Nov 18 17:58:20 2014 gwendoline rodriguez
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int   i;

  i = 0;
  while (src[i] && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (!src [n - 1])
    dest[i] = '\0';
  return (dest);
}
