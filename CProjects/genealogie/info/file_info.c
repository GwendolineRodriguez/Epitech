/*
** file_info.c for file_info in /home/gwendoline/rendu/Piscine_Synthese/genealogie
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jul  3 10:37:35 2015 Gwendoline Rodriguez
** Last update Sat Jul  4 09:53:55 2015 Gwendoline Rodriguez
*/

#include "header.h"

char		*get_inode(char *ino)
{
  char		*my_zero;

  if (strlen(ino) > 6)
    ino = strdup(&ino[strlen(ino) - 6]);
  else if (strlen(ino) < 6)
    {
      while (strlen(ino) != 6)
	{
	  my_zero = strdup("0");
	  strcat(my_zero, ino);
	  strcpy(ino, my_zero);
	}
    }
  return (ino);
}

char		*get_full(char *full)
{
  char          *my_zero;
  char		*new;

  my_zero = strdup("0");
  if (strlen(full) == 1)
    {
      strcat(my_zero, full);
      new = strdup(my_zero);
    }
  else if (strlen(full) > 2)
    new = strdup(&full[strlen(full) - 2]);
  return (new);
}

char		*get_id_secu(t_individu *id)
{
  char		*my_space;
  char		*year;

  my_space = strdup(" ");
  year = strdup(&id->year[strlen(id->year) - 2]);
  id->secu = strcat(id->secu, id->gender);
  id->secu = strcat(id->secu, my_space);
  id->secu = strcat(id->secu, year);
  id->secu = strcat(id->secu, id->mon);
  id->secu = strcat(id->secu, my_space);
  id->secu = strcat(id->secu, id->dep);
  id->secu = strcat(id->secu, my_space);
  id->secu = strcat(id->secu, id->inode);
  return (id->secu);
}

char		*get_mon(char *mon)
{
  if (strcmp(mon, "01") == 0)
    mon = strdup("janvier");
  else if (strcmp(mon, "02") == 0)
    mon = strdup("février");
  else if (strcmp(mon, "03") == 0)
    mon = strdup("mars");
  else if (strcmp(mon, "04") == 0)
    mon = strdup("avril");
  else if (strcmp(mon, "05") == 0)
    mon = strdup("mai");
  else if (strcmp(mon, "06") == 0)
    mon = strdup("juin");
  else if (strcmp(mon, "07") == 0)
    mon = strdup("juillet");
  else if (strcmp(mon, "08") == 0)
    mon = strdup("août");
  else if (strcmp(mon, "09") == 0)
    mon = strdup("septembre");
  else if (strcmp(mon, "10") == 0)
    mon = strdup("octobre");
  else if (strcmp(mon, "11") == 0)
    mon = strdup("novembre");
  else if (strcmp(mon, "12") == 0)
    mon = strdup("décembre");
  return (mon);
}

t_individu      *get_info(t_individu *id)
{
  struct stat	sb;
  struct tm	*t;
  int		fd;
  int		ret;

  stat(id->file, &sb);
  t = gmtime(&sb.st_mtime);
  if (sb.st_mode & S_IRGRP)
    id->gender = strdup("1");
  else
    id->gender = strdup("0");
  sprintf(id->dep, "%d", (int)sb.st_size);
  id->dep = get_full(id->dep);
  sprintf(id->inode, "%lu", (long)sb.st_ino);
  id->inode = get_inode(id->inode);
  sprintf(id->day, "%d", t->tm_mday);
  sprintf(id->mon, "%d", t->tm_mon);
  id->mon = get_full(id->mon);
  sprintf(id->year, "%d", t->tm_year + 1900);
  id->secu = get_id_secu(id);
  fd = open(id->file, O_RDONLY);
  ret = read(fd, id->cv, BUFF_MAX);
  id->cv[ret - 1] = '\0';
  id->monletter = get_mon(id->mon);
  return (id);
}
