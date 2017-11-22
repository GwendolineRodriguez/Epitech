/*
** my_putstr for  in /home/daniel_b
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Thu Oct  2 11:45:23 2014 Erwan DANIEL
** Last update Sat Jan 17 16:11:22 2015 DANIEL Erwan
*/

int	my_putstr(char *str)
{
  while (*str != '\0')
    {
      write(1, str, 1);
      str = str + sizeof (char);
    }
  return (0);
}
