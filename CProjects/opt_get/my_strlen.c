/*
** my_strlen.c for my_strlen in /home/gwendoline/rendu/Prgelm/colles/opt_get/gwen
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Mon May 25 18:13:00 2015 
** Last update Mon May 25 18:13:41 2015 
*/

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}
