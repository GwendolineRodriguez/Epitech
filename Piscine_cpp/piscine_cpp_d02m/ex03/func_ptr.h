/*
** func_ptr.h for func_ptr in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d02m/ex03
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jan  7 11:29:52 2016 Gwendoline Rodriguez
** Last update Thu Jan  7 14:29:24 2016 Gwendoline Rodriguez
*/

#ifndef FUNC_PTR_
# define FUNC_PTR_

#include "func_ptr_enum.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*t_func)(char *str);

typedef struct	s_action_func {
  t_action action;
  t_func func;
}		t_action_func;

void print_normal(char *str);
void print_reverse(char *str);
void print_upper(char *str);
void print_42(char *str);
void do_action(t_action action, char *str);
char *my_revstr(char *str);
char *my_strupcase(char *str);
int get_array_size(char *str);

#endif
