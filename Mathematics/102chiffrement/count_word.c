/*
** count_word.c for count_word in /home/rodrig_1/rendu/Maths/102chiffrement
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Thu Nov 27 15:55:07 2014 gwendoline rodriguez
** Last update Thu Nov 27 15:55:51 2014 gwendoline rodriguez
*/

int     count_word(char *str)
{
  int   i;
  int   c;

  i = 0;
  c = 0;
  if (str[0] != ' ')
    c = c + 1;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' && (str[i + 1] != ' ' && str[i + 1] != '\0'))
	c++;
      i = i + 1;
    }
  return (c);
}
