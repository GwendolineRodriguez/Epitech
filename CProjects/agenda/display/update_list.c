/*
** update_list.c for update_list in /home/gwendoline/rendu/Piscine_Synthese/agenda
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Tue Jun 30 16:51:58 2015 Gwendoline Rodriguez
** Last update Wed Jul  1 19:51:12 2015 Gwendoline Rodriguez
*/

#include "header.h"

t_employee	*add_meetingem(t_meeting *meeting, t_employee *employee)
{
  int		i;
  int		j;

  i = -1;
  j = -1;
  employee->day[employee->i] = my_strdup(meeting->day);
  employee->zipmeet[employee->j] = my_strdup(meeting->zip);
  while (meeting->names[++j])
    {
      if (strcmp(meeting->names[j], employee->names) != 0)
	employee->meeting[employee->y][++i] = my_strdup(meeting->names[j]);
    }
  employee->meeting[employee->y][i + 1] = NULL;
  employee->y++;
  employee->i++;
  employee->j++;
  return (employee);
}

t_employee	*update_listem(t_employee *employee, t_meeting *meeting)
{
  int		i;
  t_employee	*first;

  first = employee;
  while (meeting)
    {
      i = -1;
      while (meeting->ids[++i] != NULL)
	{
	  employee = first;
	  while(employee->id)
	    {
	      if (strcmp(meeting->ids[i], employee->id) == 0)
		employee = add_meetingem(meeting, employee);
	      employee = employee->next;
	    }
	}
      meeting = meeting->next;
    }
  return (first);
}

t_meeting       *update_names(t_meeting *meeting, t_employee *employee, int i)
{
  t_meeting     *first;
  t_employee    *tmp;
  int           j;

  first = meeting;
  tmp = employee;
  while (meeting)
    {
      i = -1;
      j = -1;
      while (meeting->ids[++i] != NULL)
        {
          employee = tmp;
          while (employee->names != NULL)
            {
              if (strcmp(meeting->ids[i], employee->id) == 0)
                meeting->names[++j] = my_strdup(employee->names);
              employee = employee->next;
            }
        }
      meeting = meeting->next;
    }
  return (first);
}
