/*
** elcrypt.c for elcrypt in /home/rodrig_1/rendu/Prgelm/elcrypt
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Fri Feb 27 20:55:57 2015 gwendoline rodriguez
** Last update Sun Mar  1 23:12:00 2015 gwendoline rodriguez
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include <unistd.h>
#include "structs.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void		my_error(char *str)
{
  write(2, str, my_strlen(str));
  exit(0);
}

int             choose_crypt(t_data *p, t_file *f)
{
  if (p->crypt == 1)
    p->res = encrypt(p, f);
  else
    my_error("Only option '-e' works.");
  return (0);
}

int             check_parse(char **av)
{
  int           i;
  int           c;

  i = 0;
  c = 0;
  while (av[i] != '\0')
    {
      if (my_strncmp("-", av[i], 1) == 0)
	c++;
      i++;
    }
  if (c == 4)
    parsing(av);
  else
    my_error("You have to put 4 options.");
  return (0);
}

int		main(int ac, char **av)
{
  if (ac == 8)
    check_parse(av);
  else
    {
      my_putstr("Usage : ./elcrypt [option] [file or key]\n");
      my_putstr("Options to put :\n");
      my_putstr("-e or -d : choose between encryption or decrytion.\n");
      my_putstr("-f [file] : file you want to encrypt/decrypt.\n");
      my_putstr("-o [file] : name of the file encrypted/decrypted.\n");
      my_putstr("-k [key] : hexa, decimal, octal, binary or ascii key.\n");
    }
  return (0);
}
