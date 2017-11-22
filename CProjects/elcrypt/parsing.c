/*
** my_parsing.c for my_parsing in /home/rodrig_1/rendu/Prgelm/elcrypt
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Fri Feb 27 23:07:46 2015 gwendoline rodriguez
** Last update Sun Mar  1 20:16:11 2015 gwendoline rodriguez
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include <unistd.h>
#include "structs.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void		my_parse2(char **av, t_data *p)
{
  int           i;
  int		check;

  i = 0;
  check = 0;
  while (av[i])
    {
      if ((my_strcmp("-f", av[i]) == 0) && av[i + 1] != NULL)
	{
	  check = open(av[i + 1], O_RDONLY);
	  if (check >= 3)
	    {
	      p->filesrc = av[i + 1];
	      p->check += 1;
	      close(check);
	    }
	  else
	    my_error("The file you entered does not exist.\n");
	}
      i++;
    }
}

void             my_parse1(char **av, t_data *p)
{
  int           i;

  i = 0;
  while (av[i])
    {
      if ((my_strcmp("-k", av[i])  == 0) && av[i + 1] != NULL)
	check_key(av[i + 1], p);
      else if ((my_strcmp("-o", av[i]) == 0) && av[i + 1] != NULL)
	{
	  p->filedest = av[i + 1];
	  p->check += 2;
	}
      else if (my_strcmp("-d", av[i]) == 0)
	{
	  p->crypt = 2;
	  p->check += 8;
	}
      else if (my_strcmp("-e", av[i]) == 0)
	{
	  p->crypt = 1;
	  p->check += 8;
	}
      i++;
    }
}

int             parsing(char **av)
{
  t_data	p;
  t_file	f;

  p.crypt = 0;
  p.filesrc = NULL;
  p.filedest = NULL;
  p.base = NULL;
  p.key = NULL;
  p.check = 0;
  if ((p.res = malloc(sizeof(unsigned char) * 9)) == NULL)
    exit(0);
  p.res[9] = '\0';
  p.res[0] = '\0';
  f.i = 0;
  f.fd = -1;
  f.ret = -1;
  f.check = 0;
  my_parse1(av, &p);
  my_parse2(av, &p);
  if (p.check == 15)
    my_send_file_by8(&p, &f);
  else
    my_error("You have not given all the necessary options.");
  return (0);
}
