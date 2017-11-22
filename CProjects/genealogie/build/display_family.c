/*
** prerequis.c for prerequis in /home/gwendoline/rendu/Piscine_Synthese/genealogie
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jul  2 09:13:12 2015 Gwendoline Rodriguez
** Last update Sat Jul  4 19:27:38 2015 Gwendoline Rodriguez
*/

#include "header.h"

static int      compare(const void *a, const void *b)
{
  return (strcmp(*(char **)a, (*(char **)b)));
}

void		print_tab(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i])
    {
      printf("%s", tab[i]);
      if (tab[i + 1] != NULL)
	printf(" / ");
      if (tab[i + 1] == NULL)
	printf("\n");
    }
}

char		**get_clean_tab(char **tab, char *str)
{
  int		i;
  int		j;
  char		**tabi;

  i = -1;
  j = -1;
  tabi = malloc(sizeof(char*) * 100);
  while (tab[++i])
    {
      if (strcmp(tab[i], str) == 0)
	i++;
      if (tab[i] != NULL)
	tabi[++j] = strdup(tab[i]);
    }
  tabi[j + 1] = NULL;
  return (tabi);
}

void		get_good_tab(char **tab, char **tabd, char *str)
{
  int		i;
  int		x;
  int		j;
  struct stat   sb;
  char		*tmp;
  char		*way;
  char		**tabi;

  i = -1;
  x = -1;
  way = malloc(sizeof(char) * 100);
  tmp = malloc(sizeof(char) * 100);
  tabi = malloc(sizeof(char*) * 100);
  qsort(tabd, len_tab(tabd), sizeof *tabd, compare);
  while (tabd[++i])
    {
      j = -1;
      while (tab[++j])
	{
	  way = strcpy(way, str);
	  way = strcat(way, tab[j]);
	  stat(way, &sb);
	  sprintf(tmp, "%ld", sb.st_mtime);
	  if (strcmp(tmp, tabd[i]) == 0)
	    {
	      tabi[++x] = tab[j];
	      tab = get_clean_tab(tab, tab[j]);
	    }
	}
    }
  tabi[len_tab(tabd)] = NULL;
  print_tab(tabi);
}

char		**get_tabd(char **tab, char *str)
{
  char		**tabd;
  char		*way;
  int           i;
  struct stat   sb;

  i = -1;
  way = malloc(sizeof(char*) * 100);
  tabd = malloc(sizeof(char*) * 1000);
  while (tab[++i])
    {
      way = strcpy(way, str);
      way = strcat(way, tab[i]);
      stat(way, &sb);
      tabd[i] = malloc(sizeof(char) * 100);
      sprintf(tabd[i], "%ld", sb.st_mtime);
    }
  tabd[i + 1] = NULL;
  return (tabd);
}
