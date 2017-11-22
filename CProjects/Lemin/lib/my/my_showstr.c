/*
** my_showstr.c for  in /home/daniel_b/Piscine_C_J07/lib/my
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Tue Oct  7 15:34:23 2014 Erwan DANIEL
** Last update Sat Jan 17 16:12:51 2015 DANIEL Erwan
*/

int	my_showstr(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter] != '\0')
    {
      write(1, str[counter], 1);
      counter++;
    }
  return (0);
}
