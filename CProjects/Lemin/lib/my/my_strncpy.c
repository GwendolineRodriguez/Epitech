/*
** my_strcpy for  in /home/daniel_b/Piscine_C_J06
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Mon Oct  6 11:37:33 2014 Erwan DANIEL
** Last update Sun Feb  1 19:26:35 2015 DANIEL Erwan
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  while (*src != '\0' && n)
    {
      *dest++ = *src++;
      n--;
    }
  return (dest);
}
