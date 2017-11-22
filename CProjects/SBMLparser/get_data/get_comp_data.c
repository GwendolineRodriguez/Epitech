/*
** get_sbml_data.c for get_sbml_data in /home/gwendoline/rendu/Piscine_Synthese/SBMLparser
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Tue Jun 16 11:43:33 2015 
** Last update Thu Jun 18 10:12:34 2015 
*/

#include "./../header.h"

void            get_comp_name(char *str, t_param *p)
{
  int           i;

  i = 0;
  while (str[i] != ' ')
    {
      if (str[i] == '"')
        {
          p->comp->name = my_strncpy(p->sbml->level, &str[0], i);
        }
      i++;
    }
}

void            get_comp_id(char *str, t_param *p)
{
  int           i;

  i = 0;
  while (str[i] != ' ')
    {
      if (str[i] == '"')
        {
          p->comp->id = my_strncpy(p->sbml->xmlns, &str[0], i);
        }
      i++;
    }
}

void            get_comp_data(char *str, t_param *p)
{
  int           i;

  i = 0;
  while (str[i] == ' ' || str[i] == '<' || str[i] == '\t')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] == '=')
        {
          if (my_strncmp(&str[i - 3], "id", 1) == 0)
	    get_comp_id(&str[i - 3], p);
          else if (my_strncmp(&str[i - 5], "name", 3) == 0)
            get_comp_name(&str[i - 5], p);
        }
      i++;
    }
}

