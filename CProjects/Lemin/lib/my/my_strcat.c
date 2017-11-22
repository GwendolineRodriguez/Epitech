/*
** my_strcat.c for  in /home/daniel_b/Piscine_C_J07/ex_01
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Tue Oct  7 15:52:09 2014 Erwan DANIEL
** Last update Sat Jan 17 16:16:43 2015 DANIEL Erwan
*/

char	*my_strcat(char *dest, char *src)
{
  int	counter;
  int	end_of_dest;

  end_of_dest = 0;
  counter = 0;
  while (dest[end_of_dest] != '\0')
    end_of_dest++;
  while (src[counter] != '\0')
    {
      dest[end_of_dest + counter] = src[counter];
      counter++;
    }
  return (dest);
}
