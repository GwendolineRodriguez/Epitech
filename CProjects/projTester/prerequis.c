/*
** prerequis.c for my_ps_synthese in /home/gwendoline/rendu/Piscine_Synthese/projTester
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jun 18 11:17:11 2015 
** Last update Sat Jun 20 17:20:16 2015 
*/

#include "header.h"

void		my_ps_synthese()
{
  pid_t		pid;

  pid = fork();
  if (pid != 0)
    wait(0);
  else
    execl("/usr/bin/ps", "/usr/bin/ps", NULL);
}
