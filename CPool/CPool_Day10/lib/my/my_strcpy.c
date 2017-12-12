/*
** my_strcpy.c for my_strcpy in /home/RODRIG_1/rendu/Piscine_C_J06
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Mon Oct  6 09:56:54 2014 rodriguez gwendoline
** Last update Tue Oct  7 10:22:00 2014 rodriguez gwendoline
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
  return dest;
}
