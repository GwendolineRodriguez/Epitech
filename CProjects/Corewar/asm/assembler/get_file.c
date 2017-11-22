/*
** main.c for main in /home/backou_a/rendu/CPE_2014_corewar/arthur
**
** Made by arthur backouche
** Login   <backou_a@epitech.net>
**
** Started on  Thu Mar  5 17:27:47 2015 arthur backouche
** Last update Sun Apr 12 17:15:00 2015 gwendoline rodriguez
*/

#include "./../header/header.h"

int	browse_file(int fd)
{
  char	buf[READ_MAX + 1];
  int	save;
  int	cpt;
  int	line;

  cpt = 0;
  line = 0;
  if ((save = read(fd, buf, READ_MAX)) == 0)
    my_error("Error on read.\n");
  while (cpt < save)
    {
      if (buf[cpt] == '\n')
	line++;
      cpt++;
    }
  return (line);
}

char	**get_file(char *file, t_tab *t)
{
  char	**tab;
  char	*line;
  int	fd;
  int	i;

  if ((fd = open(file, O_RDONLY)) == -1)
    my_error("This file does not exists.\n");
  t->nb_line = browse_file(fd);
  lseek(fd, 0, SEEK_SET);
  if (((tab = malloc((t->nb_line) *sizeof(char *))) == NULL))
    {
      close(fd);
      return (NULL);
    }
  i = 0;
  while ((line = get_next_line(fd)) != NULL)
    {
      tab[i] = line;
      i++;
    }
  tab[i] = NULL;
  close(fd);
  return (tab);
}
