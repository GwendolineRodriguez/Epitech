/*
** display.c for display in /home/gwendoline/rendu/Piscine_Synthese/FASTAtools
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Wed Jun 24 15:06:11 2015 
** Last update Fri Jun 26 01:29:13 2015 
*/

#include "header.h"

char            *get_epur_str(char *str, int i, int j)
{
  char          *res;

  if ((res = malloc(sizeof(char) * my_strlen(str))) == NULL)
    put_error("ERROR on malloc\n");
  while (str[++i] != '\0')
    {
      if (str[i] == '>')
        {
          res[j++] = '>';
          while (str[i++] != '\n')
            res[j++] = str[i];
        }
      if (str[i] >= 'a' && str[i] <= 'z')
        str[i] = str[i] - 32;
      if (str[i] == 'A' || str[i] == 'T' || str[i] == 'C'
          || str[i] == 'G'|| str[i] == 'N')
        res[j++] = str[i];
      if (str[i + 1] == '>')
        res[j++] = '\n';
    }
  res[j] = '\n';
  res[j + 1] = '\0';
  return (res);
}

void            display_simple(char *str)
{
  int           i;

  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] == '>')
        {
          my_putchar('>');
          while (str[i++] != '\n')
            my_putchar(str[i]);
        }
      if (str[i] >= 'a' && str[i] <= 'z')
        str[i] = str[i] - 32;
      if (str[i] == 'A' || str[i] == 'T' || str[i] == 'C'
          || str[i] == 'G'|| str[i] == 'N')
        my_putchar(str[i]);
      if (str[i + 1] == '>')
        my_putchar('\n');
    }
  my_putchar('\n');
}

void            display_arn(char *str)
{
  int           i;

  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] == '>')
        {
          my_putchar('>');
          while (str[i++] != '\n')
            my_putchar(str[i]);
        }
      if (str[i] >= 'a' && str[i] <= 'z')
        str[i] = str[i] - 32;
      if (str[i] == 'A' || str[i] == 'T' || str[i] == 'C'
          || str[i] == 'G'|| str[i] == 'N')
	{
	  if (str[i] == 'T')
	    my_putchar('U');
	  else
	    my_putchar(str[i]);
	}
      if (str[i + 1] == '>')
	my_putchar('\n');
    }
  my_putchar('\n');
}

char		*get_comp(char *str)
{
  int		i;

  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] == 'A')
	str[i] = 'T';
      else if (str[i] == 'T')
	str[i] = 'A';
      else if (str[i] == 'G')
        str[i] = 'C';
      else if (str[i] == 'C')
        str[i] = 'G';
    }
  return (str);
}

void		display_reverse(char *str)
{
  int		i;
  int		j;
  char		*rev;

  i = 0;
  if ((rev = malloc(sizeof(char) * 10000)) == NULL)
    put_error("ERROR on malloc\n");
  str = get_epur_str(str, -1, 0);
  str = get_comp(str);
  while (str[i] != '\0')
    {
      if (str[i] == '>')
        {
          my_putchar('>');
          while (str[i++] != '\n')
            my_putchar(get_char_comp(str[i]));
        }
      j = 0;
      while (str[i] != '\n' && str[i] != '\0')
	rev[j++] = str[i++];
      rev[j] = '\0';
      put_revstr(rev);
      my_putchar('\n');
      i++;
    }
}
