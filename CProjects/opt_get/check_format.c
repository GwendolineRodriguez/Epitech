/*
** check_format.c for check_format in /home/gwendoline/rendu/Prgelm/colles/opt_get/tmp
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Mon May 25 18:37:28 2015 
** Last update Mon May 25 18:55:46 2015 Rémi Duclos
*/

#include "opt_get.h"

char	*get_word(const char *str)
{
  char	*word;
  int	j;

  j = 0;
  word = NULL;
  while (str[j] != '\0' && str[j] != ' ')
    j++;
  if ((word = malloc(j * sizeof(char) + 1)) == NULL)
    exit(0);
  j = 0;
  while (str[j] != '\0' && str[j] != ' ')
    word[j] = str[j++];
  word[j] = '\0';
  return (word);
}

int	count_args(const char *format)
{
  char	*tmp;
  int	cnt;
  int	args;

  cnt = 0;
  args = 0;
  tmp = get_word(format);
  if (tmp != NULL)
    cnt += my_strlen(tmp) + 1;
  while (tmp != NULL && tmp[0] != '-')
    {
      free(tmp);
      tmp = get_word(&format[cnt]);
      cnt += my_strlen(tmp) + 1;
      args++;
    }
  free(tmp);
  return (args);
}

int	check_format(t_opt *opt, const char *format)
{
  int	i;

  i = 0;
  while (format[i] != 0)
    {
      if (format[i + 1] != '\0'
	  && (format[i] == '-' && format[i + 1] == '-'))
	{
	  if (double_dash(&format[i], opt) == -1)
	    return (-1);
	}
      else if (format[i] == '-' && i >= 1 && format[i - 1] != '-')
	{
	  if (one_dash(&format[i], opt) == -1)
	    return (-1);
	}
      i++;
    }
  if (check_list(opt) == 0)
    return (0);
  else
    return (-1);
}

int	check_list(t_opt *opt)
{
  t_opt	*tmp;

  tmp = opt->next;
  while (tmp != opt)
    {
      if (tmp->check == 0)
	return (-1);
      tmp = tmp->next;
    }
  return (0);
}
