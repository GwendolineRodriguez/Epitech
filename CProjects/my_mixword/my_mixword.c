/*
** my_mixword.c for my_mixwod in /home/duclos_r/Tek-1/Colle/my_mixword
** 
** Made by Rémi Duclos
** Login   <duclos_r@epitech.net>
** 
** Started on  Wed Jun 10 09:57:55 2015 Rémi Duclos
** Last update Wed Jun 10 15:01:30 2015 
*/

#include "my_mixword.h"

int	main(int ac, char **av)
{
  t_grid	grid;
  char		*file;

  file = parsing(ac, av, &grid);
  get_grid(file, &grid);
  reader(&grid);
}
