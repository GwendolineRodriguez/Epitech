/*
** str_to_wordtab.c for my_mixword in /home/duclos_r/Tek-1/Colle/my_mixword
** 
** Made by Rémi Duclos
** Login   <duclos_r@epitech.net>
** 
** Started on  Wed Jun 10 09:38:49 2015 Rémi Duclos
** Last update Wed Jun 10 10:21:31 2015 Rémi Duclos
*/

#include "my_mixword.h"

int	count_word(char *line, char sep)
{
  int	cnt;
  int	word;

  cnt = 0;
  word = 0;
  while (line[cnt] != '\0')
    {
      if (line[cnt] == sep)
	word++;
      cnt++;
    }
  return (++word);
}

int	len_word(char *line, char sep)
{
  int	cnt;

  cnt = 0;
  while (line[cnt] != '\0' && line[cnt] != sep)
    cnt++;
  return (cnt);
}

char	**str_to_wordtab(char *line, char sep)
{
  char	**wordtab;
  int	y;
  int	x;
  int	cnt;

  y = count_word(line, sep);
  wordtab = malloc(sizeof(*wordtab) * (y + 1));
  if (wordtab == NULL)
    exit(0);
  wordtab[y] = NULL;
  y = 0;
  cnt = 0;
  while (line[cnt] != '\0')
    {
      x = len_word(&line[cnt], sep);
      wordtab[y] = malloc(sizeof(**wordtab) * (x + 1));
      if (wordtab == NULL)
	exit(0);
      x = 0;
      while (line[cnt] != '\0' && line[cnt] != sep)
	wordtab[y][x++] = line[cnt++];
      wordtab[y++][x] = '\0';
      cnt++;
    }
  return (wordtab);
}
