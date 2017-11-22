/*
** my_malloc.c for  in /home/daniel_b/Rendu/CPE_2014_bsq/lib/my
** 
** Made by DANIEL Erwan
** Login   <daniel_b@epitech.net>
** 
** Started on  Sun Jan 18 15:38:31 2015 DANIEL Erwan
** Last update Tue Jan 27 19:52:27 2015 DANIEL Erwan
*/

#include <stdlib.h>

void	*my_malloc(int size)
{
  void	*new;

  if (!(new = malloc(size)))
    exit(1);
  return (new);
}
