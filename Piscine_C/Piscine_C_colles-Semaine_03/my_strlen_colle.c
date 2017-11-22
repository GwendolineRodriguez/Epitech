/*
** my_strlen_colle.c for my_strlen_colle in /home/maure_d/rendu/Piscine_C_colles-Semaine_03
** 
** Made by Damien MAURE
** Login   <maure_d@epitech.net>
** 
** Started on  Sat Oct 25 20:16:36 2014 Damien MAURE
** Last update Sat Oct 25 20:17:48 2014 Damien MAURE
*/

int	my_strlen_colle(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\n')
    {
      i = i + 1;
    }
  return (i);
}
