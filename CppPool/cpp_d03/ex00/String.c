/*
** String.c for String in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d03/ex00
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jan  8 09:04:09 2016 Gwendoline Rodriguez
** Last update Fri Jan  8 12:26:13 2016 Gwendoline Rodriguez
*/

#include "String.h"

void StringInit(String* this, char const * s)
{
  if (s)
    this->str = strdup(s);
  else
    this->str = NULL;
}

void StringDestroy(String* this)
{
  if (this->str)
    free(this->str);
  memset(this, 0, sizeof(String));
}

/* int main() */
/* { */
/*   String this; */

/*   StringInit(&this, "bonjour !"); */
/*   printf("%s\n", this.str); */
/*   return (0); */
/* } */
