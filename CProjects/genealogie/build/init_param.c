/*
** init_param.c for init_param in /home/gwendoline/rendu/Piscine_Synthese/agenda
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jun 29 16:54:38 2015 Gwendoline Rodriguez
** Last update Fri Jul  3 14:52:12 2015 Gwendoline Rodriguez
*/

#include "header.h"

t_individu	*init_param()
{
  t_individu	*individu;

  individu = malloc(sizeof(t_individu));
  individu->option = NULL;
  individu->name = NULL;
  individu->file = malloc(sizeof(char) * 100);
  individu->rep = malloc(sizeof(char) * 500);
  individu->inode = malloc(sizeof(char) * 20);
  individu->dep = malloc(sizeof(char) * 10);
  individu->gender = NULL;
  individu->secu = malloc(sizeof(char) * 20);
  individu->family = NULL;
  individu->day = malloc(sizeof(char) * 10);
  individu->mon = malloc(sizeof(char) * 10);
  individu->monletter = NULL;
  individu->year = malloc(sizeof(char) * 10);
  individu->cv = malloc(sizeof(char) * BUFF_MAX);
  return (individu);
}
