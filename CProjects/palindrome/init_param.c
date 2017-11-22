/*
** init_param.c for init_param in /home/gwendoline/rendu/Piscine_Synthese/projTester
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jun 18 12:44:30 2015 
** Last update Sat Jun 27 16:02:37 2015 Gwendoline Rodriguez
*/

#include "header.h"

void            init_param_all(t_param *p)
{
  p->c1 = NULL;
  p->c2 = NULL;
  p->revchar = NULL;
  p->n = 0;
  p->save = 0;
  p->b = 0;
  p->it = 0;
  p->rev = 0;
  p->check = -1;
  p->itmax = 2147483647;
  p->itmin = 0;
  p->reverse = 0;
  p->check_pass = 0;
  p->itopmax = "<=";
  p->itopmin = ">=";
}

t_param         *init_param()
{
  t_param       *p;

  p = malloc(sizeof(t_param));
  init_param_all(p);
  return (p);
}
