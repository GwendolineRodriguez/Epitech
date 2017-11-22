/*
** my_boogle.c for my_boogle in /home/duclos_r/Tek-1/Colle/boogle
** 
** Made by Rémi Duclos
** Login   <duclos_r@epitech.net>
** 
** Started on  Fri Jun  5 14:21:37 2015 Rémi Duclos
** Last update Fri Jun  5 17:42:57 2015 
*/

#include "my_boogle.h"

int		main(int ac, char **av)
{
  t_boogle	boogle;

  parsing(ac, av, &boogle);
  /* game(&boogle); */
}
