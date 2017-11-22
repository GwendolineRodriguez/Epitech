/*
** main.c for  in /home/rouge_b/rendu/Prog_elem/CPE_2014_lemin
**
** Made by Bastien Rougé
** Login   <rouge_b@epitech.net>
**
** Started on  Mon Apr 27 19:06:24 2015 Bastien Rougé
** Last update Sat May  2 15:40:02 2015 gwendoline rodriguez
*/

#include "lemin.h"

int	main(int ac, char **av)
{
  t_graph *graph;

  graph = init_graph();
  algo_erwan(graph);
  return (0);
}
