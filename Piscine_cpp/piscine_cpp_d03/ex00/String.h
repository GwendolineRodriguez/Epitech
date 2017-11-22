/*
** string.h for string in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d03/ex00
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jan  8 09:00:08 2016 Gwendoline Rodriguez
** Last update Fri Jan  8 12:23:03 2016 Gwendoline Rodriguez
*/

#ifndef HEADER_H_
#define HEADER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


typedef struct	s_String
{
  char		*str;

  //void (*StringInit)(struct String* s);
  //void (*StringDestroy)(struct String *s);

}		String;

void StringInit(String* this, char const *s);
void StringDestroy(String* this);

#endif

