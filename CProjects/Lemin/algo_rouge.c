/*
** algo_rouge.c for  in /home/rouge_b/rendu/Prog_elem/CPE_2014_lemin
** 
** Made by Bastien Rougé
** Login   <rouge_b@epitech.net>
** 
** Started on  Tue Apr 28 16:44:19 2015 Bastien Rougé
** Last update Tue Apr 28 17:54:27 2015 Bastien Rougé
*/

#include <stdlib.h>
#include "lemin.h"

int		nb_salles(t_graph *graph)
{
  t_peak	*tmp;
  int		count;

  count = 0;
  tmp = graph->first_room;
  while (tmp->next)
    {
      tmp = tmp->next;
      count++;
    }
  count++;
  return (count);
}

int	is_tested(t_graph **tested, t_graph *room)
{
  int	count;

  count = -1;
  while (tested[++count])
    if (tested[count] == room)
      return (1);
  return (0);
}

void		algo_rouge(t_graph *graph)
{
  t_peak	**tested;
  t_peak	*start;
  t_peak	*prev;
  int		count;

  my_printf("<%d>", nb_salles(graph));
  tested = malloc(sizeof(t_graph*) * nb_salles(graph));
  start = graph->start_room;
  //my_printf("bwao");
  while (start != graph->end_room)
    {
      my_printf("%s\n", start->room_name);
      if (start->peak[count] && !is_tested(tested, start->peak[count]))
	{
	  count = 0;
	  prev = start;
	  start = start->peak[count];
	}
      else if (start->peak[count])
	count++;
      else
	{
	  count = 0;
	  start = prev;
	}
    }
}
