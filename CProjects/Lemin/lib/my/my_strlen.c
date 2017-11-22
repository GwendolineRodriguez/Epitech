/*
** my_strlen for  in /home/daniel_b
** 
** Made by Erwan DANIEL
** Login   <daniel_b@epitech.net>
** 
** Started on  Thu Oct  2 11:45:23 2014 Erwan DANIEL
** Last update Mon Apr 27 19:16:07 2015 Bastien Rougé
*/

int	my_strlen(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter] != '\0')
    counter++;
  return (counter);
}
