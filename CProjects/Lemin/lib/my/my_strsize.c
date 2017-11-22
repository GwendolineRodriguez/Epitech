/*
** my_strsize.c for  in /home/daniel_b/Rendu/PSU_2014_minishell1/lib/my
** 
** Made by DANIEL Erwan
** Login   <daniel_b@epitech.net>
** 
** Started on  Mon Jan 26 23:28:46 2015 DANIEL Erwan
** Last update Mon Jan 26 23:37:36 2015 DANIEL Erwan
*/

int	my_strsize(char *str)
{
  int	size;

  size = 0;
  while (str[size++]);
  return (size);
}
