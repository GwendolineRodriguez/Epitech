/*
** my_strncpy.c for my_strncpy in /home/RODRIG_1/rendu/Piscine_C_J06
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Mon Oct  6 14:22:09 2014 rodriguez gwendoline
** Last update Mon Oct 20 13:13:13 2014 rodriguez gwendoline
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
