/*
** main.c for SBMLparser in /home/gwendoline/rendu/Piscine_Synthese
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jun 15 13:45:20 2015 
** Last update Wed Jun 17 21:27:04 2015 
*/

#include "./../header.h"

void            display_spec(t_param *p)
{
  my_putstr("species\n");
  if (p->data->spec_compartment == 1)
    my_putstr("----->compartment\n");
  if (p->data->spec_id == 1)
    my_putstr("----->id\n");
  if (p->data->spec_name == 1)
    my_putstr("----->name\n");
}

void            display_specr(t_param *p)
{
  my_putstr("speciesReference\n");
  if (p->data->specr_species == 1)
    my_putstr("----->species\n");
  if (p->data->specr_stoi == 1)
    my_putstr("----->stoichiometry\n");
}

void		check_opt(char **av, char *str, t_param *p, int i)
{
  while (av[++i] != NULL)
    {
      if (my_strcmp(av[i], "-i") == 0 && av[i + 1] != NULL
	  && my_strcmp(av[i + 1], "-e") != 0
	  && my_strcmp(av[i + 1], "-json") != 0
	  && my_strcmp(av[i + 1], "-gui") != 0)
	p->data->check_i = 1;
      else if (my_strcmp(av[i], "-e") == 0)
	p->data->check_e = 1;
      else if (my_strcmp(av[i], "-json") == 0)
	p->data->check_json = 1;
      else
	put_error("Fichier incorrect\n");
    }
  i = 1;
  while (av[++i] != NULL)
    {
      if (my_strcmp(av[i], "-e") == 0)
        {
          if (p->data->check_i == 0)
            put_error("Fichier incorrect\n");
        }
    }
}

int		open_file(int ac, char **av)
{
  int		fd;
  char		buffer[4096];
  char		*line;
  t_param	*p;

  fd = open(av[1], O_RDONLY);
  p = init_param();
  if (ac > 2)
    check_opt(av, line, p, 1);
  if (fd > 0)
    {
      while (line = get_next_line(fd))
	{
	  if (ac > 1)
	    parser(line, p);
	}
    }
  display_data(p);
  close(fd);
  return (0);
}

int		main(int ac, char **av)
{
  if (ac > 1)
    open_file(ac, av);
  else
    put_error("Fichier incorrect\n");
  return (0);
}
