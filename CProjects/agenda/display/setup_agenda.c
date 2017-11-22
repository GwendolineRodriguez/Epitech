/*
** show_agenda.c for show_agenda in /home/gwendoline/rendu/Piscine_Synthese/agenda
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jun 29 17:03:59 2015 Gwendoline Rodriguez
** Last update Wed Jul  1 20:07:39 2015 Gwendoline Rodriguez
*/

#include "header.h"

void		show_agenda(t_employee *employee, t_meeting *meeting)
{
  t_employee	*tmp;
  t_meeting	*tmp2;

  tmp = employee;
  tmp2 = meeting;
  while (tmp)
    {
      printf("id:%s\n", tmp->id);
      printf("name:%s\n", tmp->name);
      printf("forename:%s\n", tmp->forename);
      printf("job:%s\n", tmp->job);
      printf("zip:%s\n", tmp->zip);
      printf("names:%s\n", tmp->names);
      tmp = tmp->next;
    }
  printf("\t\tfin liste employees\n");
  while (tmp2)
    {
      printf("id:%s\n", tmp2->id);
      printf("day:%s\n", tmp2->day);
      printf("zip:%s\n", tmp2->zip);
      tmp2 = tmp2->next;
    }
}

void            setup_agenda(t_employee *employee, t_meeting *meeting, int fd)
{
  char		*line;
  char		**tab;
  t_employee    *listem;
  t_meeting	*listmeet;
  int		check;

  check = 0;
  fd = open("file", O_RDONLY);
  listem = get_list_employee(employee, fd);
  close(fd);
  fd = open("file", O_RDONLY);
  listmeet = get_list_meeting(meeting, fd);
  close(fd);
  listmeet = update_names(meeting, employee, 0);
  fd = open("file", O_RDONLY);
  close(fd);
  listem = update_listem(employee, meeting);
  fd = open("file", O_RDONLY);
  while ((line = get_next_line(fd)) && my_strcmp(line, "\n") != 0)
    {
      tab = my_strtowordtab(line);
      if (my_strcmp(tab[0], "info_meetings") == 0)
	display_meeting(listmeet, 0);
      else if (my_strcmp(tab[0], "info_employees") == 0 && check++ == 0)
	display_employee(listem);
    }
  close(fd);
}
/* listmeet = update_meeting(meeting, fd); */
