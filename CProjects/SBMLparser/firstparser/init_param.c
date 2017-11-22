/*
** init_param.c for init_param in /home/gwendoline/rendu/Piscine_Synthese/SBMLparser
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Tue Jun 16 17:13:25 2015 
** Last update Wed Jun 17 21:11:50 2015 
*/

#include "./../header.h"

void		*init_param_all(t_param *p)
{
  p->data->sbml = 0;
  p->data->sbml_level = 0;
  p->data->sbml_version = 0;
  p->data->sbml_xmlns = 0;
  p->data->model = 0;
  p->data->model_id = 0;
  p->data->model_name = 0;
  p->data->comp = 0;
  p->data->comp_id = 0;
  p->data->comp_name = 0;
  p->data->reac = 0;
  p->data->reac_id = 0;
  p->data->reac_name = 0;
  p->data->reac_reversible = 0;
  p->data->spec = 0;
  p->data->spec_compartment = 0;
  p->data->spec_id = 0;
  p->data->spec_name = 0;
  p->data->specr = 0;
  p->data->specr_species = 0;
  p->data->specr_stoi = 0;
  p->data->check_i = 0;
  p->data->check_e = 0;
  p->data->check_json = 0;
  p->data->check_gui = 0;
}

t_param		*init_param()
{
  t_param       *p;

  p = malloc(sizeof(t_param));
  p->data = malloc(sizeof(t_data));
  init_param_all(p);
  return (p);
}

