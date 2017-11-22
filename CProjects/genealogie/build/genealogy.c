/*
** genealogy.c for genealogy in /home/gwendoline/rendu/Piscine_Synthese/genealogie
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jul  3 09:19:31 2015 Gwendoline Rodriguez
** Last update Sat Jul  4 18:11:25 2015 Gwendoline Rodriguez
*/

#include "header.h"

int             my_files(char *str)
{
  DIR           *fd;
  struct dirent *tmp;
  char          **tab;
  int           i;

  i = -1;
  if ((fd = opendir(str)) == NULL)
    return (0);
  tmp = readdir(fd);
  tab = malloc(sizeof(char*) * 1000);
  while (tmp)
    {
      if (tmp->d_name[0] != '.')
        tab[++i] = strdup(tmp->d_name);
      tmp = readdir(fd);
    }
  tab[i + 1] = NULL;
  closedir(fd);
  get_good_tab(tab, get_tabd(tab, str), str);
  return (0);
}

void		get_genealogy(t_individu *id)
{
  if (strcmp(id->option, "1") == 0)
    my_files(id->family);
  else if (strcmp(id->option, "2") == 0)
    display_info(id);
  else if (strcmp(id->option, "6") == 0)
    printf("cousin(e)s : aucun\n");
  else if (strcmp(id->option, "7") == 0)
    printf("demi-frères et soeurs : aucun\n");
}
