/*
** prerequis.c for prerequis in /home/gwendoline/rendu/Piscine_Synthese/genealogie
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jul  2 09:13:12 2015 Gwendoline Rodriguez
** Last update Sat Jul  4 14:22:53 2015 Gwendoline Rodriguez
*/

#include "header.h"

char		*put_lower(char *str)
{
  int		i;
  char		*new;

  i = -1;
  new = strdup(str);
  while (new[++i])
    {
      if (new[i] >= 'A' && new[i] <= 'Z')
	new[i] = new[i] + 32;
    }
  return (new);
}

static int      compare(const void *a, const void *b)
{
  return (strcmp(put_lower(*(char **)a), put_lower(*(char **)b)));
}

int             len_tab(char **tab)
{
  int           i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

void		print_tab(char **tab)
{
  int		i;

  i = -1;
  qsort(tab, len_tab(tab), sizeof *tab, compare);
  while (tab[++i])
    printf("%s\n", tab[i]);
}

int		my_files_synthese(char *str)
{
  DIR		*fd;
  struct dirent	*tmp;
  char		**tab;
  int		i;

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
  print_tab(tab);
  return (0);
}

/* int		main(UNUSED int ac, char **av) */
/* { */
/*   my_files_synthese(av[1]); */
/*   return (0); */
/* } */
