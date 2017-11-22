/*
** search_res.c for search_res in /home/gwendoline/rendu/Piscine_Synthese/projTester/get_list
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Sat Jun 20 21:03:58 2015 
** Last update Sat Jun 20 22:15:50 2015 
*/

#include "header.h"

int		search_res(char *res, char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (strncmp(res, &str[i], i + strlen(res)) == 0)
	return (1);
      i++;
    }
  return (0);
}

void		print_res(char *res, t_param *p)
{
  if (search_res(res, p->data->input) == 1)
    printf("TEST OK\n");
  else
    printf("TEST KO\n");
}
