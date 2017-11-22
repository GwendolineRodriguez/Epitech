/*
** init_param.c for init_param in /home/gwendoline/rendu/Piscine_Synthese/agenda
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jun 29 16:54:38 2015 Gwendoline Rodriguez
** Last update Wed Jul  1 19:50:50 2015 Gwendoline Rodriguez
*/

#include "header.h"

t_employee	*init_param_employee(t_employee *employee)
{
  int		i;

  i = -1;
  employee->id = NULL;
  employee->name = NULL;
  employee->forename = NULL;
  employee->job = NULL;
  employee->zip = NULL;
  employee->names = NULL;
  employee->day = malloc(sizeof(char*) * 50);
  employee->zipmeet = malloc(sizeof(char*) * 50);;
  employee->y = 0;
  employee->i = 0;
  employee->j = 0;
  employee->meeting = malloc(sizeof(char**) * 50);
  while (++i < 20)
    employee->meeting[i] = malloc(sizeof(char*) * 50);
  employee->meeting[0][0] = NULL;
  return (employee);
}

t_meeting	*init_param_meeting(t_meeting *meeting)
{
  meeting->id = NULL;
  meeting->day = NULL;
  meeting->zip = NULL;
  meeting->names = malloc(sizeof(char*) * 50);
  return (meeting);
}
