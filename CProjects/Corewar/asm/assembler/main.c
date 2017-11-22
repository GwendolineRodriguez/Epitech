/*
** hexa_to_bin.c for hexa_to_bin in /home/rodrig_1/rendu/Prgelm/CPE_2014_corewar/rodrig_1
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Thu Mar  5 18:24:50 2015 gwendoline rodriguez
** Last update Sun Apr 12 21:44:00 2015 gwendoline rodriguez
*/

#include "./../header/header.h"

int             my_error(char *str)
{
  write(2, str, my_strlen(str));
  exit(0);
}

int		check_arg(char *str)
{
  int		i;

  i = my_strlen(str) - 1;
  if (str[i] == 's' && str[i - 1] == '.')
    return (0);
  else
    my_error("The file does not finish by [.s]\n");
  return (-1);
}

void		assm(t_tab *t, char *file, char **tab)
{
  int		i;
  int		j;
  char		**cleantab;

  i = 0;
  put_header_tofile(file, tab);
  while (i < t->nb_line)
    {
      if ((cleantab = get_clean_line(tab[i])) != 0)
  	{
  	  j = 0;
  	  while (j < my_strlen_tab(cleantab))
	    j++;
  	  my_putinstruct_tofile(file, cleantab);
  	}
      i++;
    }
}

char		*get_filecor_name(char *file, char *str)
{
  int		i;

  i = 0;
  if ((file = malloc(my_strlen(str) + 2)) == NULL)
    my_error("Error on malloc");
  while (str[i] != 's')
    {
      file[i] = str[i];
      i++;
    }
  file[i] = '\0';
  file = my_strcat(file, "cor");
  return (file);
}

int		main(int ac, char **av)
{
  char		*file;
  char          **tab;
  int		i;
  t_tab		t;

  t.nb_line = 0;
  i = ac - 1;
  if (ac > 1)
    {
      while (i > 0)
	{
	  if (check_file(av[i]) == 0)
	    {
	      tab = get_file(av[i], &t);
	      file = get_filecor_name(file, av[i]);
	      assm(&t, file, tab);
	    }
	  else
	    my_error("Errors detected.\n");
	  i--;
	}
    }
  else
    my_error("Usage : ./test [file.s]\n");
  return (0);
}
