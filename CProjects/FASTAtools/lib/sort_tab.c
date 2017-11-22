/*
** sort_tab.c for sort_tab in /home/gwendoline/rendu/Piscine_Synthese/FASTAtools/lib
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jun 25 13:20:26 2015 
** Last update Thu Jun 25 15:49:35 2015 
*/

void    swaptab(char **tab, int i, int j)
{
  char	*str;

  str = tab[i];
  tab[i] = tab[j];
  tab[j] = str;
}

int     len_tab(char **tab)
{
  int   i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

