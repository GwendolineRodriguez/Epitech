/*
** k_mer.c for k_mer in /home/gwendoline/rendu/Piscine_Synthese/FASTAtools/options
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Wed Jun 24 17:52:50 2015 
** Last update Thu Jun 25 19:38:43 2015 
*/

#include "header.h"

char		*get_all_seq(char *str)
{
  int		i;
  int		j;
  char		*rev;

  i = 0;
  j = 0;
  str = get_epur_str(str, -1, 0);
  if ((rev = malloc(sizeof(char) * my_strlen(str))) == NULL)
    put_error("ERROR on malloc\n");
  while (str[i] != '\0')
    {
      if (str[i] == '>')
	while (str[i++] != '\n');
      while (str[i] != '\n' && str[i] != '\0')
        rev[j++] = str[i++];
      if (str[i] == '\n')
	i++;
    }
  rev[j] = '\0';
  return (rev);
}

char		**get_k_mers(char *str, int k)
{
  int		len;
  char		**tab;
  int		cnt;
  int		i;
  int		j;

  i = -1;
  j = 0;
  str = get_all_seq(str);
  len = my_strlen(str);
  if ((tab = malloc(sizeof(char*) * ((len - k + 1) + 1))) == NULL)
    put_error("ERROR on malloc\n");
  while (++i < (len - k + 1))
    {
      cnt = -1;
      if ((tab[j] = malloc(sizeof(char) * (k + 1))) == NULL)
	put_error("ERROR on malloc\n");
      while (++cnt < k)
	tab[j][cnt] = str[i++];
      tab[j][cnt] = '\0';
      i = i - k;
      j++;
    }
  tab[i] = NULL;
  return (tab);
}

static int	compare(const void *a, const void *b)
{
  return strcmp(*(char **)a, *(char **)b);
}

void		display_k_mers(char *str, int k)
{
  char		**tab;
  char		*tmp[1000];
  int		i;
  int		j;
  int		c;

  i = -1;
  c = 0;
  tab = get_k_mers(str, k);
  qsort(tab, len_tab(tab), sizeof *tab, compare);
  while (tab[++i] != NULL)
    {
      j = -1;
      while (tmp[++j] != NULL && tab[i] != NULL)
	while (my_strcmp(tmp[j], tab[i]) == 0 && tab[i++] != NULL);
      if (tab[i] != NULL)
	{
	  tmp[c] = my_strdup(tab[i]);
	  if (tmp[c] != NULL)
	    printf("%s\n", tmp[c]);
	  tmp[++c] = NULL;
	}
    }
}
