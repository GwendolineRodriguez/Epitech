/*
** my_strcmp.c for my_strcmp in /home/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 18:41:54 2014 gwendoline rodriguez
** Last update Mon Nov 24 17:18:38 2014 gwendoline rodriguez
*/

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i])
    {
      if (s1[i] < s2[i])
        return (-1);
      if (s1[i] > s2[i])
        return (1);
      i++;
    }
  if (s1[i] < s2[i])
    return (-1);
  if (s1[i] > s2[i])
    return (1);
  return (0);
}
