/*
** display.c for display in /home/gwendoline/rendu/Piscine_Synthese/SBMLparser
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Tue Jun 16 17:37:30 2015 
** Last update Wed Jun 17 17:25:12 2015 
*/

#include "./../header.h"

void            display_comp(t_param *p)
{
  my_putstr("compartment\n");
  if (p->data->comp_id == 1)
    my_putstr("----->id\n");
  if (p->data->comp_name == 1)
    my_putstr("----->name\n");
}

void            display_reac(t_param *p)
{
  my_putstr("reaction\n");
  if (p->data->reac_id == 1)
    my_putstr("----->id\n");
  if (p->data->reac_name == 1)
    my_putstr("----->name\n");
  if (p->data->reac_reversible == 1)
    my_putstr("----->reversible\n");
}

void            display_model(t_param *p)
{
  my_putstr("model\n");
  if (p->data->model_id == 1)
    my_putstr("----->id\n");
  if (p->data->model_name == 1)
    my_putstr("----->name\n");
}

void		display_sbml(t_param *p)
{
  my_putstr("sbml\n");
  if (p->data->sbml_level == 1)
    my_putstr("----->level\n");
  if (p->data->sbml_version == 1)
    my_putstr("----->version\n");
  if (p->data->sbml_xmlns == 1)
    my_putstr("----->xmlns\n");
}

void		display_data(t_param *p)
{
  if (p->data->comp == 1)
    display_comp(p);
  if (p->data->model == 1)
    display_model(p);
  if (p->data->reac == 1)
    display_reac(p);
  if (p->data->sbml == 1)
    display_sbml(p);
  if (p->data->spec == 1)
    display_spec(p);
  if (p->data->specr == 1)
    display_specr(p);
}
