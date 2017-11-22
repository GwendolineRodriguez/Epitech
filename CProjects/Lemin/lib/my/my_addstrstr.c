/*
** my_addstrstr.c for  in /home/daniel_b/Rendu/PSU_2014_minishell1
** 
** Made by DANIEL Erwan
** Login   <daniel_b@epitech.net>
** 
** Started on  Fri Jan 30 14:30:31 2015 DANIEL Erwan
** Last update Sun Mar 29 23:43:07 2015 DANIEL Erwan
*/

#include <stdlib.h>
#include <stdio.h>

void    my_addstrstr(char **str, char *add)
{
  int   size;
  int   add_size;
  char  *new_str;
  char  *pstr;
  int   i;

  i = 0;
  size = 0;
  add_size = 0;
  pstr = *str;
  while (*pstr++ != '\0')
    size++;
  pstr = add;
  while (*pstr++ != '\0')
    add_size++;
  if (!(new_str = malloc(sizeof (char) * (size + add_size + 1))))
    exit(1);
  my_strncpy(new_str, *str, size + 1);
  new_str[size] = '\0';
  my_strcat(&new_str[size], add);
  new_str[size + add_size] = 0;
  free(str[0]);
  str[0] = new_str;
}
