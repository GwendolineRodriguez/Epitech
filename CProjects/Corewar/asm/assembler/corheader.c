/*
** corheader.c for corheader in /home/rodrig_1/rendu/Prgelm/CPE_2014_corewar/rodrig_1
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Fri Apr 10 11:56:51 2015 gwendoline rodriguez
** Last update Sun Apr 12 17:14:26 2015 gwendoline rodriguez
*/

#include "./../header/header.h"

void		put_magic_key(int fd)
{
  unsigned char	key[4];
  int		magickey;
  int		i;

  i = 3;
  magickey = COREWAR_EXEC_MAGIC;
  while (i >= 0)
    {
      key[i] = magickey;
      magickey = magickey >> 8;
      i--;
    }
  i = 0;
  while (i < 4)
    {
      write(fd, &key[i], 1);
      i++;
    }
}

int		get_len_param(char **tab, int p)
{
  int		i;
  int		len;

  i = 0;
  len = 0;
  while (tab[p][i] != '\0')
    {
      if (tab[p][i] == '"')
	{
	  i++;
	  while (tab[p][i++] != '"')
	    len++;
	  return (len);
	}
      i++;
    }
  return (0);
}

void		fill_in(int p, int len, int fd)
{
  int		lenmax;
  char		c;

  lenmax = 0;
  c = 0;
  if (p == 0)
    lenmax = PROG_NAME_LENGTH;
  else if (p == 1)
    lenmax = COMMENT_LENGTH;
  while (++len <= lenmax)
    write(fd, &c, 1);
}

void		put_param(char **tab, int fd, int p)
{
  int		i;
  int		j;
  char		*name;
  int		len;

  i = 0;
  j = 0;
  len = 0;
  len = get_len_param(tab, p);
  if ((name = malloc(len * sizeof(char))) == NULL)
    my_error("Error on malloc.\n");
  while (i <= my_strlen(tab[p]))
    {
      if (tab[p][i] == '"')
	{
	  i++;
	  while (j < len)
	    name[j++] = tab[p][i++];
	}
      i++;
    }
  write(fd, name, len);
  fill_in(p, len, fd);
}

  int		put_header_tofile(char *dest, char **tab)
  {
    int		i;
    int		fd;

    fd = -1;
    i = 0;
    tab[i] = tab[i];
    if ((fd = open(dest, O_RDWR | O_CREAT | O_APPEND, 0666)) != -1)
      {
	put_magic_key(fd);
	put_param(tab, fd, 0);
	put_param(tab, fd, 1);
      }
    else
      my_error("Error on open.\n");
    close(fd);
    return (0);
  }
