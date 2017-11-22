/*
** init_param.c for init_param in /home/gwendoline/rendu/Piscine_Synthese/projTester
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jun 18 12:44:30 2015 
** Last update Sat Jun 20 22:09:35 2015 
*/

#include "./../header.h"

void            *init_param_all(t_param *p)
{
  p->bin = NULL;
  p->data->output = 0;
  p->data->goodbin = 0;
  p->data->goodtest = 0;
  p->data->stats = 0;
  p->data->check_res = 0;
  p->data->check_entree = 0;
  p->data->check_args = 0;
  p->data->check_ok = 0;
  p->data->check_ko = 0;
  p->data->input = NULL;
  p->list->type = NULL;
  p->list->inputfile = NULL;
  p->list->res = NULL;
}

t_param         *init_param()
{
  t_param       *p;

  p = malloc(sizeof(t_param));
  p->data = malloc(sizeof(t_data));
  p->list = create_elem();
  init_param_all(p);
  return (p);
}
