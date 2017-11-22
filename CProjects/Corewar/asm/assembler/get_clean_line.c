/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/bano_l/rendu/PSU_2013_minishell1
**
** Made by bano
** Login   <bano_l@epitech.net>
**
** Started on  Mon Dec 30 02:14:55 2013 bano
** Last update Sun Apr 12 21:43:37 2015 gwendoline rodriguez
*/

#include "./../header/header.h"

char		**get_clean_tab(char *str, char **tab, int b, int i)
{
  int           h;

  h = 0;
  while (str[i] != '\0')
    {
      b = 0;
      while (str[i] == ' ' || str[i] == COMMENT_CHAR
	     || str[i] == SEPARATOR_CHAR || str[i] == '\t')
	i = i + 1;
      if ((tab[h] = malloc((strlen_char(str) + 1) * sizeof(char *))) == NULL)
	return (NULL);
      while (str[i] != ' ' && str[i] != '\0' && str[i] != COMMENT_CHAR
	     && str[i] != SEPARATOR_CHAR && str[i] != '\t')
	{
	  tab[h][b] = str[i];
	  i = i + 1;
	  b = b + 1;
	}
      tab[h][b] = '\0';
      h = h + 1;
    }
  tab[h] = NULL;
  return (tab);
}

char		**get_clean_line(char *str)
{
  int		i;
  int		c;
  char		**tab;

  i = check_if_label(str);
  c = cpt_word(str);
  if (check_if_point(str, i) != 0)
    return (0);
  if ((tab = malloc(c * sizeof(*tab))) == NULL)
    return (NULL);
  tab = get_clean_tab(str, tab, 0, i);
  return (tab);
}
