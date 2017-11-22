/*
** get_char_comp.c for get_char_comp in /home/gwendoline/rendu/Piscine_Synthese/FASTAtools
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jun 26 01:17:22 2015 
** Last update Fri Jun 26 01:28:11 2015 
*/

#include "header.h"

char		get_char_comp(char c)
{
  if (c == 'A')
    c = 'T';
  else if (c == 'T')
    c = 'A';
  else if (c == 'G')
    c = 'C';
  else if (c == 'C')
    c = 'G';
  return (c);
}
