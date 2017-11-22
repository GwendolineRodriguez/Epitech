/*
** init_param.c for init_param in /home/gwendoline/rendu/Piscine_Synthese/projTester
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jun 18 12:44:30 2015 
** Last update Wed Jun 24 13:24:17 2015 
*/

#include "header.h"

void            init_param_all(t_param *p)
{
  p->file = NULL;
}

t_param         *init_param()
{
  t_param       *p;

  p = malloc(sizeof(t_param));
  init_param_all(p);
  return (p);
}
