/*
** main.c for main in /home/gwendoline/rendu/Piscine_Synthese/genealogie
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jul  2 11:03:05 2015 Gwendoline Rodriguez
** Last update Sat Jul  4 16:35:38 2015 Gwendoline Rodriguez
*/

#include "header.h"

char		**get_family(DIR *fd, char *str, char *name, char **tab)
{
  char          *buffer;
  int           i;
  struct dirent *tmp;

  i = 0;
  tmp = readdir(fd);
  tab[0] = strdup("false");
  if ((buffer = malloc(sizeof(char) * 500)) == NULL)
    return (0);
  while (tmp)
    {
      if (strcmp(name, tmp->d_name) == 0)
        tab[0] = strdup("true");
      if (tmp->d_name[0] != '.')
        {
          strcpy(buffer, str);
          strcat(buffer, tmp->d_name);
          tab[++i] = strdup(buffer);
        }
      tmp = readdir(fd);
    }
  tab[i + 1] = NULL;
  return (tab);
}

char		*search_family(char *str, char *name)
{
  char		**tab;
  DIR		*fd;
  int		i;

  if ((fd = opendir(str)) == NULL)
    return (0);
 if ((tab = malloc(sizeof(char) * 500)) == 0)
    return (NULL);
  if (str[strlen(str) - 1] != '/')
    strcat(str, "/");
  tab = get_family(fd, str, name, tab);
  if (strcmp(tab[0], "true") == 0)
    return (str);
  i = 0;
  while (tab[++i])
    if ((str = search_family(tab[i], name)) != NULL)
      return (str);
  closedir(fd);
  return (NULL);
}

int		main(int ac, UNUSED char **av)
{
  t_individu	*individu;
  char		*buffer;
  int		ret;

  if (ac == 3)
    {
      buffer = malloc(sizeof(char) * BUFF_MAX);
      if ((ret = (read(0, buffer, BUFF_MAX))) == -1 && ret != 0)
        return (0);
      buffer[ret - 1] = '\0';
      individu = init_param();
      individu->option = buffer;
      individu->name = strdup(av[2]);
      individu->rep = strdup(av[1]);
      individu->family = search_family(individu->rep, individu->name);
      if (individu->family == NULL)
	put_error("! Famille incorrecte !\n");
      else
	{
	  strcpy(individu->file, individu->family);
	  individu->file = strcat(individu->file, individu->name);
	  individu = get_info(individu);
	  get_genealogy(individu);
	}
    }
  return (0);
}
