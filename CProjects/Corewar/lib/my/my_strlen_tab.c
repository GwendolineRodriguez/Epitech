/*
** my_strlen_tab.c for my_strlen_tab in /home/rodrig_1/rendu/Prgelm/CPE_2014_corewar/rodrig_1/lib/my
**
** Made by gwendoline rodriguez
** Login   <rodrig_1@epitech.net>
**
** Started on  Wed Apr  8 22:31:31 2015 gwendoline rodriguez
** Last update Wed Apr  8 23:03:04 2015 gwendoline rodriguez
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	my_strlen_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}
