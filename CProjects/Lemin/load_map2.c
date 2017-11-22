/*
** load_map2.c for  in /home/rouge_b/rendu/Prog_elem/CPE_2014_lemin
** 
** Made by Bastien Rougé
** Login   <rouge_b@epitech.net>
** 
** Started on  Mon Apr 27 23:51:37 2015 Bastien Rougé
** Last update Mon Apr 27 23:56:02 2015 Bastien Rougé
*/

#include <stdlib.h>
#include "lemin.h"
#include "./lib/my/my.h"
#include "./lib/explode/explode.h"

int	nb_links(char *room_name, char **data)
{
  int	count;
  int	count2;
  int	occur;
  char	**exp;

  count = -1;
  occur = 0;
  while (data[++count])
    {
      count2 = -1;
      exp = my_explode("-", data[count]);
      while (exp[++count2])
	if (!(my_strcmp(room_name, exp[count2])))
	  occur++;
    }
  return (occur);
}
