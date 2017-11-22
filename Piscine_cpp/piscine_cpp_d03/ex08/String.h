ls
/*
** string.h for string in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d03/ex00
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jan  8 09:00:08 2016 Gwendoline Rodriguez
** Last update Fri Jan  8 22:27:31 2016 Gwendoline Rodriguez
*/

#ifndef HEADER_H_
#define HEADER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct	String
{
  char		*str;

  void (*assign_c)(struct String *this, char const *s);
  void (*assign_s)(struct String *this, struct String const *str);
  void (*append_c)(struct String* this, char const *ap);
  void (*append_s)(struct String *this, struct String const *ap);
  char (*at)(struct String *this, size_t pos);
  void (*clear)(struct String *this);
  int (*size)(struct String *this);
  int (*compare_c)(struct String *this, char const *str);
  int (*compare_s)(struct String *this, const struct String *str);
  size_t (*copy)(struct String *this, char *s, size_t n, size_t pos);
  char const* (*c_str)(struct String * this);
  int (*empty)(struct String* this);
  int (*find_c)(struct String *this, char const *str, size_t pos);
  int (*find_s)(struct String *this, const struct String *str, size_t pos);
  void (*insert_c)(struct String *this, size_t pos, char const *str);
  void (*insert_s)(struct String *this, size_t pos, struct String const *str);
  int (*to_int)(struct String *this);
  /* char **(*split_c)(struct String *this, char separator); */
  /* struct String *(*split_s)(struct String *this, char separator); */
  void (*aff)(struct String *this);
  /* void (*join_c)(struct String *this, char delim, char const **tab); */
  /* void (*join_s)(struct String *this, char delim, struct String *tab); */
  /* struct String *(*substr)(struct String *this, int offset, int length); */

}		String;

void StringInit(String* this, char const *s);
void StringDestroy(String* this);

#endif

