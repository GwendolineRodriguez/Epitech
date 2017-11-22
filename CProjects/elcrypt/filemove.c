/*
** my_put_file_by8.c for my_put_file_by8 in /home/rodrig_1/rendu/Prgelm/elcrypt
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Sat Feb 28 18:05:48 2015 gwendoline rodriguez
** Last update Sun Mar  1 20:44:39 2015 gwendoline rodriguez
*/

#include "structs.h"
#include "my.h"

int		my_put_str_tofile(unsigned char *src, char *dest)
{
  int		fd;

  fd = -1;
  fd = open(dest, O_RDWR | O_CREAT | O_APPEND, 0666);
  if (fd != -1)
    {
      write(fd, src, my_strlen_unsigned(src));
      close(fd);
    }
  return (0);
}

int		my_send_file_by8(t_data *p, t_file *f)
{
  f->fd = open(p->filesrc, O_RDONLY);
  while (p->filesrc[f->i] != '\0')
    {
      f->ret = read(f->fd, f->buffer, 8);
      if (f->ret < 8 && f->ret != -1)
	{
	  while (f->ret <= 8)
	    {
	      f->buffer[f->ret] = 0x06;
	      f->ret++;
	    }
	  f->check = 1;
	}
      f->buffer[8] = '\0';
      choose_crypt(p, f);
      my_put_str_tofile(p->res, p->filedest);
      f->i += 8;
      if (f->check == 1)
	return (0);
    }
  if (f->fd >= 3)
    close(f->fd);
  return (0);
}
