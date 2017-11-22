/*
** my_strtowordtab.c for my_strtowordtab in /home/gwendoline/rendu/Piscine_Synthese/projTester
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jun 18 19:51:22 2015 
** Last update Wed Jun 24 17:30:13 2015 
*/

#include "header.h"

int             get_nb_words(char *s)
{
  int   i;
  int   cpt;

  i = 0;
  cpt = 0;
  if (!s)
    return (0);
  while (s[i])
    {
      if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
          || (s[i] >= '0' && s[i] <= '9'))
        {
          cpt = cpt + 1;
          while (s[i] && ((s[i] >= 'a' && s[i] <= 'z')
                          || (s[i] >= 'A' && s[i] <= 'Z')
                          || (s[i] >= '0' && s[i] <= '9')))
            i++;
        }
      i++;
    }
  return (cpt);
}

int             get_nb_char(char *s, int i)
{
  int           cpt;

  cpt = 0;
  while (s[i] && ((s[i] >= 'a' && s[i] <= 'z')
		  || (s[i] >= 'A' && s[i] <= 'Z')
		  || (s[i] >= '0' && s[i] <= '9')))
    {
      cpt++;
      i++;
    }
  return (cpt);
}

char            *get_next_word(char *word, char *str, int i)
{
  int           j;

  j = 0;
  while ((str[i] >= 'a' && str[i] <= 'z')
         || (str[i] >= 'A' && str[i] <= 'Z')
         || (str[i] >= '0' && str[i] <= '9'))
    word[j++] = str[i++];
  word[j] = '\0';
  return (word);
}

char            **my_strtowordtab(char *str)
{
  int           i;
  int           w;
  char          **tab;

  i = -1;
  w = 0;
  tab = malloc(sizeof(char *) * (get_nb_words(str) + 1));
  while (str && str[++i])
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
          || (str[i] >= '0' && str[i] <= '9'))
        {
          tab[w] = malloc(sizeof(char) * (get_nb_char(str, i) + 1));
          tab[w] = get_next_word(tab[w], str, i);
	  i = i + get_nb_char(str, i);
	  w++;
        }
    }
  tab[w] = NULL;
  if (my_strcmp(tab[0], "ARGS") != 0 && my_strcmp(tab[0], "ENTREE")
      && my_strcmp(tab[0], "RES") != 0)
    put_error("! Fichier mal formatté !\n");
  return (tab);
}
