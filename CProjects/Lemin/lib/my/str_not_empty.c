/*
** str_not_empty.c for  in /home/daniel_b/Rendu/PSU_2014_42sh/daniel_b/lib/my
** 
** Made by DANIEL Erwan
** Login   <daniel_b@epitech.net>
** 
** Started on  Tue Apr  7 16:40:50 2015 DANIEL Erwan
** Last update Tue Apr  7 16:58:21 2015 DANIEL Erwan
*/

int	str_not_empty(char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != 0)
    {
      if (str[i] != ' ' && str[i] != '\t')
	return (1);
      i++;
    }
  return (0);
}
