/*
** algo_erwan.c for  in /home/daniel_b/Rendu/CPE_2014_lemin
** 
** Made by DANIEL Erwan
** Login   <daniel_b@epitech.net>
** 
** Started on  Tue Apr 28 16:39:08 2015 DANIEL Erwan
** Last update Sat May  2 15:20:20 2015 daniel_b
*/

#include "lemin.h"
#include <stdio.h>
#include <stdlib.h>

t_peak	**test_way(t_graph *graph);
t_peak  **get_passage(t_graph *graph);
int     get_peak_nb(t_graph *graph);

void	show_passage(t_peak **passage, t_graph *graph)
{
  int	i;
  int	room;
  int	size;

  i = 0;
  room = 0;
  size = get_peak_nb(graph);
  while (passage[i])
    {
      printf("passage %d\n", i);
      while (room != size)
	{
	  printf("\tin room %s | %d\n", passage[i][room].room_name, room);
	  room++;
	}
      i++;
      room = 0;
    }
}

void	algo_erwan(t_graph *graph)
{
  int	poid_poss[graph->start_room->nb_adj];
  t_peak	*start;
  t_peak	**passage;
  int		i;

  i = 0;
  start = graph->start_room;
  while (start->peak[i])
    {
      passage = test_way(graph);
      i++;
    }
  i = 0;
  show_passage(passage, graph);
}

int	get_peak_nb(t_graph *graph)
{
  int	size;
  t_peak	*temp;

  temp = graph->first_room;
  size = 0;
  while (temp && ++size)
    temp = temp->next;
  return (size);
}

t_peak		**get_passage(t_graph *graph)
{
  t_peak	**passage;
  int		size;
  int		i;

  i = 0;
  size = get_peak_nb(graph);
  passage = malloc(sizeof (t_peak *) * (size + 1));
  passage[size] = 0;
  while (passage[i])
    {
      passage[i] = malloc(sizeof (t_peak) * (size + 1));
      i++;
    }
  return (passage);
}

int		already_passed(t_peak **passage, int passe, int room)
{
  int		is_passed;
  int		i;

  is_passed = 0;
  i = 0;
  while (i < passe)
    {
      if (passage[i][room] == passage[passe][room])
	return (1);
      i++;
    }
  return (0);
}

t_peak		**test_way(t_graph *graph)
{
  t_peak	**passage;
  t_peak	*room;
  int		passe;
  int		i;
  int		size;
  int		actual;

  passage = get_passage(graph);
  passe = 0;
  i = 0;
  size = get_peak_nb(graph);
  while (passage[passe])
    {
      actual = 0;
      room = graph->start_room;
      while (actual != size)
	{
	  while (already_passed(passage, passe, actual) && i < 
	  passage[passe][actual] = *room;
	  if (passage, passe, actual)
	  room = room->peak[0];
	  actual++;
	}
      passe++;
    }
  return (passage);
}
