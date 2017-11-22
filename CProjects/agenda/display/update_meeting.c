/*
** update_meeting.c for update_meeting in /home/gwendoline/rendu/Piscine_Synthese/agenda
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Wed Jul  1 10:42:55 2015 Gwendoline Rodriguez
** Last update Wed Jul  1 20:04:55 2015 Gwendoline Rodriguez
*/

#include "header.h"

t_meeting	*update_exclude(t_meeting *meeting, char **tab)
{
  int           i;
  int           len;

  i = -1;
  len = len_tab(meeting->ids);
  if (my_strcmp(meeting->id, tab[1]) == 0)
    {
      while (tab[++i])
	{
	  if (is_intab(tab[i], meeting->ids) != 0)
	    meeting->ids[len++] = my_strdup(tab[i]);
	}
      meeting->ids[len + i] = NULL;
    }
  return (meeting);
}

t_meeting       *update_invite(t_meeting *meeting, char **tab)
{
  int		i;
  int		len;

  i = 1;
  len = len_tab(meeting->ids);
  while (tab[++i])
    {
      printf("tab[%d]:%s\n", i, tab[i]);
      if (is_intab(tab[i], meeting->ids) != 0)
	meeting->ids[len++] = my_strdup(tab[i]);
    }
  printf("i = %d, len = %d\n", i, len);
  meeting->ids[len + i] = NULL;
  return (meeting);
}

t_meeting       *update_meeting(t_meeting *meeting, int fd)
{
  char          **tab;
  char		*line;
  t_meeting	*first;

  first = meeting;
  while ((line = get_next_line(fd)))
    {
      tab = my_strtowordtab(line);
      meeting = first;
      while (meeting)
	{
	  if (my_strcmp(tab[0], "invite") == 0)
	    meeting = update_invite(meeting, tab);
	  meeting = meeting->next;
	}
    }
  return (first);
}
