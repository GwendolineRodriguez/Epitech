/*
** my_strcmp.c for my_strcmp in /home/gwendoline/rendu/Prgelm/colles/boogle/gwen
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jun  5 18:24:38 2015 
** Last update Fri Jun  5 18:29:41 2015 
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] == s2[i])
	i++;
      else
	return (1);
    }
  if (s2[i] != '\0')
    return (1);
  return (0);
}
