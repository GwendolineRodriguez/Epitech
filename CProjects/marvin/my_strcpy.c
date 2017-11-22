/*
** my_strcpy.c for my strcpy in /home/kerebe_p/git/Piscine_C_J06
** 
** Made by Paul Kerebel
** Login   <kerebe_p@epitech.net>
** 
** Started on  Mon Oct  6 09:39:34 2014 Paul Kerebel
** Last update Mon Oct  6 11:19:46 2014 Paul Kerebel
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
