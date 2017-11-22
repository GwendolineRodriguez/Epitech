/*
** check_line.c for check_line in /home/rodrig_1/rendu/Prgelm/CPE_2014_corewar/asm
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Sat Apr 11 18:42:35 2015 gwendoline rodriguez
** Last update Sun Apr 12 17:13:55 2015 gwendoline rodriguez
*/

#include "./../header/header.h"

int             strlen_char(char *str)
{
  int           i;

  i = 0;
  while (str[i] != ' ' && str[i] != '\0'
	          && str[i] != '\t'
	          && str[i] != COMMENT_CHAR && str[i] != DIRECT_CHAR
	 && str[i] != LABEL_CHAR && str[i] != SEPARATOR_CHAR)
    i = i + 1;
  return (i);
}

int             cpt_word(char *str)
{
  int           i;
  int           c;

  i = 0;
  c = 0;
  while (str[i] != ' ' && str[i] != '\0' && str[i] != COMMENT_CHAR
	 && str[i] != SEPARATOR_CHAR && str[i] != '\t')
    {
      while (str[i] == ' ' || str[i] == COMMENT_CHAR
	     || str[i] == SEPARATOR_CHAR || str[i] == '\t')
	i = i + 1;
      if (str[i] != '\0')
	c = c + 1;
      while (str[i] != ' ' && str[i] != '\0' && str[i] != COMMENT_CHAR
	     && str[i] != SEPARATOR_CHAR && str[i] != '\t')
	i = i + 1;
    }
  return (c);
}

int             check_if_point(char *str, int i)
{
  int		count;

  count = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '.')
	return (-1);
      if (str[i] >= 'a' && str[i] <= 'z')
	count++;
      i++;
    }
  if (count == 0)
    return (-1);
  return (0);
}

int             check_if_label(char *str)
{
  int           i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ':'
	  && (str[i - 1] != ' ' && str[i - 1] != DIRECT_CHAR))
	return (i + 1);
      i++;
    }
  return (0);
}
