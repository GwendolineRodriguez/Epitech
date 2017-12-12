/*
** my_strcat.c for my_strcat in /home/RODRIG_1/rendu/Piscine_C_J07/lib/my
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Tue Oct  7 17:59:22 2014 rodriguez gwendoline
** Last update Thu Oct  9 09:38:43 2014 rodriguez gwendoline
*/

char	*my_strcat(char *dest, char *src)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    {
      i = i + 1;
    }

  while (src[j] != '\0')
    {
      dest[i] = src[j];
      j = j + 1;
    }
  dest[i] = '\0';
  return (dest);
}
