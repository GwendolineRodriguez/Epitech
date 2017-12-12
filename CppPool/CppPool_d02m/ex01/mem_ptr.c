/*
** mem_ptr.c for mem_ptr in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d02m/ex01
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jan  7 09:32:40 2016 Gwendoline Rodriguez
** Last update Thu Jan  7 10:06:04 2016 Gwendoline Rodriguez
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem_ptr.h"

void	add_str(char *str1, char *str2, char **res)
{
  *res = malloc(strlen(str1) + strlen(str2) + 1);
  strcpy(*res, str1);
  strcat(*res, str2);
}

void	add_str_struct(t_str_op *str_op)
{
  add_str(str_op->str1, str_op->str2, &str_op->res);
}

/* int	main(void) */
/* { */
/*   char *str1 = "Salut, "; */
/*   char *str2 = "ca marche !"; */
/*   char *res; */
/*   t_str_op str_op; */


/*   add_str(str1, str2, &res); */

/*   printf("%s\n", res); */

/*   str_op.str1 = str1; */
/*   str_op.str2 = str2; */
/*   add_str_struct(&str_op); */

/*   printf("%s\n", str_op.res); */

/*   return (0); */
/* } */
