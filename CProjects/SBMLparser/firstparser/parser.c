/*
** parser.c for parser in /home/gwendoline/rendu/Piscine_Synthese
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jun 15 15:56:34 2015 
** Last update Wed Jun 17 20:31:32 2015 
*/

#include "./../header.h"

void            check_specr(char *str, t_param *p)
{
  int           i;

  i = 0;
  p->data->specr = 1;
  while (str[i] == ' ' || str[i] == '<' || str[i] == '\t')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] == '=')
        {
          if (my_strncmp(&str[i - 7], "species", 6) == 0)
            p->data->specr_species = 1;
          else if (my_strncmp(&str[i - 13], "stoichiometry", 12) == 0)
            p->data->specr_stoi = 1;
        }
      i++;
    }
}

int		parser(char *str, t_param *p)
{
  int		i;

  i = 0;
  while (str[i] == ' ' || str[i] == '<' || str[i] == '\t')
    i++;
  while (str[i++] != '\0')
    {
      if (str[i] == ' ')
	{
	  if (my_strncmp(&str[i - 4], "sbml", 3) == 0)
	    check_sbml(str, p);
	  else if (my_strncmp(&str[i - 5], "model", 4) == 0)
	    check_model(str, p);
          else if (my_strncmp(&str[i - 11], "compartment", 10) == 0)
            check_comp(str, p);
          else if (my_strncmp(&str[i - 8], "reaction", 7) == 0)
            check_reac(str, p);
          else if (my_strncmp(&str[i - 7], "species", 6) == 0)
            check_spec(str, p);
          else if (my_strncmp(&str[i - 16], "speciesReference", 15) == 0)
            check_specr(str, p);
	  return (0);
	}
    }
  return (0);
}
