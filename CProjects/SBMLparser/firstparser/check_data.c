/*
** check_sbml.c for check_sbml in /home/gwendoline/rendu/Piscine_Synthese/SBMLparser
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Tue Jun 16 16:55:44 2015 
** Last update Wed Jun 17 17:25:03 2015 
*/

#include "./../header.h"

void            check_spec(char *str, t_param *p)
{
  int           i;

  i = 0;
  p->data->spec = 1;
  while (str[i] == ' ' || str[i] == '<' || str[i] == '\t')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] == '=')
        {
          if (my_strncmp(&str[i - 11], "compartment", 10) == 0)
            p->data->spec_compartment = 1;
          else if (my_strncmp(&str[i - 2], "id", 1) == 0)
            p->data->spec_id = 1;
          else if (my_strncmp(&str[i - 4], "name", 3) == 0)
            p->data->spec_name = 1;
        }
      i++;
    }
}

void            check_reac(char *str, t_param *p)
{
  int           i;

  i = 0;
  p->data->reac = 1;
  while (str[i] == ' ' || str[i] == '<' || str[i] == '\t')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] == '=')
        {
          if (my_strncmp(&str[i - 2], "id", 1) == 0)
            p->data->reac_id = 1;
          else if (my_strncmp(&str[i - 4], "name", 3) == 0)
            p->data->reac_name = 1;
          else if (my_strncmp(&str[i - 10], "reversible", 9) == 0)
            p->data->reac_reversible = 1;
        }
      i++;
    }
}

void            check_comp(char *str, t_param *p)
{
  int           i;

  i = 0;
  p->data->comp = 1;
  while (str[i] == ' ' || str[i] == '<' || str[i] == '\t')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] == '=')
        {
          if (my_strncmp(&str[i - 2], "id", 1) == 0)
            p->data->comp_id = 1;
          else if (my_strncmp(&str[i - 4], "name", 3) == 0)
            p->data->comp_name = 1;
        }
      i++;
    }
}

void            check_model(char *str, t_param *p)
{
  int           i;

  i = 0;
  p->data->model = 1;
  while (str[i] == ' ' || str[i] == '<' || str[i] == '\t')
    i++;
  while (str[i++] != '\0')
    {
      if (str[i] == '=')
        {
          if (my_strncmp(&str[i - 2], "id", 1) == 0)
            p->data->model_id = 1;
          else if (my_strncmp(&str[i - 4], "name", 3) == 0)
            p->data->model_name = 1;
        }
    }
}

void		check_sbml(char *str, t_param *p)
{
  int		i;

  i = 0;
  p->data->sbml = 1;
  while (str[i] == ' ' || str[i] == '<' || str[i] == '\t')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] == '=')
	{
	  if (my_strncmp(&str[i - 7], "version", 6) == 0)
	    p->data->sbml_version = 1;
          else if (my_strncmp(&str[i - 5], "level", 4) == 0)
            p->data->sbml_level = 1;
          else if (my_strncmp(&str[i - 5], "xmlns", 4) == 0)
            p->data->sbml_xmlns = 1;
	}
      i++;
    }
}
