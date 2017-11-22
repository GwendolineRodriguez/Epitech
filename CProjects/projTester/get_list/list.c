/*
** list.c for list in /home/gwendoline/rendu/Piscine_Synthese/projTester/etape2
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jun 19 13:35:11 2015 
** Last update Sat Jun 20 14:51:54 2015 
*/

#include "./../header.h"

t_list      *create_elem()
{
  t_list    *elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    exit(0);
  elem->prev = 0;
  return (elem);
}
