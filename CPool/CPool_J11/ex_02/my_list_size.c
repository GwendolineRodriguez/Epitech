/*
** my_list_size.c for my_list_size in /home/RODRIG_1/rendu/Piscine_C_J12/ex_02
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Tue Oct 21 17:56:07 2014 rodriguez gwendoline
** Last update Tue Oct 21 17:56:12 2014 rodriguez gwendoline
*/

#include <stdlib.h>
#include "./../include/mylist.h"

int		my_list_size(t_list *begin)
{
  t_list	*tmp;
  int		i;

  tmp = begin;
  i = 0;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i = i + 1;
    }
  return (i);
}
