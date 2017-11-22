/*
** put_params_inhexa.c for put_params_inhexa in /home/rodrig_1/rendu/Prgelm/CPE_2014_corewar/rodrig_1
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Thu Apr  9 22:29:24 2015 gwendoline rodriguez
** Last update Sun Apr 12 17:15:54 2015 gwendoline rodriguez
*/

#include "./../header/header.h"

void		get_register_nb(char **tab, int fd, int i)
{
  char		hexa;
  char		*nbregist;
  int		x;
  int		j;

  hexa = 0;
  x = 1;
  j = 0;
  if ((nbregist = malloc(my_strlen(tab[i]) * sizeof(char) + 1)) == NULL)
    my_error("Error on malloc.\n");
  while (tab[i][x] != '\0')
    {
      nbregist[j] = tab[i][x];
      x++;
      j++;
    }
  nbregist[j] = '\0';
  hexa = my_getnbr(nbregist);
  write(fd, &hexa, 1);
}

void            get_direct(char **tab, int fd, int i)
{
  char		hexa;
  char		*nbdir;
  int		x;
  int		j;

  hexa = 0;
  x = 1;
  j = 1;
  if ((nbdir = malloc(my_strlen(tab[i]) * sizeof(char))) == NULL)
    my_error("Error on malloc.\n");
  while (j < DIR_SIZE)
    {
      write(fd, &hexa, 1);
      j++;
    }
  j = 0;
  while (tab[i][x] != '\0')
    {
      nbdir[j] = tab[i][x];
      j++;
      x++;
    }
  hexa = my_getnbr(nbdir);
  write(fd, &hexa, 1);
}

void            get_indirect(char **tab, int fd, int i)
{
  char		hexa;
  int		j;

  hexa = 0;
  j = 1;
  while (j < IND_SIZE)
    {
      write(fd, &hexa, 1);
      j++;
    }
  hexa  = my_getnbr(tab[i]);
  write(fd, &hexa, 1);
}

int		put_params_inhexa(char **tab, int fd)
{
  int		i;

  i = 0;
  while (i < my_strlen_tab(tab))
    {
      if (tab[i][0] == 'r')
	get_register_nb(tab, fd, i);
      else if (tab[i][0] == DIRECT_CHAR)
	get_direct(tab, fd, i);
      else if ((tab[i][0] >= '0' && tab[i][0] <= '9')
	       || tab[i][0] == LABEL_CHAR)
	get_indirect(tab, fd, i);
      i++;
    }
  return (0);
}
