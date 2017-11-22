/*
** lemin.h for  in /home/daniel_b/Rendu/CPE_2014_lemin
** 
** Made by DANIEL Erwan
** Login   <daniel_b@epitech.net>
** 
** Started on  Thu Apr  2 14:31:21 2015 DANIEL Erwan
** Last update Tue Apr 28 01:13:30 2015 Bastien Rougé
*/

#ifndef LEMIN_H_
#define LEMIN_H_

typedef struct	s_peak
{
  char		*room_name;
  int		x;
  int		y;
  int		nb_adj;
  struct s_peak	**peak;
  struct s_peak	*next;
}		t_peak;

typedef struct	s_graph
{
  int		nb_ants;
  t_peak	*start_room;
  t_peak	*end_room;
  t_peak	*first_room;
}		t_graph;

#endif
