/*
** display.c for display in /home/gwendoline/rendu/Piscine_Synthese/genealogie
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jul  3 13:02:44 2015 Gwendoline Rodriguez
** Last update Sat Jul  4 16:15:52 2015 Gwendoline Rodriguez
*/

#include "header.h"

int		check_ifslash(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    if (str[i] == '/')
      return (0);
  return (1);
}

char		*get_nameonly(char *str)
{
  int		len;

  len = strlen(str);
  while (len--)
    if (str[len] == '/')
      str = strdup(&str[len + 1]);
  return (str);
}

char		*get_familyname(char *name)
{
  if (name[strlen(name) - 1] == '/')
    name[(strlen(name) - 1)] = '\0';
  if (name[0] == '.' && name [1] == '/')
    name = strdup(&name[2]);
  if (check_ifslash(name) == 0)
    name = get_nameonly(name);
  return (name);
}

void            display_info(t_individu *id)
{
  id->rep = get_familyname(id->rep);
  printf("%s %s\n", id->name, id->rep);
  if (strcmp(id->gender, "1") == 0)
    printf("née le %s %s %s (%s)\n", id->day, id->monletter, id->year, id->dep);
  else
    printf("né le %s %s %s (%s)\n", id->day, id->monletter, id->year, id->dep);
  if (strcmp(id->gender, "1") == 0)
    printf("de sexe féminin\n");
  else    printf("de sexe masculin\n");
  printf("%s\n", id->secu);
  printf("%s\n", id->cv);
}
