/*
** explode.h for  in /home/rouge_b/rendu/PersoProject/my_explode
** 
** Made by Bastien Rougé
** Login   <rouge_b@epitech.net>
** 
** Started on  Mon Apr 27 15:52:50 2015 Bastien Rougé
** Last update Mon Apr 27 17:18:57 2015 Bastien Rougé
*/

#ifndef EXPLODE_H_
#define EXPLODE_H_

typedef struct	my_explode_s
{
  char	*expr;
  char	*str;
  char	**result;
}		my_explode_t;

char	**my_explode(char *expr, char *str);

#endif
