/*
** mylist.h for mylist in /home/RODRIG_1/rendu/Piscine_C_J12/include
** 
** Made by rodriguez gwendoline
** Login   <RODRIG_1@epitech.net>
** 
** Started on  Tue Oct 21 10:52:48 2014 rodriguez gwendoline
** Last update Wed Dec  3 13:26:34 2014 gwendoline rodriguez
*/

#ifndef MYLIST_H_
#define MYLIST_H_

typedef struct s_list
{
  void		*data;
  struct s_list *next;
}		t_list;

#endif
