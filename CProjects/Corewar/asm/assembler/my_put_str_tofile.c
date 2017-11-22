/*
** creat_file.c for creat_file in /home/rodrig_1/rendu/Prgelm/CPE_2014_corewar/rodrig_1
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Tue Mar 10 14:03:57 2015 gwendoline rodriguez
** Last update Sun Apr 12 21:27:51 2015 gwendoline rodriguez
*/

#include "./../header/header.h"

int             my_putchar_tohexa2(char dest, char *src)
{
  if (my_strcmp(op_tab[8].mnemonique, src) == 0)
    dest = 0x09;
  else if (my_strcmp(op_tab[9].mnemonique, src) == 0)
    dest = 0x0a;
  else if (my_strcmp(op_tab[10].mnemonique, src) == 0)
    dest = 0x0b;
  else if (my_strcmp(op_tab[11].mnemonique, src) == 0)
    dest = 0x0c;
  else if (my_strcmp(op_tab[12].mnemonique, src) == 0)
    dest = 0x0d;
  else if (my_strcmp(op_tab[13].mnemonique, src) == 0)
    dest = 0x0e;
  else if (my_strcmp(op_tab[14].mnemonique, src) == 0)
    dest = 0x0f;
  else if (my_strcmp(op_tab[15].mnemonique, src) == 0)
    dest = 0x10;
  return (dest);
}

int		my_putchar_tohexa(char *src, int fd)
{
  char		dest;

  dest = 0;
  if (my_strcmp(op_tab[0].mnemonique, src) == 0)
    dest = 0x01;
  else if (my_strcmp(op_tab[1].mnemonique, src) == 0)
    dest = 0x02;
  else if (my_strcmp(op_tab[2].mnemonique, src) == 0)
    dest = 0x03;
  else if (my_strcmp(op_tab[3].mnemonique, src) == 0)
    dest = 0x04;
  else if (my_strcmp(op_tab[4].mnemonique, src) == 0)
    dest = 0x05;
  else if (my_strcmp(op_tab[5].mnemonique, src) == 0)
    dest = 0x06;
  else if (my_strcmp(op_tab[6].mnemonique, src) == 0)
    dest = 0x07;
  else if (my_strcmp(op_tab[7].mnemonique, src) == 0)
    dest = 0x08;
  if (dest == 0)
    dest = my_putchar_tohexa2(dest, src);
  write(fd, &dest, 1);
  return (dest);
}

int		get_byte(int i, int bin)
{
  int		hexa;

  hexa = 1;
  if (i == 1)
    i = 64;
  else if (i == 2)
    i = 16;
  else if (i == 3)
    i = 4;
  hexa = bin * i;
  return (hexa);
}

int		my_putinstruct_tochar(char **tab, int fd)
{
  char		hexa;
  int		i;

  hexa = 0;
  i = 0;
  while (i < my_strlen_tab(tab))
    {
      if (tab[i][0] == 'r')
	hexa = hexa + get_byte(i, 1);
      else if (tab[i][0] == DIRECT_CHAR)
	hexa = hexa + get_byte(i, 2);
      else if ((tab[i][0] >= '0' && tab[i][0] <= '9')
	       || tab[i][0] == LABEL_CHAR)
	hexa = hexa + get_byte(i, 3);
      i++;
    }
  write(fd, &hexa, 1);
  put_params_inhexa(tab, fd);
  return (hexa);
}

int             my_putinstruct_tofile(char *dest, char **src)
{
  int           fd;
  int		i;

  fd = -1;
  i = 0;
  if ((fd = open(dest, O_RDWR | O_CREAT | O_APPEND, 0666)) != -1)
    {
      while (i < 2)
	{
	  if ((src[i][0] == 'r'
	       && (src[i][1] >= '0' && src[i][1] <= '9'))
	      || src[i][0] == LABEL_CHAR
	      || (src[i][0] >= '0' && src[i][0] <= '9'))
	    {
	      my_putinstruct_tochar(src, fd);
	      return (0);
	    }
	  else
	      my_putchar_tohexa(src[0], fd);
	  i++;
	}
    }
  close(fd);
  return (0);
}
