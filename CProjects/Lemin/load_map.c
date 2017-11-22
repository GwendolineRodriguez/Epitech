/*
** load_map.c for  in /home/rouge_b/rendu/Prog_elem/CPE_2014_lemin
** 
** Made by Bastien Rougé
** Login   <rouge_b@epitech.net>
** 
** Started on  Fri Apr 24 16:12:13 2015 Bastien Rougé
** Last update Tue Apr 28 17:58:38 2015 Bastien Rougé
*/

#include <stdlib.h>
#include <stdio.h>
#include "lemin.h"
#include "./lib/my/my.h"
#include "./lib/explode/explode.h"

void		add_link(char *s1, char *s2, t_graph *graph)
{
  t_peak	*tmp;
  t_peak	*peak2;
  t_peak	*peak1;
  int		len;

  if (my_strcmp(s1, s2))
    {
      tmp = graph->first_room;
      while (tmp)
	{
	  if (!(my_strcmp(s1, tmp->room_name)))
	    peak1 = tmp;
	  else if (!(my_strcmp(s2, tmp->room_name)))
	    peak2 = tmp;
	  tmp = tmp->next;
	}
      peak1->peak[peak1->nb_adj] = peak2;
      peak1->peak[++peak1->nb_adj] = 0;
      peak2->peak[peak2->nb_adj] = peak1;
      peak2->peak[++peak2->nb_adj] = 0;
    }
}

void	add_topeak(char **coord, t_peak *peak, t_graph *graph, char *str)
{
  peak->room_name = my_strdup(coord[0]);
  peak->x = atoi(coord[1]);
  peak->y = atoi(coord[2]);
  if (!(my_strcmp("##start", str)))
    graph->start_room = peak;
  else if (!(my_strcmp("##end", str)))
    graph->end_room = peak;
}

void		init_links(t_graph *graph, char **data)
{
  t_peak	*tmp;
  int		count;
  char		**exp;

  tmp = graph->first_room;
  while (tmp)
    {
      tmp->nb_adj = 0;
      if (!(tmp->peak = malloc(sizeof(t_peak*) *
			       (nb_links(tmp->room_name, data) + 1))))
	exit(0);
      tmp = tmp->next;
    }
  count = -1;
  while (data[++count])
    {
      exp = my_explode("-", data[count]);
      if (my_tablen(exp) == 2)
	add_link(exp[0], exp[1], graph);
      free(exp);
    }
}

void		init_map(t_graph *graph, char *map)
{
  int		count;
  char		**exp;
  char		**coord;
  t_peak	*tmpeak;
  t_peak	*save;

  exp = my_explode("\n", map);
  count = 0;
  tmpeak = graph->first_room;
  save = tmpeak;
  while (exp[++count])
    {
      coord = my_explode(" ", exp[count]);
      if (my_tablen(coord) == 3)
	{
	  add_topeak(coord, tmpeak, graph, exp[count - 1]);
	  if (!(tmpeak->next = malloc(sizeof(*tmpeak->next))))
	    exit(0);
	  save = tmpeak;
	  tmpeak = tmpeak->next;
	}
      free(coord);
    }
  save->next = 0;
}

t_graph		*init_graph()
{
  t_graph	*graph;
  char		*map;
  char		**exp;
  char		*exp2;

  map = read_map();
  if (!(graph = malloc(sizeof(*graph))))
    exit(0);
  exp = my_explode("\n", map);
  graph->nb_ants = atoi(exp[0]);
  if (!(graph->first_room = malloc(sizeof(*graph->first_room))))
    exit(0);
  init_map(graph, map);
  init_links(graph, exp);
  free(exp);
  return (graph);
}
