/*
** read_map.c for  in /home/rouge_b/rendu/Prog_elem/CPE_2014_lemin
** 
** Made by Bastien Rougé
** Login   <rouge_b@epitech.net>
** 
** Started on  Fri Apr 24 16:16:00 2015 Bastien Rougé
** Last update Mon Apr 27 19:21:23 2015 Bastien Rougé
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./lib/my/my.h"
#include "./lemin.h"

int	my_strlen(char *str);

char	*cpytomap(char c, char *map)
{
  char	*new;
  int	len;

  if (!(new = malloc(sizeof(char) * (my_strlen(map) + 2))))
    exit(0);
  strcpy(new, map);
  len = my_strlen(new);
  new[len] = c;
  new[len + 1] = 0;
  return (new);
}

char	*read_map()
{
  char	buf[2];
  char	*map;
  int	fd;

  if (!(map = malloc(sizeof(char) * 1)))
    exit(0);
  map[0] = 0;
  while (fd = read(0, &buf[0], 1))
    map = cpytomap(buf[0], map);
  return (map);
}
