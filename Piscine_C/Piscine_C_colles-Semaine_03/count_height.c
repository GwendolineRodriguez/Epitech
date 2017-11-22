/*
** count_height.c for count_height in /home/maure_d/rendu/Piscine_C_colles-Semaine_03
** 
** Made by Damien MAURE
** Login   <maure_d@epitech.net>
** 
** Started on  Sat Oct 25 20:54:54 2014 Damien MAURE
** Last update Sat Oct 25 21:36:43 2014 Damien MAURE
*/

int     count_height(char *str, int i, int height)
{
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
        height = height + 1;
      i = i + 1;
    }
  return (height);
}
