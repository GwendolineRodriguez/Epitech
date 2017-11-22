/*
** cat.c for cat in /home/rodrig_1/rendu/Piscine_C_J13/cat
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Nov 18 13:35:57 2014 gwendoline rodriguez
** Last update Tue Nov 18 13:36:01 2014 gwendoline rodriguez
*/

#include <fcntl.h>
#include <errno.h>

int     infinite()
{
  int   ret;
  char  buffer[30000];

  while (1)
    {
      ret = read(0, buffer, 30000);
      buffer[ret] = '\0';
      if (ret == 0)
	return (0);
      my_putstr(buffer);
    }
}

void	error(char **argv, int i, int errsv)
{
  if (argv[i][0] == '-')
    infinite();
  else if (errsv == EACCES)
    {
      write(2, "cat: ", 5);
      write(2, argv[i], my_strlen(argv[i]));
      write(2, ": Permission denied\n", 20);
    }
  else if (errsv == ENOENT)
    {
      write(2, "cat: ", 5);
      write(2, argv[i], my_strlen(argv[i]));
      write(2, ": No such file or directory\n", 28);
    }
  else if (errsv == EISDIR)
    {
      write(2, "cat: ", 5);
      write(2, argv[i], my_strlen(argv[i]));
      write(2, ": Is a directory\n", 17);
    }
}

int     main(int argc, char **argv)
{
  int	err;
  int   i;
  int   fd;
  int   ret;
  char  buffer[30000];

  i = 1;
  if (argc == 1)
    infinite();
  while (i < argc)
    {
      fd = open(argv[i], O_RDONLY);
      if (fd == -1)	err = 1;
      ret = read(fd, buffer, 30000);
      buffer[ret] = '\0';
      if (ret == -1)
	err = 1;
      if (err == 1)
	error(argv, i, errno);
      else
	my_putstr(buffer);
      close(fd);
      i = i + 1;
    }
}
