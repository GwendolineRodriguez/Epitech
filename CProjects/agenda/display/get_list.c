/*
** get_list.c for get_list in /home/gwendoline/rendu/Piscine_Synthese/agenda/display
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Tue Jun 30 13:42:23 2015 Gwendoline Rodriguez
** Last update Wed Jul  1 17:33:08 2015 Gwendoline Rodriguez
*/

#include "header.h"

void            add_employee(t_employee *employee, char **tab)
{
  char		*tmp;

  if (tab[1] != NULL)
    employee->name = tab[1];
  if (tab[2] != NULL)
    employee->forename = tab[2];
  if (tab[3] != NULL)
    employee->job = tab[3];
  if (tab[4] != NULL)
    employee->zip = tab[4];
  if (tab[5] != NULL)
    employee->id = tab[5];
  tmp = my_strdup(employee->forename);
  if (employee->name != NULL && employee->forename != NULL)
    {
      employee->names = strcat(tmp, " ");
      employee->names = strcat(employee->names, employee->name);
    }
}

void            add_meeting(t_meeting *meeting, char **tab)
{
  int           i;
  int           j;

  i = 3;
  j = -1;
  meeting = init_param_meeting(meeting);
  if (tab[1] != NULL)
    meeting->zip = tab[1];
  if (tab[2] != NULL)
    meeting->day = tab[2];
  if (tab[3] != NULL)
    meeting->id = tab[3];
  while (tab[++i] != NULL)
    meeting->ids[++j] = my_strdup(tab[i]);
  meeting->ids[++j] = NULL;
}

t_employee      *get_list_employee(t_employee *employee, int fd)

{
  char          *line;
  char          **tab;
  t_employee    *listem;

  employee = init_param_employee(employee);
  listem = employee;
  while ((line = get_next_line(fd)) && my_strcmp(line, "\n") != 0)
    {
      tab = my_strtowordtab(line);
      if (tab[0] != NULL && my_strcmp(tab[0], "new_employee") == 0)
        {
          add_employee(employee, tab);
          employee->next = create_employee();
          employee = employee->next;
          employee = init_param_employee(employee);
        }
    }
  employee->next = NULL;
  return (listem);
}

t_meeting      *get_list_meeting(t_meeting *meeting, int fd)

{
  char          *line;
  char          **tab;
  t_meeting     *listmeet;

  meeting = init_param_meeting(meeting);
  listmeet = meeting;
  while ((line = get_next_line(fd)) && my_strcmp(line, "\n") != 0)
    {
      tab = my_strtowordtab(line);
      if (tab[0] != NULL && my_strcmp(tab[0], "new_meeting") == 0)
        {
          add_meeting(meeting, tab);
          meeting->next = create_meeting();
          meeting = meeting->next;
          meeting = init_param_meeting(meeting);
        }
    }
  meeting->next = NULL;
  return (listmeet);
}

