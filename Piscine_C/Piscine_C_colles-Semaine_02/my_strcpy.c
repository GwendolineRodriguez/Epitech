/*
** my_strcpy.c for my_strcpy in /home/cubi_c/rendu/Piscine_C_colles-Semaine_02
** 
** Made by cedric cubizolle
** Login   <cubi_c@epitech.net>
** 
** Started on  Sat Oct 11 22:07:37 2014 cedric cubizolle
** Last update Sat Oct 11 22:58:00 2014 cedric cubizolle
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
