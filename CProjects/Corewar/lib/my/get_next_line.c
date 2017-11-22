/*
** get_next_line.c for get_next_line in /home/rodrig_1/rendu/Prgelm/CPE_2014_corewar/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Wed Apr  8 23:52:48 2015 gwendoline rodriguez
** Last update Sun Apr 12 22:58:23 2015 gwendoline rodriguez
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define READ_MAX 5

int             my_len(char *str)
{
  int           i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char            *my_realloc(char *old, int size)
{
  int           i;
  char          *new;

  i = 0;
  if ((new = malloc(sizeof(*new) * (my_len(old) + size))) == NULL)
    return (NULL);
  while (old[i])
    {
      new[i] = old[i];
      i++;
    }
  free(old);
  return (new);
}

char            *get_next_line(const int fd)
{
  static int    last = 1;
  static int    rd = 0;
  static int    i = 0;
  static char   *rs = NULL;
  static char   buf[READ_MAX];

  if (buf[my_len(buf) - rd] == '\0')
    {
      if ((rd = read(fd, buf, READ_MAX)) <= 0)
        return (rs = (last-- && buf[my_len(buf) - rd - 1] != 10) ? rs : NULL);
      buf[rd] = '\0';
    }
  if ((rs = (i == 0) ? malloc(sizeof(*rs) * READ_MAX + 1) :
       my_realloc(rs, sizeof(*rs) * READ_MAX + 1)) == NULL)
    return (NULL);
  while (buf[my_len(buf) - rd] && buf[my_len(buf) - rd] != '\n')
    rs[i++] = buf[my_len(buf) - rd--];
  rs[i] = '\0';
  if (buf[my_len(buf) - rd] == '\n')
    {
      i = 0;
      rd--;
      return (rs);
    }
  return (get_next_line(fd));
}
