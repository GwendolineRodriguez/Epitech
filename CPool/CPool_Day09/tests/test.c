/*
** test.c for test in /home/RODRIG_1/rendu/Piscine_C_J09/tests
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Mon Nov 17 12:42:18 2014 rodriguez gwendoline
** Last update Mon Nov 17 12:45:12 2014 rodriguez gwendoline
*/

#include "test.h"

int	view_struct(t_person *person)
{
  my_putstr(person->first_name);
  return (0);
}
